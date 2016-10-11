#include"common.h"


int GetEmptyIndexOfPlayerBullet(){
	for(int i=0;i<PL_BULLET_MAX;i++){
		if((pl_bullet+i)->f==false)return i;
	}
	return -1;
}

void Pl_BulletSet(Position pos,double v,double shot_rad,int power,Bul_Color color,bool playerShot){
	int index = GetEmptyIndexOfPlayerBullet();
	if(index==-1)return;

	(pl_bullet+index)->f=true;
	(pl_bullet+index)->playerShot=playerShot;
	(pl_bullet+index)->c=0;
	(pl_bullet+index)->v=v;
	(pl_bullet+index)->rad=shot_rad;
	(pl_bullet+index)->power=power;
	(pl_bullet+index)->color=color;

	if(playerShot==true){
		(pl_bullet+index)->pos.x = pos.x+PLAYER_WIDTH/2;
		(pl_bullet+index)->pos.y = pos.y+PLAYER_HEIGHT/2;
	}
	else{
		(pl_bullet+index)->pos.x = pos.x+PL_SUBWEAPON_WIDTH/2;
		(pl_bullet+index)->pos.y = pos.y+PL_SUBWEAPON_HEIGHT/2;
	}
}


int GetNearestEnemyIndex(){
	int index=-1;
	double d1,d2;
	for(int i=0;i<ENEMY_MAX;i++){
		if(enemy[i].f==false)continue;
		if(enemy[i].status!=normal)continue;

		if(index==-1){
			index=i;
		}
		else{
			d1 = (enemy[index].pos.x+ENEMY_WIDTH/2-player.pos.x-PLAYER_WIDTH/2)*(enemy[index].pos.x+ENEMY_WIDTH/2-player.pos.x-PLAYER_WIDTH/2)+(enemy[index].pos.y+ENEMY_HEIGHT/2-player.pos.y-PLAYER_HEIGHT/2)*(enemy[index].pos.y+ENEMY_HEIGHT/2-player.pos.y-PLAYER_HEIGHT/2);
			d2 = (enemy[i].pos.x+ENEMY_WIDTH/2-player.pos.x-PLAYER_WIDTH/2)*(enemy[i].pos.x+ENEMY_WIDTH/2-player.pos.x-PLAYER_WIDTH/2)+(enemy[i].pos.y+ENEMY_HEIGHT/2-player.pos.y-PLAYER_HEIGHT/2)*(enemy[i].pos.y+ENEMY_HEIGHT/2-player.pos.y-PLAYER_HEIGHT/2); 

			if(d2<d1){
				index=i;
			}
		}
	}
	return index;
}

void Pl_BulletMove(int i){
	(pl_bullet+i)->pos.x += (pl_bullet+i)->v*cos((pl_bullet+i)->rad);
	(pl_bullet+i)->pos.y += (pl_bullet+i)->v*sin((pl_bullet+i)->rad);
}

bool VisibleBulletCheck(int i){
	if(((pl_bullet+i)->pos.x+gameData.eb_size[eb_fuda].height>0)&&((pl_bullet+i)->pos.x<FIELD_SIZE_WIDTH)){
		if(((pl_bullet+i)->pos.y+gameData.eb_size[eb_fuda].height>0)&&((pl_bullet+i)->pos.y<FIELD_SIZE_HEIGHT)){
			return true;
		}
	}
	return false;
}

void Pl_BulletUpdate(){
	for(int i=0;i<PL_BULLET_MAX;i++){
		if((pl_bullet+i)->f==false) continue;

		(pl_bullet+i)->c++;

		Pl_BulletMove(i);
		if(VisibleBulletCheck(i)==false) (pl_bullet+i)->f=false;
	}

	//ホーミング
	if(player.attack_pattern==front_curve){
		if(boss.f==false){
			int index = GetNearestEnemyIndex();
			if(index==-1)return;
			for(int i=0;i<PL_BULLET_MAX;i++){
				if(pl_bullet[i].color==bul_white){
					pl_bullet[i].rad = atan2(-pl_bullet[i].pos.y-PLAYER_HEIGHT/2+enemy[index].pos.y+ENEMY_HEIGHT/2,-pl_bullet[i].pos.x-PLAYER_WIDTH/2+enemy[index].pos.x+ENEMY_WIDTH/2);
				}
			}
		}
		else if(boss.status==b_normal){
			for(int i=0;i<PL_BULLET_MAX;i++){
				if(pl_bullet[i].color==bul_white){
					pl_bullet[i].rad = atan2(-pl_bullet[i].pos.y-PLAYER_HEIGHT/2+boss.pos.y+ENEMY_HEIGHT/2,-pl_bullet[i].pos.x-PLAYER_WIDTH/2+boss.pos.x+ENEMY_WIDTH/2);
				}
			}
		}
	}
}


void Pl_BulletDraw(){
	for(int i=0;i<PL_BULLET_MAX;i++){
		if((pl_bullet+i)->f==false) continue;

		SetDrawBlendMode(DX_BLENDMODE_ALPHA,180);
		DrawRotaGraph2(FIELD_OFFSET_X+Round((pl_bullet+i)->pos.x),FIELD_OFFSET_Y+Round((pl_bullet+i)->pos.y),gameData.eb_size[eb_fuda].width/2,gameData.eb_size[eb_fuda].height/2,1.0,M_PI/2+(pl_bullet+i)->rad,gameData.chip.e_bullet[eb_fuda][(pl_bullet+i)->color],true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	}
}

void Pl_BulletInit(){
	for(int i=0;i<PL_BULLET_MAX;i++){
		pl_bullet[i].f=false;
	}
}