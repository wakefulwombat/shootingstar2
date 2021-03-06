#include"common.h"


int GetEmptyBarrageIndex(){
	for(int i=0;i<EN_BARRAGE_MAX;i++){
		if(en_barrage[i].f==false)return i;
	}
	return -1;
}

void En_BarrageSet(StaticEnemyShotData *enemyShotData,int e_index){
	int index = GetEmptyBarrageIndex();
	if(index==-1)return;

	en_barrage[index].f=true;
	en_barrage[index].c=0;
	en_barrage[index].e_index=e_index;
	en_barrage[index].shot_v=enemyShotData->shot_v;
	en_barrage[index].shot_rad=atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
	en_barrage[index].staticData=enemyShotData;
	en_barrage[index].large_group_bet_time_c=0;
	en_barrage[index].large_group_num_c=0;
	en_barrage[index].small_group_bet_time_c=0;
	en_barrage[index].small_group_num_c=0;
	en_barrage[index].total_group_num_c=0;
}



//自機狙い(pram1で加速度)
void En_BarragePattern_00(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);

			En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->param1,en_barrage[index].staticData->param2);
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//n-way自機狙い (param1で弾の広がり角度を指定,param2で加速度もしくはカウンタ)
void En_BarragePattern_01(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad+en_barrage[index].staticData->param1*M_PI*2/360*i/(en_barrage[index].staticData->small_group_num-1)-en_barrage[index].staticData->param1*M_PI/360,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//円形弾自機狙い(param1で加速度 param2でカウンタ)
void En_BarragePattern_02(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad+M_PI*2*i/en_barrage[index].staticData->small_group_num,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->param1,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//円形弾固定(param1で加速度 param2でカウンタ)
void En_BarragePattern_03(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = en_barrage[index].staticData->shot_rad;
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad+M_PI*2*i/en_barrage[index].staticData->small_group_num,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->param1,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//角度記憶自機狙い(param1で加速度)
void En_BarragePattern_04(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);

			En_BulletSet(pos,en_barrage[index].staticData->shot_v,en_barrage[index].shot_rad,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,index,en_barrage[index].staticData->param1);
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//角度記憶n-way(param1で広がり角度,param2で加速度)
void En_BarragePattern_05(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,en_barrage[index].shot_rad+en_barrage[index].staticData->param1*M_PI*2/360*i/(en_barrage[index].staticData->small_group_num-1)-en_barrage[index].staticData->param1*M_PI/360,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,index,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//角度記憶円形(param1で加速度)
void En_BarragePattern_06(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,en_barrage[index].shot_rad+M_PI*2*i/en_barrage[index].staticData->small_group_num,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,index,en_barrage[index].staticData->param1);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_rad=atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//固定自機狙い(param1で加速度)
void En_BarragePattern_07(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);

			En_BulletSet(pos,en_barrage[index].staticData->shot_v,en_barrage[index].staticData->shot_rad,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,index,en_barrage[index].staticData->param1);
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//固定n-way(param1で広がり角度,param2で加速度)
void En_BarragePattern_08(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,en_barrage[index].staticData->shot_rad+en_barrage[index].staticData->param1*M_PI*2/360*i/(en_barrage[index].staticData->small_group_num-1)-en_barrage[index].staticData->param1*M_PI/360,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,index,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//全体ばらまき(param1で加速度param2でカウンタ)
void En_BarragePattern_09(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				double rad = (double)GetRand(31416*2)/10000;
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad+M_PI*2*i/en_barrage[index].staticData->small_group_num,
							en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,
							en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->param1,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//固定指定角度中心、指定範囲ばらまき(param1を角度範囲,param2で加速度)
void En_BarragePattern_10(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				double rad = en_barrage[index].staticData->shot_rad + (double)GetRand((int)en_barrage[index].staticData->param1*100)/100*M_PI*2/360 - en_barrage[index].staticData->param1*M_PI/360;
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,index,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//螺旋弾(param1が回転角速度 param2でカウンタ)
void En_BarragePattern_11(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,en_barrage[index].shot_rad+M_PI*2*i/en_barrage[index].staticData->small_group_num,
							en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,
							index,en_barrage[index].staticData->param1,en_barrage[index].staticData->param2);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
			en_barrage[index].shot_rad+=en_barrage[index].staticData->param1*M_PI*2/360;;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_rad=atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//弾生成加減速型自機狙い(param1で弾生成の加速度) 弾の加速度は変化しない
void En_BarragePattern_12(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);

			En_BulletSet(pos,en_barrage[index].shot_v,rad,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,0,index);
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
			en_barrage[index].shot_v+=en_barrage[index].staticData->param1;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_v=en_barrage[index].staticData->shot_v;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//弾生成加減速型n-way自機狙い (param1で弾の広がり角度を指定,param2で弾生成加速度)
void En_BarragePattern_13(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].shot_v,rad+en_barrage[index].staticData->param1*M_PI*2/360*i/(en_barrage[index].staticData->small_group_num-1)-en_barrage[index].staticData->param1*M_PI/360,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,0,index);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
			en_barrage[index].shot_v+=en_barrage[index].staticData->param2;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_v=en_barrage[index].staticData->shot_v;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//弾生成加減速型螺旋弾(param1が回転角速度,param2が弾生成加速度)
void En_BarragePattern_14(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].shot_v,en_barrage[index].shot_rad+M_PI*2*i/en_barrage[index].staticData->small_group_num,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,0,index);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
			en_barrage[index].shot_rad+=en_barrage[index].staticData->param1*M_PI*2/360;
			en_barrage[index].shot_v+=en_barrage[index].staticData->param2;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_rad=atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			en_barrage[index].shot_v=en_barrage[index].staticData->shot_v;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//自機狙い直進レーザー(単発)
void En_BarragePattern_15(int index){
	if(en_barrage[index].total_group_num_c>=1)return;

	double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
	Position pos;
	pos = GetPositionFromXY(0.0,0.0);
	En_LazerSet(GetPositionFromXY(enemy[en_barrage[index].e_index].pos.x+ENEMY_WIDTH/2,enemy[en_barrage[index].e_index].pos.y+ENEMY_HEIGHT/2),pos,GetPositionFromXY(player.pos.x+PLAYER_WIDTH/2,player.pos.y+PLAYER_HEIGHT/2),
				en_barrage[index].staticData->shot_v,rad,0,index,en_barrage[index].staticData->shot_bul_color);

	en_barrage[index].total_group_num_c++;
}

//円形型直進レーザー(自機狙い)
void En_BarragePattern_16(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			Position start,control,end;
			start = GetPositionFromXY(enemy[index].pos.x+ENEMY_WIDTH/2,enemy[index].pos.y+ENEMY_HEIGHT/2);
			control = GetPositionFromXY(0.0,0.0);
			end = GetPositionFromXY(player.pos.x+PLAYER_WIDTH/2,player.pos.y+PLAYER_HEIGHT/2);

			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_LazerSet(start,control,end,en_barrage[index].shot_v,rad+M_PI*2*i/en_barrage[index].staticData->small_group_num,en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->shot_bul_color);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//↑主に雑魚用
///////////////////////////////////////////////////////////////////////////////////////

//弾生成加減速型n-way螺旋弾60°固定(param1が回転角速度,param2が弾生成加速度)
void En_BarragePattern_17(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
				En_BulletSet(pos,en_barrage[index].shot_v,en_barrage[index].shot_rad+M_PI/3*i/(en_barrage[index].staticData->small_group_num-1)-M_PI/6,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,0,index);
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
			en_barrage[index].shot_rad+=en_barrage[index].staticData->param1*M_PI*2/360;
			en_barrage[index].shot_v+=en_barrage[index].staticData->param2;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].shot_rad=atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			en_barrage[index].shot_v=en_barrage[index].staticData->shot_v;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}

//角度範囲、s_group_num増加型(shot_vに0を指定 param1に増加角度分を入れる)
void En_BarragePattern_18(int index){
	if(en_barrage[index].total_group_num_c >= en_barrage[index].staticData->total_group_num) return;

	if(en_barrage[index].large_group_num_c < en_barrage[index].staticData->large_group_num){
		if(en_barrage[index].small_group_bet_time_c > en_barrage[index].staticData->small_group_bet_time){
			////////////////////////////////////////////
			double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
			Position pos = GetPosAdd(enemy[en_barrage[index].e_index].pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
			
			if(en_barrage[index].staticData->small_group_num==1){
				En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->param1,en_barrage[index].staticData->param2);
			}
			else{
				for(int i=0;i<en_barrage[index].staticData->small_group_num;i++){
					En_BulletSet(pos,en_barrage[index].staticData->shot_v,rad+en_barrage[index].shot_rad*M_PI*2/360*i/(en_barrage[index].staticData->small_group_num-1)-en_barrage[index].shot_rad*M_PI/360,en_barrage[index].staticData->shot_bul_color,en_barrage[index].staticData->shot_kind,en_barrage[index].staticData->shotMovePattern,index,en_barrage[index].staticData->param2);
				}
			}
			////////////////////////////////////////////
			en_barrage[index].small_group_bet_time_c=0;
			en_barrage[index].large_group_num_c++;
			en_barrage[index].staticData->small_group_num++;
			en_barrage[index].shot_rad+=en_barrage[index].staticData->param1;
		}
		else{
			en_barrage[index].small_group_bet_time_c++;
		}
	}
	else{
		if(en_barrage[index].large_group_bet_time_c > en_barrage[index].staticData->large_group_bet_time){
			en_barrage[index].large_group_bet_time_c=0;
			en_barrage[index].total_group_num_c++;
			en_barrage[index].large_group_num_c=0;
			en_barrage[index].staticData->small_group_num-=(en_barrage[index].staticData->large_group_num-1);
			en_barrage[index].shot_rad=0.0;
		}
		else{
			en_barrage[index].large_group_bet_time_c++;
		}
	}
}



void (*En_BarragePattern[])(int)={
	En_BarragePattern_00,
	En_BarragePattern_01,
	En_BarragePattern_02,
	En_BarragePattern_03,
	En_BarragePattern_04,
	En_BarragePattern_05,
	En_BarragePattern_06,
	En_BarragePattern_07,
	En_BarragePattern_08,
	En_BarragePattern_09,
	En_BarragePattern_10,
	En_BarragePattern_11,
	En_BarragePattern_12,
	En_BarragePattern_13,
	En_BarragePattern_14,
	En_BarragePattern_15,
	En_BarragePattern_16,
	En_BarragePattern_17,
	En_BarragePattern_18
};

void En_BarrageUpdate(){
	for(int i=0;i<EN_BARRAGE_MAX;i++){
		if(en_barrage[i].f==false)continue;

		En_BarragePattern[en_barrage[i].staticData->attackPattern](i);
		en_barrage[i].f = enemy[en_barrage[i].e_index].f;

		en_barrage[i].c++;
	}
}


void En_BarrageInit(){
	for(int i=0;i<EN_BARRAGE_MAX;i++){
		en_barrage[i].f=false;
	}
}