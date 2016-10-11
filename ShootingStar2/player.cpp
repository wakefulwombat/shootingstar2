#include"common.h"


///playerÇ™deadèÛë‘Ç…Ç»ÇÈÇ∆Ç´Ç…åƒÇ‘ÅB
void PlayerHited(){
	player.c=0;
	player.chip_rad=M_PI/2;
	player.shot_c=0;
	player.status=dead;
	player.life--;
	if(player.life<0){

	}
}

///powerÇïœâªÇ≥ÇπÇÈéûÇ…åƒÇ‘
void PlayerPowerChanged(double variation,bool add){
	if(add==true){
		if(((int)player.power) != ((int)(player.power+variation))){
			player.power+=variation;
			if(player.power<0)player.power=0.0;
			if(player.power>=6.99)player.power=6.99;
			Pl_SubWeaponMove_Approach();
		}
		else{
			player.power+=variation;
			if(player.power<0)player.power=0.0;
			if(player.power>=6.99)player.power=6.99;
		}
	}
	else{
		player.power = variation;
		Pl_SubWeaponMove_Approach();
	}
}

///bombÇïœâªÇ≥ÇπÇÈéûÇ…åƒÇ‘
void PlayerBombChanged(double variation,bool add){
	if(add==true){
		player.bomb+=variation;
		if(player.bomb<0)player.bomb=0.0;
		if(player.bomb>=6.99)player.bomb=6.99;
	}
	else{
		player.bomb = variation;
	}
}


void KeyCheck(){
	GetHitKeyStateAll(gameData.key);

	if(gameData.key[KEY_INPUT_LSHIFT]==1){
		Pl_SubWeaponMove_Approach();
	}
	else{
		Pl_SubWeaponMove_Secission();
	}

	if(gameData.key[KEY_INPUT_Z]==1){
		player.shot_c++;
		if(player.shot_c%PL_SHOT_BET_TIME==1){
			Position temp_pos;
			temp_pos.x=player.pos.x-gameData.eb_size[eb_fuda].width/2-1;
			temp_pos.y=player.pos.y+gameData.eb_size[eb_fuda].height;
			Pl_BulletSet(temp_pos,player.shot_v,M_PI*3/2,player.shot_power,bul_red);
			temp_pos.x=player.pos.x+gameData.eb_size[eb_fuda].width/2+1;
			Pl_BulletSet(temp_pos,player.shot_v,M_PI*3/2,player.shot_power,bul_red);

			for(int i=0;i<(int)player.power;i++){
				for(int j=0;j<3;j++){
					if(pl_subWeapon.subWeapon[i].shot_f[j]==false)break;

					temp_pos.x = player.pos.x+PLAYER_WIDTH/2+pl_subWeapon.subWeapon[i].pos.x-gameData.eb_size[eb_fuda].width/2;
					temp_pos.y = player.pos.y+pl_subWeapon.subWeapon[i].pos.y+gameData.eb_size[eb_fuda].height;
					Pl_BulletSet(temp_pos,pl_subWeapon.subWeapon[i].shot_v[j],pl_subWeapon.subWeapon[i].shot_bul_rad[j],pl_subWeapon.subWeapon[i].power[j],pl_subWeapon.subWeapon[i].shot_bul_color[j],false);
				}
			}
		}
	}
	else{
		player.shot_c=0;
	}

	if(gameData.key[KEY_INPUT_X]==1){//É{ÉÄ
		if((player.status==normal)||(player.status==invincible)){
			if(player.bomb>=1.00){
				Pl_BombSet();
			}
		}
	}
}

void PlayerMove(){
	int x=0,y=0;
	if(gameData.key[KEY_INPUT_UP]==1)	y=-1;
	if(gameData.key[KEY_INPUT_DOWN]==1)	y=1;
	if(gameData.key[KEY_INPUT_LEFT]==1)	x=-1;
	if(gameData.key[KEY_INPUT_RIGHT]==1)x=1;
	
	double rad=1.00;
	if((x!=0)||(y!=0)) rad = atan2((double)y,(double)x);
	
	if(rad!=1.00){
		if(gameData.key[KEY_INPUT_LSHIFT]==1){
			player.pos.x+=player.v/2*cos(rad);
			player.pos.y+=player.v/2*sin(rad);
		}
		else{
			player.pos.x+=player.v*cos(rad);
			player.pos.y+=player.v*sin(rad);
		}
	}

	if(player.pos.x<0.00)player.pos.x=0.00;
	if(player.pos.y<0.00)player.pos.y=0.00;
	if(player.pos.x>(double)(FIELD_SIZE_WIDTH-PLAYER_WIDTH)) player.pos.x=(double)(FIELD_SIZE_WIDTH-PLAYER_WIDTH);
	if(player.pos.y>(double)(FIELD_SIZE_HEIGHT-PLAYER_HEIGHT)) player.pos.y=(double)(FIELD_SIZE_HEIGHT-PLAYER_HEIGHT);

	if(player.pos.y<FIELD_SIZE_HEIGHT*0.3) ItemSetToCollecting();
}


void PlayerUpdate(){
	player.c++;

	if(player.status==normal){
		if(player.c%10==0)player.chip_rad+=M_PI/2;
		if(player.c%30==0)player.power-=0.01;
		KeyCheck();
		if(gameData.key[KEY_INPUT_LSHIFT]==1)ItemSetToCollectingNear();
		PlayerMove();
	}
	if(player.status==dead){
		if(player.c>=90){
			player.status=recovering;
			player.pos=GetPositionFromXY(0.5*(FIELD_SIZE_WIDTH-PLAYER_WIDTH),0.9*(FIELD_SIZE_HEIGHT-PLAYER_HEIGHT));
		}
	}
	if(player.status==recovering){
		player.pos.y-=0.5;
		if(player.c>=150){
			player.c=0;
			player.status=invincible;
		}
	}
	if(player.status==invincible){
		if(player.c%10==0)player.chip_rad+=M_PI/2;
		if(player.c>=200){
			player.status=normal;
		}
		KeyCheck();
		ItemSetToCollecting();
		if(gameData.key[KEY_INPUT_LSHIFT]==1)ItemSetToCollectingNear();
		PlayerMove();
	}

	player.power = (double)Round(player.power*100)/100;
	player.bomb  = (double)Round(player.bomb*100)/100;

	if(player.power<0)player.power=0.0;
	if(player.power>=6.99)player.power=6.99;
	if(player.bomb<0)player.bomb=0.0;
	if(player.bomb>=6.00)player.bomb=6.00;
}

void PlayerDraw(){
	if(player.status==normal){
		DrawGraph(FIELD_OFFSET_X+Round(player.pos.x),FIELD_OFFSET_Y+Round(player.pos.y),gameData.chip.player[1+Round(sin(player.chip_rad))],true);
	}
	if(player.status==dead){
		DrawGraph(FIELD_OFFSET_X+Round(player.pos.x)-(EXPLODE_WIDTH-PLAYER_WIDTH)/2,FIELD_OFFSET_Y+Round(player.pos.y)-(EXPLODE_HEIGHT-PLAYER_HEIGHT)/2,gameData.chip.explode[(player.c-player.c%6)/6],true);
	}
	if(player.status==recovering){
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
		DrawGraph(FIELD_OFFSET_X+Round(player.pos.x),FIELD_OFFSET_Y+Round(player.pos.y),gameData.chip.player[1],true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	}
	if(player.status==invincible){
		if(((player.c-player.c%5)/5)%2==0){
			SetDrawBlendMode(DX_BLENDMODE_ALPHA,64);
		}
		else{
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
		}
		DrawGraph(FIELD_OFFSET_X+Round(player.pos.x),FIELD_OFFSET_Y+Round(player.pos.y),gameData.chip.player[1+Round(sin(player.chip_rad))],true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	}
}

void PlayerInit(){
	player.c=0;
	player.chip_rad=0.00;
	player.shot_c=0;
	player.status=normal;
	player.v=4.0;
	player.life=2;
	player.shot_v=60.0;
	player.pos=GetPositionFromXY(0.5*(FIELD_SIZE_WIDTH-PLAYER_WIDTH),0.9*(FIELD_SIZE_HEIGHT-PLAYER_HEIGHT));
	player.bomb=2.00;
	player.power=2.98;
	player.attack_pattern = front_curve;
	player.shot_power=20;
	player.bomb_power=8;
}