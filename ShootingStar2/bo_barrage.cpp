#include"common.h"


int GetEmptyBo_BarrageIndex(){
	for(int i=0;i<BO_BARRAGE_MAX;i++){
		if(bo_barrage[i].f==false)return i;
	}
	return -1;
}

void Bo_BarrageSet(StaticBossBarrageData* barrageData){
	int index = GetEmptyBo_BarrageIndex();
	if(index==-1)return;

	bo_barrage[index].f=true;
	bo_barrage[index].c=0;
	bo_barrage[index].large_group_bet_time_c=1;
	bo_barrage[index].large_group_num_c=0;
	bo_barrage[index].small_group_bet_time_c=1;//barrageData->small_group_bet_time;
	bo_barrage[index].small_group_num_c=0;

	bo_barrage[index].pos=barrageData->startPos;
	bo_barrage[index].shot_v=barrageData->shot_v;
	bo_barrage[index].shot_rad=barrageData->shot_trans_rad;
	bo_barrage[index].move_trans_rad=barrageData->move_trans_rad;
	bo_barrage[index].move_v=barrageData->move_v;
	bo_barrage[index].staticData=barrageData;
}


//En_BulletSet()のe_indexには、bo_barrageのindexを入れる
/////////////////////////////////////////////////////////////////////////////////////////////////////
//↓Bo_Barrageの攻撃パターン

////attackNum=0構成その1 //ランダムばらまき
void Bo_BarrageAttackPattern_00(int index){
	int t=bo_barrage[index].c%bo_barrage[index].staticData->whole_time;

	if(bo_barrage[index].large_group_num_c < bo_barrage[index].staticData->large_group_num){
		if(bo_barrage[index].small_group_bet_time_c >= bo_barrage[index].staticData->small_group_bet_time){

			///////////////////////////////////////////////////////////////////////////////////////////////////////
			for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(bo_barrage[index].pos,bo_barrage[index].staticData->shot_v,M_PI*2*GetRand(3600)/3600,
					(Bul_Color)GetRand(6),bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
			}
			///////////////////////////////////////////////////////////////////////////////////////////////////////

			bo_barrage[index].small_group_bet_time_c=1;
			bo_barrage[index].large_group_num_c++;
		}
		else{
			bo_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(t==0){
			bo_barrage[index].large_group_bet_time_c=1;
			bo_barrage[index].large_group_num_c=0;
			bo_barrage[index].small_group_bet_time_c = bo_barrage[index].staticData->small_group_bet_time;
		}
	}
}

////attackNum=0構成その2 //自機狙い型5-way
void Bo_BarrageAttackPattern_01(int index){
	int t=bo_barrage[index].c%bo_barrage[index].staticData->whole_time;
	double rad = atan2(player.pos.y-boss.pos.y,player.pos.x-boss.pos.x);

	if(bo_barrage[index].large_group_num_c < bo_barrage[index].staticData->large_group_num){
		if(bo_barrage[index].small_group_bet_time_c >= bo_barrage[index].staticData->small_group_bet_time){

			///////////////////////////////////////////////////////////////////////////////////////////////////////
			for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(bo_barrage[index].pos,bo_barrage[index].staticData->shot_v,rad+M_PI/2*i/(bo_barrage[index].staticData->small_group_num-1)-M_PI/4,
					bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
			}
			///////////////////////////////////////////////////////////////////////////////////////////////////////

			bo_barrage[index].small_group_bet_time_c=1;
			bo_barrage[index].large_group_num_c++;
		}
		else{
			bo_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(t==0){
			bo_barrage[index].large_group_bet_time_c=1;
			bo_barrage[index].large_group_num_c=0;
			bo_barrage[index].small_group_bet_time_c = bo_barrage[index].staticData->small_group_bet_time;
		}
	}
}


////attackNum=1構成1 //円弾
void Bo_BarrageAttackPattern_02(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		for(int small_g=0;small_g<bo_barrage[index].staticData->small_group_num;small_g++){
			for(int circle=0;circle<(int)bo_barrage[index].staticData->param3;circle++){
				En_BulletSet(GetPosAdd(bo_barrage[index].pos,bo_barrage[index].staticData->param1*cos(M_PI*2*circle/bo_barrage[index].staticData->param3)+ENEMY_WIDTH/2,bo_barrage[index].staticData->param1*sin(M_PI*2*circle/bo_barrage[index].staticData->param3)+ENEMY_HEIGHT/2)
					,bo_barrage[index].staticData->shot_v,bo_barrage[index].shot_rad+M_PI*2*small_g/bo_barrage[index].staticData->small_group_num
					,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->movePattern,index);
			}
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].shot_rad+=bo_barrage[index].staticData->param2;
		bo_barrage[index].small_group_bet_time_c=1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=2構成1 //回転式円弾
void Bo_BarrageAttackPattern_03(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		for(int small_g=0;small_g<bo_barrage[index].staticData->small_group_num;small_g++){
			for(int circle=0;circle<(int)bo_barrage[index].staticData->param3;circle++){
				En_BulletSet(GetPosAdd(bo_barrage[index].pos,bo_barrage[index].staticData->param1*cos(M_PI*2*circle/bo_barrage[index].staticData->param3)+ENEMY_WIDTH/2,bo_barrage[index].staticData->param1*sin(M_PI*2*circle/bo_barrage[index].staticData->param3)+ENEMY_HEIGHT/2)
					,bo_barrage[index].staticData->shot_v,bo_barrage[index].shot_rad+M_PI*2*small_g/bo_barrage[index].staticData->small_group_num
					,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern
					,index,bo_barrage[index].staticData->shot_rot_rad,M_PI*2*circle/bo_barrage[index].staticData->param3);
			}
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].shot_rad+=bo_barrage[index].staticData->param2;
		bo_barrage[index].small_group_bet_time_c=1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=3構成1 //螺旋弾
void Bo_BarrageAttackPattern_04(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			En_BulletSet(GetPosAdd(bo_barrage[index].pos,bo_barrage[index].staticData->param3*cos(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num),bo_barrage[index].staticData->param3*sin(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num))
				,bo_barrage[index].staticData->shot_v,bo_barrage[index].staticData->shot_trans_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num,(Bul_Color)i
				,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=1;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
		bo_barrage[index].staticData->shot_trans_rad+=bo_barrage[index].staticData->param2;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}

////attackNum=3構成2 //円形弾
void Bo_BarrageAttackPattern_05(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad = M_PI*2*GetRand(3600)/3600;
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			En_BulletSet(bo_barrage[index].pos,bo_barrage[index].staticData->shot_v,rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num,bo_barrage[index].staticData->shot_bul_color
				,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index,bo_barrage[index].staticData->param1);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=4構成1
void Bo_BarrageAttackPattern_06(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			En_BulletSet(GetPosAdd(bo_barrage[index].pos,bo_barrage[index].staticData->param2*cos(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num),bo_barrage[index].staticData->param2*sin(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num))
				,bo_barrage[index].staticData->shot_v,bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num,(Bul_Color)(bo_barrage[index].staticData->shot_bul_color+i)
				,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=1;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=5 構成1
void Bo_BarrageAttackPattern_07(int index){
	if(bo_barrage[index].large_group_bet_time_c>=bo_barrage[index].staticData->large_group_bet_time){
		if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
			En_BulletSet(GetPosAdd(bo_barrage[index].staticData->startPos,240.0*bo_barrage[index].staticData->param1*cos(bo_barrage[index].staticData->shot_rot_rad),150.0*(1.0-bo_barrage[index].staticData->param1)*sin(bo_barrage[index].staticData->shot_rot_rad))
				,bo_barrage[index].staticData->shot_v,M_PI*2*GetRand(3600)/3600
				,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
			
			bo_barrage[index].small_group_bet_time_c=0;
		}
		else{
			bo_barrage[index].small_group_bet_time_c++;
			bo_barrage[index].staticData->shot_rot_rad+=M_PI*32/180;
			if(bo_barrage[index].staticData->shot_rot_rad >= M_PI*2){
				bo_barrage[index].staticData->shot_rot_rad -= M_PI*2;
				bo_barrage[index].staticData->param1+=bo_barrage[index].staticData->param2;
				if(bo_barrage[index].staticData->param1>=1.0){
					bo_barrage[index].large_group_bet_time_c=0;
					bo_barrage[index].staticData->param1=0.01;
				}
				if(bo_barrage[index].staticData->param1<=0.0){
					bo_barrage[index].large_group_bet_time_c=0;
					bo_barrage[index].staticData->param1=0.99;
				}
			}
		}
		bo_barrage[index].staticData->param3=0.0;
	}
	else{
		bo_barrage[index].large_group_bet_time_c++;
		bo_barrage[index].small_group_bet_time_c=bo_barrage[index].staticData->small_group_bet_time;
		bo_barrage[index].staticData->param3=1.0;
	}
}


////attackNum=6 構成1
void Bo_BarrageAttackPattern_08(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		Position pos;
		double rad;
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			pos = GetPosAdd(bo_barrage[index].staticData->startPos,220.0*sin(4.0*bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)*cos(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)+ENEMY_WIDTH/2,220.0*sin(4.0*bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)*sin(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)+ENEMY_HEIGHT/2);
			rad = atan2(player.pos.y+PLAYER_HEIGHT/2-pos.y,player.pos.x+PLAYER_WIDTH/2-pos.x);
			En_BulletSet(pos,bo_barrage[index].staticData->shot_v,rad,bo_barrage[index].staticData->shot_bul_color
				,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=1;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}

////attackNum=6 構成2
void Bo_BarrageAttackPattern_09(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		Position pos;
		double rad;
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			pos = GetPosAdd(bo_barrage[index].staticData->startPos,220.0*sin(4.0*bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)*cos(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)+ENEMY_WIDTH/2,150.0*sin(4.0*bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)*sin(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num)+ENEMY_HEIGHT/2);
			rad = M_PI*2*GetRand(3600)/3600;
			En_BulletSet(pos,bo_barrage[index].staticData->shot_v,rad,bo_barrage[index].staticData->shot_bul_color
				,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index,0.0,bo_barrage[index].staticData->param2);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=1;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=7 構成1
void Bo_BarrageAttackPattern_10(int index){
	if(bo_barrage[index].large_group_num_c<bo_barrage[index].staticData->large_group_num){
		if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
			///////////////////////////////////////////////////////////////////////////////////////////////
			double rad;
			for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
				rad = bo_barrage[index].staticData->shot_trans_rad + bo_barrage[index].staticData->param3*i/(bo_barrage[index].staticData->small_group_num-1) - bo_barrage[index].staticData->param3/2 + M_PI/4*sin(bo_barrage[index].staticData->param1);
				En_BulletSet(bo_barrage[index].staticData->startPos,bo_barrage[index].staticData->shot_v,rad,bo_barrage[index].staticData->shot_bul_color
					,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
			}	
			///////////////////////////////////////////////////////////////////////////////////////////////
			bo_barrage[index].small_group_bet_time_c=0;
			bo_barrage[index].large_group_num_c++;

			bo_barrage[index].staticData->param1 += bo_barrage[index].staticData->param2;
		}
		else{
			bo_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(bo_barrage[index].large_group_bet_time_c>=bo_barrage[index].staticData->large_group_bet_time){
			bo_barrage[index].small_group_bet_time_c=bo_barrage[index].staticData->small_group_bet_time;
			bo_barrage[index].large_group_bet_time_c=0;
			bo_barrage[index].large_group_num_c=0;
		}
		else{
			bo_barrage[index].large_group_bet_time_c++;
		}
	}
}


////attackNum=8 構成1
void Bo_BarrageAttackPattern_11(int index){
	if(bo_barrage[index].large_group_num_c<bo_barrage[index].staticData->large_group_num){
		if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
			///////////////////////////////////////////////////////////////////////////////////////////////
			Position pos;
			double rad;
			for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
				pos = GetPosAdd(bo_barrage[index].staticData->startPos,150.0*cos(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num),150.0*sin(bo_barrage[index].staticData->shot_rot_rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num));
				rad = atan2(bo_barrage[index].staticData->startPos.y+PLAYER_HEIGHT/2-pos.y,bo_barrage[index].staticData->startPos.x+PLAYER_WIDTH/2-pos.x);
				En_BulletSet(pos,bo_barrage[index].staticData->shot_v,rad,bo_barrage[index].staticData->shot_bul_color
					,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index,0.0,bo_barrage[index].staticData->param1);
			}	
			///////////////////////////////////////////////////////////////////////////////////////////////
			bo_barrage[index].small_group_bet_time_c=0;
			bo_barrage[index].large_group_num_c++;
			bo_barrage[index].staticData->shot_rot_rad += bo_barrage[index].staticData->param2;
		}
		else{
			bo_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(bo_barrage[index].large_group_bet_time_c>=bo_barrage[index].staticData->large_group_bet_time){
			bo_barrage[index].small_group_bet_time_c=bo_barrage[index].staticData->small_group_bet_time;
			bo_barrage[index].large_group_bet_time_c=0;
			bo_barrage[index].large_group_num_c=0;
			bo_barrage[index].staticData->shot_rot_rad = M_PI*2*GetRand(3600)/3600;
			bo_barrage[index].staticData->startPos=player.pos;
		}
		else{
			bo_barrage[index].large_group_bet_time_c++;
		}
	}
}


////attackNum=9 構成1
void Bo_BarrageAttackPattern_12(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		Position pos1=GetPositionFromXY(0.0,0.0),pos2=GetPositionFromXY(0.0,0.0);
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			En_LazerSet(bo_barrage[index].staticData->startPos,pos1,pos2,bo_barrage[index].staticData->shot_v,bo_barrage[index].staticData->shot_rot_rad + M_PI*2*i/bo_barrage[index].staticData->small_group_num
				,bo_barrage[index].staticData->shotMovePattern,index,bo_barrage[index].staticData->shot_bul_color);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=1;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}

}

////attackNum=9 構成2
void Bo_BarrageAttackPattern_13(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad = atan2(player.pos.y-boss.pos.y,player.pos.x-boss.pos.x);
		En_BulletSet(GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2),bo_barrage[index].staticData->shot_v,rad
			,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=10 構成1
void Bo_BarrageAttackPattern_14(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad = bo_barrage[index].staticData->param2*sin(bo_barrage[index].staticData->shot_rot_rad);
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			En_BulletSet(GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2),bo_barrage[index].staticData->shot_v,rad+M_PI*2*i/bo_barrage[index].staticData->small_group_num
				,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=11 構成1
void Bo_BarrageAttackPattern_15(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		Position pos;
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			pos=GetPosAdd(boss.pos,120.0*cos(bo_barrage[index].staticData->shot_rot_rad)+(double)ENEMY_WIDTH/2,120.0*sin(bo_barrage[index].staticData->shot_rot_rad)+(double)ENEMY_HEIGHT/2);

			En_BulletSet(pos,bo_barrage[index].staticData->shot_v,M_PI*2*i/bo_barrage[index].staticData->small_group_num
				,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=12 構成1
void Bo_BarrageAttackPattern_16(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad; 
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			rad = bo_barrage[index].staticData->shot_trans_rad +bo_barrage[index].staticData->param2*sin(bo_barrage[index].staticData->shot_rot_rad) + M_PI*i/(bo_barrage[index].staticData->small_group_num-1) -M_PI/2;
			En_BulletSet(GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2),bo_barrage[index].staticData->shot_v,rad
				,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index
				,bo_barrage[index].staticData->shot_v*cos(rad),bo_barrage[index].staticData->shot_v*sin(rad));
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
		bo_barrage[index].staticData->shot_rot_rad+=bo_barrage[index].staticData->param1;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=13 構成1
void Bo_BarrageAttackPattern_17(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad; 
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			rad = M_PI*3/2 + M_PI*(GetRand(60)-30)/180;
			En_BulletSet(GetPositionFromXY((double)GetRand(FIELD_SIZE_WIDTH),585.0),bo_barrage[index].staticData->shot_v,rad
				,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index
				,M_PI*GetRand(180)/180);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
		bo_barrage[index].staticData->param1+=M_PI*5/180;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=14 構成1
void Bo_BarrageAttackPattern_18(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad; 
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			rad = M_PI*3/2 + M_PI*(GetRand(30)-15)/180;
			En_BulletSet(GetPosAdd(bo_barrage[index].staticData->startPos,4.5*i,(double)(GetRand(10)-5))
				,bo_barrage[index].staticData->shot_v,bo_barrage[index].staticData->shot_trans_rad
				,(Bul_Color)GetRand(7),bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}

////attackNum=14 構成2
void Bo_BarrageAttackPattern_19(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad = atan2(player.pos.y-boss.pos.y,player.pos.x-boss.pos.x);
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			En_BulletSet(GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2),bo_barrage[index].staticData->shot_v
				,rad+bo_barrage[index].staticData->param1*i/(bo_barrage[index].staticData->small_group_num-1)-bo_barrage[index].staticData->param1/2
				,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=15 構成1
void Bo_BarrageAttackPattern_20(int index){
	int t = bo_barrage[index].c%bo_barrage[index].staticData->whole_time;
	if(t%2!=0)return;

	if(t==0){
		bo_barrage[index].staticData->shot_trans_rad = M_PI*GetRand(1800)/1800;
	}
	else if(t<=200){
		Position pos = GetPosAdd(bo_barrage[index].staticData->startPos,0.0,bo_barrage[index].staticData->move_v*t);
		En_BulletSet(pos,bo_barrage[index].staticData->shot_v,bo_barrage[index].staticData->shot_trans_rad,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind
			,bo_barrage[index].staticData->shotMovePattern,index);

		bo_barrage[index].staticData->shot_trans_rad+=bo_barrage[index].staticData->param1;
	}
}


////attackNum=10 構成2
void Bo_BarrageAttackPattern_21(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		//////////////////////////////////////////////////////////////////////////
		Position pos=GetPositionFromXY(1.0*GetRand(480)+16,-20.0);
		double rad = bo_barrage[index].staticData->shot_trans_rad + M_PI*(GetRand(30)-15)/180;

		En_BulletSet(pos,bo_barrage[index].staticData->shot_v,rad
			,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		//////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}


////attackNum=12 構成2
void Bo_BarrageAttackPattern_22(int index){
	if(bo_barrage[index].small_group_bet_time_c>=bo_barrage[index].staticData->small_group_bet_time){
		////////////////////////////////////////////////////////////////////////////////////
		double rad;
		for(int i=0;i<bo_barrage[index].staticData->small_group_num;i++){
			rad = bo_barrage[index].staticData->shot_trans_rad + M_PI*(GetRand(150)-75)/180;
			En_BulletSet(GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2),bo_barrage[index].staticData->shot_v
				,rad+bo_barrage[index].staticData->param1*i/(bo_barrage[index].staticData->small_group_num-1)-bo_barrage[index].staticData->param1/2
				,bo_barrage[index].staticData->shot_bul_color,bo_barrage[index].staticData->shot_kind,bo_barrage[index].staticData->shotMovePattern,index);
		}
		////////////////////////////////////////////////////////////////////////////////////
		bo_barrage[index].small_group_bet_time_c=0;
	}
	else{
		bo_barrage[index].small_group_bet_time_c++;
	}
}



void(*Bo_BarrageAttackPattern[])(int index)={
	Bo_BarrageAttackPattern_00,
	Bo_BarrageAttackPattern_01,
	Bo_BarrageAttackPattern_02,
	Bo_BarrageAttackPattern_03,
	Bo_BarrageAttackPattern_04,
	Bo_BarrageAttackPattern_05,
	Bo_BarrageAttackPattern_06,
	Bo_BarrageAttackPattern_07,
	Bo_BarrageAttackPattern_08,
	Bo_BarrageAttackPattern_09,
	Bo_BarrageAttackPattern_10,
	Bo_BarrageAttackPattern_11,
	Bo_BarrageAttackPattern_12,
	Bo_BarrageAttackPattern_13,
	Bo_BarrageAttackPattern_14,
	Bo_BarrageAttackPattern_15,
	Bo_BarrageAttackPattern_16,
	Bo_BarrageAttackPattern_17,
	Bo_BarrageAttackPattern_18,
	Bo_BarrageAttackPattern_19,
	Bo_BarrageAttackPattern_20,
	Bo_BarrageAttackPattern_21,
	Bo_BarrageAttackPattern_22
};
/////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////
//↓Bo_Barrageの移動パターン

//敵機座標と同じ
void Bo_BarrageMovePattern_00(int index){
	bo_barrage[index].pos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
}

void(*Bo_BarrageMovePattern[])(int)={
	Bo_BarrageMovePattern_00
};
//////////////////////////////////////////////////////////////////////////////////////////////////////


void Bo_BarrageUpdate(){
	if(boss.f==false)return;
	if(boss.status!=b_normal)return;

	for(int i=0;i<BO_BARRAGE_MAX;i++){
		if(bo_barrage[i].f==false)continue;

		bo_barrage[i].c++;

		Bo_BarrageMovePattern[bo_barrage[i].staticData->movePattern](i);
		Bo_BarrageAttackPattern[bo_barrage[i].staticData->attackPattern](i);
	}
}