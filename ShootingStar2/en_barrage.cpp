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



//Ž©‹@‘_‚¢(pram1‚Å‰Á‘¬“x)
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

//n-wayŽ©‹@‘_‚¢ (param1‚Å’e‚ÌL‚ª‚èŠp“x‚ðŽw’è,param2‚Å‰Á‘¬“x‚à‚µ‚­‚ÍƒJƒEƒ“ƒ^)
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

//‰~Œ`’eŽ©‹@‘_‚¢(param1‚Å‰Á‘¬“x param2‚ÅƒJƒEƒ“ƒ^)
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

//‰~Œ`’eŒÅ’è(param1‚Å‰Á‘¬“x param2‚ÅƒJƒEƒ“ƒ^)
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

//Šp“x‹L‰¯Ž©‹@‘_‚¢(param1‚Å‰Á‘¬“x)
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

//Šp“x‹L‰¯n-way(param1‚ÅL‚ª‚èŠp“x,param2‚Å‰Á‘¬“x)
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

//Šp“x‹L‰¯‰~Œ`(param1‚Å‰Á‘¬“x)
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

//ŒÅ’èŽ©‹@‘_‚¢(param1‚Å‰Á‘¬“x)
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

//ŒÅ’èn-way(param1‚ÅL‚ª‚èŠp“x,param2‚Å‰Á‘¬“x)
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

//‘S‘Ì‚Î‚ç‚Ü‚«(param1‚Å‰Á‘¬“xparam2‚ÅƒJƒEƒ“ƒ^)
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

//ŒÅ’èŽw’èŠp“x’†SAŽw’è”ÍˆÍ‚Î‚ç‚Ü‚«(param1‚ðŠp“x”ÍˆÍ,param2‚Å‰Á‘¬“x)
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

//—†ù’e(param1‚ª‰ñ“]Šp‘¬“x param2‚ÅƒJƒEƒ“ƒ^)
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

//’e¶¬‰ÁŒ¸‘¬Œ^Ž©‹@‘_‚¢(param1‚Å’e¶¬‚Ì‰Á‘¬“x) ’e‚Ì‰Á‘¬“x‚Í•Ï‰»‚µ‚È‚¢
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

//’e¶¬‰ÁŒ¸‘¬Œ^n-wayŽ©‹@‘_‚¢ (param1‚Å’e‚ÌL‚ª‚èŠp“x‚ðŽw’è,param2‚Å’e¶¬‰Á‘¬“x)
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

//’e¶¬‰ÁŒ¸‘¬Œ^—†ù’e(param1‚ª‰ñ“]Šp‘¬“x,param2‚ª’e¶¬‰Á‘¬“x)
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

//Ž©‹@‘_‚¢’¼iƒŒ[ƒU[(’P”­)
void En_BarragePattern_15(int index){
	if(en_barrage[index].total_group_num_c>=1)return;

	double rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[en_barrage[index].e_index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[en_barrage[index].e_index].pos.x-ENEMY_WIDTH/2);
	Position pos;
	pos = GetPositionFromXY(0.0,0.0);
	En_LazerSet(GetPositionFromXY(enemy[en_barrage[index].e_index].pos.x+ENEMY_WIDTH/2,enemy[en_barrage[index].e_index].pos.y+ENEMY_HEIGHT/2),pos,GetPositionFromXY(player.pos.x+PLAYER_WIDTH/2,player.pos.y+PLAYER_HEIGHT/2),
				en_barrage[index].staticData->shot_v,rad,0,index,en_barrage[index].staticData->shot_bul_color);

	en_barrage[index].total_group_num_c++;
}

//‰~Œ`Œ^’¼iƒŒ[ƒU[(Ž©‹@‘_‚¢)
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

//ªŽå‚ÉŽG‹›—p
///////////////////////////////////////////////////////////////////////////////////////

//’e¶¬‰ÁŒ¸‘¬Œ^n-way—†ù’e60‹ŒÅ’è(param1‚ª‰ñ“]Šp‘¬“x,param2‚ª’e¶¬‰Á‘¬“x)
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

//Šp“x”ÍˆÍAs_group_num‘‰ÁŒ^(shot_v‚É0‚ðŽw’è param1‚É‘‰ÁŠp“x•ª‚ð“ü‚ê‚é)
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