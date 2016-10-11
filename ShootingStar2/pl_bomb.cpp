#include"common.h"


void Pl_BombSet(){
	if(pl_bomb.f==true)return;

	pl_bomb.c=0;
	pl_bomb.f=true;
	pl_bomb.pos.x=player.pos.x+PLAYER_WIDTH/2;
	pl_bomb.pos.y=player.pos.y+PLAYER_HEIGHT/2;

	player.bomb-=1.00;
	if(player.bomb<0.00)player.bomb=0.00;

	player.c=0;
	player.status=invincible;

	if(player.attack_pattern==front_curve)pl_bomb.v=2.0;
	if(player.attack_pattern==side_curve)pl_bomb.v=4.0;
	if(player.attack_pattern==back_curve)pl_bomb.v=5.0;
}

void Pl_BombUpdate(){
	if(pl_bomb.f==false) return;

	pl_bomb.c++;
	if(pl_bomb.c>=80){
		pl_bomb.f=false;
	}

	if(pl_bomb.c%5==0) pl_bomb.rot_rad=0.01*GetRand(314);

	pl_bomb.pos.y-=pl_bomb.v;
}

void Pl_BombDraw(){
	if(pl_bomb.f==false)return;

	if(pl_bomb.c<20){
		DrawRotaGraph2(FIELD_OFFSET_X+Round(pl_bomb.pos.x),FIELD_OFFSET_Y+Round(pl_bomb.pos.y),PL_BOMB_WIDTH/2,PL_BOMB_HEIGHT/2,1.0*pl_bomb.c/20,pl_bomb.rot_rad,gameData.chip.pl_bomb,true);
	}
	else{
		DrawRotaGraph2(FIELD_OFFSET_X+Round(pl_bomb.pos.x),FIELD_OFFSET_Y+Round(pl_bomb.pos.y),PL_BOMB_WIDTH/2,PL_BOMB_HEIGHT/2,1.0,pl_bomb.rot_rad,gameData.chip.pl_bomb,true);
	}
}

void Pl_BombInit(){
	pl_bomb.c=0;
	pl_bomb.f=false;
	pl_bomb.rot_rad=0.00;
}