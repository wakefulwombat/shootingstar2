#include"common.h"

bool HitCheckPlayerAndEnemy(int e_index){
	if(player.status!=normal)return false;
	if(enemy[e_index].status!=normal)return false;

	if((player.pos.x+PLAYER_WIDTH/2<enemy[e_index].pos.x+ENEMY_WIDTH+5)&&(player.pos.x+PLAYER_WIDTH/2>enemy[e_index].pos.x-5)
		&&(player.pos.y+PLAYER_HEIGHT/2<enemy[e_index].pos.y+ENEMY_HEIGHT+5)&&(player.pos.y+PLAYER_HEIGHT/2>enemy[e_index].pos.y-5)){
			return true;
	}
	return false;
}

bool HitCheckPlayerAndEn_Bullet(int eb_index){
	if(player.status!=normal)return false;

	double d = (player.pos.x+PLAYER_WIDTH/2-en_bullet[eb_index].pos.x)*(player.pos.x+PLAYER_WIDTH/2-en_bullet[eb_index].pos.x) + (player.pos.y+PLAYER_HEIGHT/2-en_bullet[eb_index].pos.y)*(player.pos.y+PLAYER_HEIGHT/2-en_bullet[eb_index].pos.y);
	if(d<0.4*(gameData.eb_size[en_bullet[eb_index].kind].width/2)*(gameData.eb_size[en_bullet[eb_index].kind].width/2)){
		return true;
	}
	return false;
}

bool HitCheckPlayerAndEn_Lazer(int el_index){
	if(player.status!=normal)return false;

	double d;
	for(int i=0;i<EN_LAZER_DIV_MAX;i++){
		if(en_lazer[el_index].lazerDiv[i].f==false)continue;

		d = (player.pos.x+PLAYER_WIDTH/2-en_lazer[el_index].lazerDiv[i].center.x)*(player.pos.x+PLAYER_WIDTH/2-en_lazer[el_index].lazerDiv[i].center.x) + (player.pos.y+PLAYER_HEIGHT/2-en_lazer[el_index].lazerDiv[i].center.y)*(player.pos.y+PLAYER_HEIGHT/2-en_lazer[el_index].lazerDiv[i].center.y);
		if(d<0.8*(gameData.eb_size[eb_lazer].width/2)*(gameData.eb_size[eb_lazer].width/2)){
			return true;
		}
	}

	return false;
}

bool HitCheckPl_BulletAndEnemy(int pb_index,int e_index){
	if(enemy[e_index].status!=normal)return false;

	if((pl_bullet[pb_index].pos.x<enemy[e_index].pos.x+ENEMY_WIDTH)&&(pl_bullet[pb_index].pos.x+gameData.eb_size[eb_fuda].width>enemy[e_index].pos.x)
		&&(pl_bullet[pb_index].pos.y<enemy[e_index].pos.y+ENEMY_HEIGHT)&&(pl_bullet[pb_index].pos.y+gameData.eb_size[eb_fuda].height>enemy[e_index].pos.y)){
			return true;
	}
	if((pl_bullet[pb_index].pos.x<enemy[e_index].pos.x+ENEMY_WIDTH)&&(pl_bullet[pb_index].pos.x+gameData.eb_size[eb_fuda].width>enemy[e_index].pos.x)
		&&(pl_bullet[pb_index].pos.y+pl_bullet[pb_index].v/2<enemy[e_index].pos.y+ENEMY_HEIGHT)&&(pl_bullet[pb_index].pos.y+pl_bullet[pb_index].v/2+gameData.eb_size[eb_fuda].height>enemy[e_index].pos.y)){
			return true;
	}
	return false;
}

bool HitCheckPl_BombAndEnemy(int e_index){
	if(pl_bomb.f==false)return false;

	double d = (enemy[e_index].pos.x+ENEMY_WIDTH/2-pl_bomb.pos.x)*(enemy[e_index].pos.x+ENEMY_WIDTH/2-pl_bomb.pos.x) + (enemy[e_index].pos.y+ENEMY_HEIGHT/2-pl_bomb.pos.y)*(enemy[e_index].pos.y+ENEMY_HEIGHT/2-pl_bomb.pos.y);

	if(d<10000)return true;
	return false;
}

bool HitCheckPl_BombAndEn_Bullet(int eb_index){
	if(pl_bomb.f==false)return false;

	double d = ((en_bullet[eb_index].pos.x-pl_bomb.pos.x)*(en_bullet[eb_index].pos.x-pl_bomb.pos.x)+(en_bullet[eb_index].pos.y-pl_bomb.pos.y)*(en_bullet[eb_index].pos.y-pl_bomb.pos.y));

	if(d<10000)return true;
	return false;
}

void HitCheckPlayerAndItem(int i_index){
	if(item[i_index].size==item_small){
		if((player.pos.x<item[i_index].pos.x+ITEM_S_WIDTH/2)&&(player.pos.x+PLAYER_WIDTH>item[i_index].pos.x-ITEM_S_WIDTH/2)&&
			(player.pos.y<item[i_index].pos.y+ITEM_S_HEIGHT/2)&&(player.pos.y+PLAYER_HEIGHT>item[i_index].pos.y-ITEM_S_HEIGHT/2)){
				if(item[i_index].kind==item_power){
					PlayerPowerChanged(0.02,true);
				}
				else if(item[i_index].kind==item_bomb){
					PlayerBombChanged(0.03,true);
				}
				else if(item[i_index].kind==item_score){
					gameData.stageData.scoreHold+=200;
				}
				else{
					player.life++;
				}
				item[i_index].f=false;
		}
	}
	else{
		if((player.pos.x<item[i_index].pos.x+ITEM_L_WIDTH/2)&&(player.pos.x+PLAYER_WIDTH>item[i_index].pos.x-ITEM_L_WIDTH/2)&&
			(player.pos.y<item[i_index].pos.y+ITEM_L_HEIGHT/2)&&(player.pos.y+PLAYER_HEIGHT>item[i_index].pos.y-ITEM_L_HEIGHT/2)){

				if(item[i_index].kind==item_power){
					PlayerPowerChanged(0.05,true);
				}
				else if(item[i_index].kind==item_bomb){
					PlayerBombChanged(0.10,true);
				}
				else if(item[i_index].kind==item_score){
					gameData.stageData.scoreHold+=1000;
				}
				else{
					player.life++;
				}
				item[i_index].f=false;
		}
	}
}

bool HitCheckPlayerAndBoss(){
	if(player.status!=normal)return false;
	if(boss.f==false)return false;
	if(boss.status!=b_normal)return false;

	if((player.pos.x+PLAYER_WIDTH/2<boss.pos.x+ENEMY_WIDTH+5)&&(player.pos.x+PLAYER_WIDTH/2>boss.pos.x-5)
		&&(player.pos.y+PLAYER_HEIGHT/2<boss.pos.y+ENEMY_HEIGHT+5)&&(player.pos.y+PLAYER_HEIGHT/2>boss.pos.y-5)){
			return true;
	}
	return false;
}

bool HitCheckPl_BulletAndBoss(int pb_index){
	if(boss.f==false)return false;
	if(boss.status!=b_normal)return false;

	if((pl_bullet[pb_index].pos.x<boss.pos.x+ENEMY_WIDTH)&&(pl_bullet[pb_index].pos.x+gameData.eb_size[eb_fuda].width>boss.pos.x)
		&&(pl_bullet[pb_index].pos.y<boss.pos.y+ENEMY_HEIGHT)&&(pl_bullet[pb_index].pos.y+gameData.eb_size[eb_fuda].height>boss.pos.y)){
			return true;
	}
	if((pl_bullet[pb_index].pos.x<boss.pos.x+ENEMY_WIDTH)&&(pl_bullet[pb_index].pos.x+gameData.eb_size[eb_fuda].width>boss.pos.x)
		&&(pl_bullet[pb_index].pos.y+pl_bullet[pb_index].v/2<boss.pos.y+ENEMY_HEIGHT)&&(pl_bullet[pb_index].pos.y+pl_bullet[pb_index].v/2+gameData.eb_size[eb_fuda].height>boss.pos.y)){
			return true;
	}
	return false;
}

bool HitCheckPl_BombAndBoss(){
	if(boss.f==false)return false;
	if(pl_bomb.f==false)return false;

	double d = (boss.pos.x+ENEMY_WIDTH/2-pl_bomb.pos.x)*(boss.pos.x+ENEMY_WIDTH/2-pl_bomb.pos.x) + (boss.pos.y+ENEMY_HEIGHT/2-pl_bomb.pos.y)*(boss.pos.y+ENEMY_HEIGHT/2-pl_bomb.pos.y);

	if(d<10000)return true;
	return false;

}


void HitCHeckAllAndUpdate(){
	for(int e_index=0;e_index<ENEMY_MAX;e_index++){
		if(enemy[e_index].f==false)continue;

		if(HitCheckPlayerAndEnemy(e_index)==true){
			PlayerPowerChanged(3.00,false);
			if(player.bomb<3.00)PlayerBombChanged(3.00,false);
			PlayerHited();
		}
		if(HitCheckPl_BombAndEnemy(e_index)==true){
			enemy[e_index].HP-=player.bomb_power;
		}
		for(int pb_index=0;pb_index<PL_BULLET_MAX;pb_index++){
			if(pl_bullet[pb_index].f==false)continue;

			if(HitCheckPl_BulletAndEnemy(pb_index,e_index)==true){
				enemy[e_index].HP-=pl_bullet[pb_index].power;
				pl_bullet[pb_index].f=false;
			}
		}
	}

	for(int eb_index=0;eb_index<EN_BULLET_MAX;eb_index++){
		if(en_bullet[eb_index].f==false) continue;

		if(HitCheckPlayerAndEn_Bullet(eb_index)==true){
			PlayerPowerChanged(3.00,false);
			if(player.bomb<3.00)PlayerBombChanged(3.00,false);
			PlayerHited();
		}
		if(HitCheckPl_BombAndEn_Bullet(eb_index)==true){
			en_bullet[eb_index].f=false;
		}
	}

	for(int el_index=0;el_index<EN_LAZER_MAX;el_index++){
		if(en_lazer[el_index].f==false)continue;

		if(HitCheckPlayerAndEn_Lazer(el_index)==true){
			PlayerPowerChanged(3.00,false);
			if(player.bomb<3.00)PlayerBombChanged(3.00,false);
			PlayerHited();
		}
	}

	if(HitCheckPlayerAndBoss()==true){
		PlayerPowerChanged(3.00,false);
		if(player.bomb<3.00)PlayerBombChanged(3.00,false);
		PlayerHited();
	}
	for(int pb_index=0;pb_index<PL_BULLET_MAX;pb_index++){
		if(pl_bullet[pb_index].f==false)continue;

		if(HitCheckPl_BulletAndBoss(pb_index)==true){
			boss.HP-=pl_bullet[pb_index].power;
			pl_bullet[pb_index].f=false;
		}
	}
	if(HitCheckPl_BombAndBoss()==true){
		boss.HP -= player.bomb_power;
	}

	for(int i_index=0;i_index<ITEM_MAX;i_index++){
		if(item[i_index].f==false)continue;

		HitCheckPlayerAndItem(i_index);
	}
}