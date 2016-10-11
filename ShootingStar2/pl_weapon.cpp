#include"common.h"


//ウエポンの座標に関する情報
void GetSubWeaponPos_Near_Front(Position pos[PL_SUBWEAPON_MAX]){
	if(player.power<1.00){
		pos[0] = GetPositionFromXY(0.00,0.00);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<2.00){
		pos[0] = GetPositionFromXY(0.00,-20.0);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<3.00){
		pos[0] = GetPositionFromXY(-10.0,-20.0);
		pos[1] = GetPositionFromXY(10.0,-20.0);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<4.00){
		pos[0] = GetPositionFromXY(-17.0,-20.0);
		pos[1] = GetPositionFromXY(0.00,-20.0);
		pos[2] = GetPositionFromXY(17.0,-20.0);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<5.00){
		pos[0] = GetPositionFromXY(-25.0,-20.0);
		pos[1] = GetPositionFromXY(-10.0,-20.0);
		pos[2] = GetPositionFromXY(10.0,-20.0);
		pos[3] = GetPositionFromXY(25.0,-20.0);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<6.00){
		pos[0] = GetPositionFromXY(-34.0,-20.0);
		pos[1] = GetPositionFromXY(-17.0,-20.0);
		pos[2] = GetPositionFromXY(0.00,-20.0);
		pos[3] = GetPositionFromXY(17.0,-20.0);
		pos[4] = GetPositionFromXY(34.0,-20.0);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else{
		pos[0] = GetPositionFromXY(-40.0,-20.0);
		pos[1] = GetPositionFromXY(-25.0,-20.0);
		pos[2] = GetPositionFromXY(-10.0,-20.0);
		pos[3] = GetPositionFromXY(10.0,-20.0);
		pos[4] = GetPositionFromXY(25.0,-20.0);
		pos[5] = GetPositionFromXY(40.0,-20.0);
	}
}

void GetSubWeaponPos_Near_Side(Position pos[PL_SUBWEAPON_MAX]){
	if(player.power<1.00){
		pos[0] = GetPositionFromXY(0.00,0.00);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<2.00){
		pos[0] = GetPositionFromXY(0.00,15.00*sin(M_PI*3/2));
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<3.00){
		pos[0] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[1] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<4.00){
		pos[0] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[1] = GetPositionFromXY(0.00,15.00*sin(M_PI*3/2));
		pos[2] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<5.00){
		pos[0] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[1] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[2] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[3] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<6.00){
		pos[0] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[1] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[2] = GetPositionFromXY(0.00,15.00*sin(M_PI*3/2));
		pos[3] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[4] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else{
		pos[0] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[1] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[2] = GetPositionFromXY(15.00*cos(M_PI),0.00);
		pos[3] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[4] = GetPositionFromXY(15.00*cos(0.00),0.00);
		pos[5] = GetPositionFromXY(15.00*cos(0.00),0.00);
	}
}

void GetSubWeaponPos_Near_Back(Position pos[PL_SUBWEAPON_MAX]){
	if(player.power<1.00){
		pos[0] = GetPositionFromXY(0.00,0.00);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<2.00){
		pos[0] = GetPositionFromXY(0.00,10.0);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<3.00){
		pos[0] = GetPositionFromXY(-10.0,10.0);
		pos[1] = GetPositionFromXY(10.0,10.0);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<4.00){
		pos[0] = GetPositionFromXY(-15.0,10.0);
		pos[1] = GetPositionFromXY(0.00,10.0);
		pos[2] = GetPositionFromXY(15.0,10.0);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<5.00){
		pos[0] = GetPositionFromXY(-25.0,10.0);
		pos[1] = GetPositionFromXY(-10.0,10.0);
		pos[2] = GetPositionFromXY(10.0,10.0);
		pos[3] = GetPositionFromXY(25.0,10.0);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<6.00){
		pos[0] = GetPositionFromXY(-30.0,10.0);
		pos[1] = GetPositionFromXY(-15.0,10.0);
		pos[2] = GetPositionFromXY(0.00,10.0);
		pos[3] = GetPositionFromXY(15.0,10.0);
		pos[4] = GetPositionFromXY(30.0,10.0);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else{
		pos[0] = GetPositionFromXY(-40.0,10.0);
		pos[1] = GetPositionFromXY(-25.0,10.0);
		pos[2] = GetPositionFromXY(-10.0,10.0);
		pos[3] = GetPositionFromXY(10.0,10.0);
		pos[4] = GetPositionFromXY(25.0,10.0);
		pos[5] = GetPositionFromXY(40.0,10.0);
	}
}


void GetSubWeaponPos_Far_Front(Position pos[PL_SUBWEAPON_MAX]){
	if(player.power<1.00){
		pos[0] = GetPositionFromXY(0.00,0.00);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<2.00){
		pos[0] = GetPositionFromXY(0.00,30.00*sin(M_PI*3/2));
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<3.00){
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*28/20),30.00*sin(M_PI*28/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*32/20),30.00*sin(M_PI*32/20));
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<4.00){
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*26/20),30.00*sin(M_PI*26/20));
		pos[1] = GetPositionFromXY(0.00,30.00*sin(M_PI*3/2));
		pos[2] = GetPositionFromXY(30.00*cos(M_PI*34/20),30.00*sin(M_PI*34/20));
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<5.00){
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*24/20),30.00*sin(M_PI*24/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*28/20),30.00*sin(M_PI*28/20));
		pos[2] = GetPositionFromXY(30.00*cos(M_PI*32/20),30.00*sin(M_PI*32/20));
		pos[3] = GetPositionFromXY(30.00*cos(M_PI*36/20),30.00*sin(M_PI*36/20));
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<6.00){
		pos[0] = GetPositionFromXY(35.00*cos(M_PI*22/20),35.00*sin(M_PI*22/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*26/20),30.00*sin(M_PI*26/20));
		pos[2] = GetPositionFromXY(0.00,30.00*sin(M_PI*3/2));
		pos[3] = GetPositionFromXY(30.00*cos(M_PI*34/20),30.00*sin(M_PI*34/20));
		pos[4] = GetPositionFromXY(35.00*cos(M_PI*38/20),35.00*sin(M_PI*38/20));
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else{
		pos[0] = GetPositionFromXY(35.00*cos(M_PI*20/20),35.00*sin(M_PI*20/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*24/20),30.00*sin(M_PI*24/20));
		pos[2] = GetPositionFromXY(30.00*cos(M_PI*28/20),30.00*sin(M_PI*28/20));
		pos[3] = GetPositionFromXY(30.00*cos(M_PI*32/20),30.00*sin(M_PI*32/20));
		pos[4] = GetPositionFromXY(30.00*cos(M_PI*36/20),30.00*sin(M_PI*36/20));
		pos[5] = GetPositionFromXY(35.00*cos(M_PI*40/20),35.00*sin(M_PI*40/20));
	}
}

void GetSubWeaponPos_Far_Side(Position pos[PL_SUBWEAPON_MAX]){
	if(player.power<1.00){
		pos[0] = GetPositionFromXY(0.00,0.00);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<2.00){
		pos[0] = GetPositionFromXY(0.00,40.00*sin(M_PI*3/2));
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<3.00){
		pos[0] = GetPositionFromXY(40.00*cos(M_PI),40.00*sin(M_PI));
		pos[1] = GetPositionFromXY(40.00*cos(0.00),40.00*sin(0.00));
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<4.00){
		pos[0] = GetPositionFromXY(40.00*cos(M_PI),40.00*sin(M_PI));
		pos[1] = GetPositionFromXY(0.00,40.00*sin(M_PI*3/2));
		pos[2] = GetPositionFromXY(40.00*cos(0.00),40.00*sin(0.00));
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<5.00){
		pos[0] = GetPositionFromXY(40.00*cos(M_PI*16/20),40.00*sin(M_PI*16/20));
		pos[1] = GetPositionFromXY(40.00*cos(M_PI*24/20),40.00*sin(M_PI*24/20));
		pos[2] = GetPositionFromXY(40.00*cos(M_PI*36/20),40.00*sin(M_PI*36/20));
		pos[3] = GetPositionFromXY(40.00*cos(M_PI*4/20),40.00*sin(M_PI*4/20));
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<6.00){
		pos[0] = GetPositionFromXY(40.00*cos(M_PI*18/20),40.00*sin(M_PI*18/20));
		pos[1] = GetPositionFromXY(40.00*cos(M_PI*22/20),40.00*sin(M_PI*22/20));
		pos[2] = GetPositionFromXY(0.00,40.00*sin(M_PI*3/2));
		pos[3] = GetPositionFromXY(40.00*cos(M_PI*38/20),40.00*sin(M_PI*38/20));
		pos[4] = GetPositionFromXY(40.00*cos(M_PI*2/20),40.00*sin(M_PI*2/20));
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else{
		pos[0] = GetPositionFromXY(40.00*cos(M_PI*16/20),40.00*sin(M_PI*16/20));
		pos[1] = GetPositionFromXY(40.00*cos(M_PI),40.00*sin(M_PI));
		pos[2] = GetPositionFromXY(40.00*cos(M_PI*24/20),40.00*sin(M_PI*24/20));
		pos[3] = GetPositionFromXY(40.00*cos(M_PI*36/20),40.00*sin(M_PI*36/20));
		pos[4] = GetPositionFromXY(40.00*cos(0.00),40.00*sin(0.00));
		pos[5] = GetPositionFromXY(40.00*cos(M_PI*4/20),40.00*sin(M_PI*4/20));
	}
}

void GetSubWeaponPos_Far_Back(Position pos[PL_SUBWEAPON_MAX]){
	if(player.power<1.00){
		pos[0] = GetPositionFromXY(0.00,0.00);
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<2.00){
		pos[0] = GetPositionFromXY(0.00,30.00*sin(M_PI/2));
		pos[1] = GetPositionFromXY(0.00,0.00);
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<3.00){
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*12/20),30.00*sin(M_PI*12/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*8/20),30.00*sin(M_PI*8/20));
		pos[2] = GetPositionFromXY(0.00,0.00);
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<4.00){
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*14/20),30.00*sin(M_PI*14/20));
		pos[1] = GetPositionFromXY(0.00,30.00*sin(M_PI/2));
		pos[2] = GetPositionFromXY(30.00*cos(M_PI*6/20),30.00*sin(M_PI*6/20));
		pos[3] = GetPositionFromXY(0.00,0.00);
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<5.00){
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*16/20),30.00*sin(M_PI*16/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*12/20),30.00*sin(M_PI*12/20));
		pos[2] = GetPositionFromXY(30.00*cos(M_PI*8/20),30.00*sin(M_PI*8/20));
		pos[3] = GetPositionFromXY(30.00*cos(M_PI*4/20),30.00*sin(M_PI*4/20));
		pos[4] = GetPositionFromXY(0.00,0.00);
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else if(player.power<6.00){
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*18/20),30.00*sin(M_PI*18/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*14/20),30.00*sin(M_PI*14/20));
		pos[2] = GetPositionFromXY(0.00,30.00*sin(M_PI/2));
		pos[3] = GetPositionFromXY(30.00*cos(M_PI*6/20),30.00*sin(M_PI*6/20));
		pos[4] = GetPositionFromXY(30.00*cos(M_PI*2/20),30.00*sin(M_PI*2/20));
		pos[5] = GetPositionFromXY(0.00,0.00);
	}
	else{
		pos[0] = GetPositionFromXY(30.00*cos(M_PI*20/20),30.00*sin(M_PI*20/20));
		pos[1] = GetPositionFromXY(30.00*cos(M_PI*16/20),30.00*sin(M_PI*16/20));
		pos[2] = GetPositionFromXY(30.00*cos(M_PI*12/20),30.00*sin(M_PI*12/20));
		pos[3] = GetPositionFromXY(30.00*cos(M_PI*8/20),30.00*sin(M_PI*8/20));
		pos[4] = GetPositionFromXY(30.00*cos(M_PI*4/20),30.00*sin(M_PI*4/20));
		pos[5] = GetPositionFromXY(30.00*cos(M_PI*0/20),30.00*sin(M_PI*0/20));
	}
}


void GetSubWeaponPos_Near(Position pos[PL_SUBWEAPON_MAX]){
	if(player.attack_pattern==front_curve) GetSubWeaponPos_Near_Front(pos);
	if(player.attack_pattern==side_curve)  GetSubWeaponPos_Near_Side(pos);
	if(player.attack_pattern==back_curve)  GetSubWeaponPos_Near_Back(pos);
}

void GetSubWeaponPos_Far(Position pos[PL_SUBWEAPON_MAX]){
	if(player.attack_pattern==front_curve) GetSubWeaponPos_Far_Front(pos);
	if(player.attack_pattern==side_curve)  GetSubWeaponPos_Far_Side(pos);
	if(player.attack_pattern==back_curve)  GetSubWeaponPos_Far_Back(pos);
}


Position GetAcceraLinePos(Position start_pos,Position end_pos,int c,int bet_time){
	Position obj_pos;
	double x_max = end_pos.x-start_pos.x;
	double y_max = end_pos.y-start_pos.y;

	obj_pos.x = start_pos.x + 2.0*x_max*c/bet_time - x_max*c*c/bet_time/bet_time;
	obj_pos.y = start_pos.y + 2.0*y_max*c/bet_time - y_max*c*c/bet_time/bet_time;

	return obj_pos;
}

void Pl_SubWeaponMove_Approach(){
	pl_subWeapon.c++;
	if(pl_subWeapon.c>30) pl_subWeapon.c=30;

	Position pos_from[PL_SUBWEAPON_MAX],pos_to[PL_SUBWEAPON_MAX];

	GetSubWeaponPos_Far(pos_from);
	GetSubWeaponPos_Near(pos_to);

	for(int i=0;i<(int)player.power;i++){
		pl_subWeapon.subWeapon[i].pos = GetAcceraLinePos(pos_from[i],pos_to[i],pl_subWeapon.c,30);
	}
}

void Pl_SubWeaponMove_Secission(){
	pl_subWeapon.c--;
	if(pl_subWeapon.c<0) pl_subWeapon.c=0;

	Position pos_from[PL_SUBWEAPON_MAX],pos_to[PL_SUBWEAPON_MAX];

	GetSubWeaponPos_Far(pos_to);
	GetSubWeaponPos_Near(pos_from);

	for(int i=0;i<(int)player.power;i++){
		pl_subWeapon.subWeapon[i].pos = GetAcceraLinePos(pos_from[i],pos_to[i],30-pl_subWeapon.c,30);
	}
}




//ウエポンのショットに関する情報
void SetValueSubWeapon(int num_6,int num_3,bool shot_f,int power,double shot_rad,double shot_v,Bul_Color shot_color){
	pl_subWeapon.subWeapon[num_6].shot_f[num_3]			= shot_f;
	pl_subWeapon.subWeapon[num_6].power[num_3]			= power;
	pl_subWeapon.subWeapon[num_6].shot_bul_rad[num_3]	= shot_rad;
	pl_subWeapon.subWeapon[num_6].shot_v[num_3]			= shot_v;
	pl_subWeapon.subWeapon[num_6].shot_bul_color[num_3] = shot_color;
}

void SetSubWeaponShotInfomation_Near_Front(){
	if(player.power<1.00){

	}
	else if(player.power<2.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,50.0,bul_white);
	}
	else if(player.power<3.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,50.0,bul_white);
		SetValueSubWeapon(1,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(1,2,true,5,M_PI*31/20,50.0,bul_white);
	}
	else if(player.power<4.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*29/20,50.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(1,2,false,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(2,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(2,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(2,2,true,5,M_PI*31/20,50.0,bul_white);
	}
	else if(player.power<5.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*29/20,50.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(1,2,false,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(2,0,true,4,M_PI*29/20,50.0,bul_yellow);
		SetValueSubWeapon(2,1,true,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(2,2,false,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(3,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(3,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(3,2,true,5,M_PI*31/20,50.0,bul_white);
	}
	else if(player.power<6.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*29/20,50.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(1,2,false,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(2,0,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(2,1,false,3,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(2,2,false,3,M_PI*31/20,50.0,bul_white);
		SetValueSubWeapon(3,0,true,4,M_PI*29/20,50.0,bul_yellow);
		SetValueSubWeapon(3,1,true,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(3,2,false,4,M_PI*31/20,50.0,bul_yellow);
		SetValueSubWeapon(4,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(4,1,true,5,M_PI*29/20,50.0,bul_white);
		SetValueSubWeapon(4,2,true,5,M_PI*31/20,50.0,bul_white);
	}
	else{
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*59/40,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*61/40,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*59/40,50.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*61/40,50.0,bul_yellow);
		SetValueSubWeapon(1,2,false,4,M_PI*61/40,50.0,bul_yellow);
		SetValueSubWeapon(2,0,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(2,1,false,3,M_PI*59/40,50.0,bul_white);
		SetValueSubWeapon(2,2,false,3,M_PI*61/40,50.0,bul_white);
		SetValueSubWeapon(3,0,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(3,1,false,3,M_PI*59/40,50.0,bul_white);
		SetValueSubWeapon(3,2,false,3,M_PI*61/40,50.0,bul_white);
		SetValueSubWeapon(4,0,true,4,M_PI*61/40,50.0,bul_yellow);
		SetValueSubWeapon(4,1,true,4,M_PI*59/40,50.0,bul_yellow);
		SetValueSubWeapon(4,2,false,4,M_PI*59/40,50.0,bul_yellow);
		SetValueSubWeapon(5,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(5,1,true,5,M_PI*59/40,50.0,bul_white);
		SetValueSubWeapon(5,2,true,5,M_PI*61/40,50.0,bul_white);
	}
}

void SetSubWeaponShotInfomation_Near_Side(){
	if(player.power<1.00){

	}
	else if(player.power<2.00){
		SetValueSubWeapon(0,0,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,1,M_PI*3/2,50.0,bul_white);
	}
	else if(player.power<3.00){
		SetValueSubWeapon(0,0,true,2,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,2,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,2,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,0,true,2,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,1,true,2,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,2,true,2,M_PI*3/2,50.0,bul_white);
	}
	else if(player.power<4.00){
		SetValueSubWeapon(0,0,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,0,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,1,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,2,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,0,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(2,1,true,3,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(2,2,true,3,M_PI*3/2,50.0,bul_white);
	}
	else if(player.power<5.00){
		SetValueSubWeapon(0,0,true,4,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,4,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,4,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,1,true,4,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,2,true,4,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,0,true,4,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,1,true,4,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,2,true,4,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(3,0,true,4,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(3,1,true,4,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(3,2,true,4,M_PI*3/2,50.0,bul_white);
	}
	else if(player.power<6.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,0,true,5,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,1,true,5,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,2,true,5,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,0,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,5,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(3,1,true,5,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(3,2,true,5,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(4,0,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(4,1,true,5,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(4,2,true,5,M_PI*3/2,50.0,bul_white);
	}
	else{
		SetValueSubWeapon(0,0,true,7,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,7,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,7,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(1,0,true,7,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,1,true,7,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,2,true,7,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,0,true,7,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,7,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,7,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,7,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(3,1,true,7,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(3,2,true,7,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(4,0,true,7,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(4,1,true,7,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(4,2,true,7,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(5,0,true,7,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(5,1,true,7,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(5,2,true,7,M_PI*3/2,50.0,bul_white);
	}
}

void SetSubWeaponShotInfomation_Near_Back(){
	if(player.power<1.00){

	}
	else if(player.power<2.00){
		SetValueSubWeapon(0,0,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,1,M_PI*3/2,50.0,bul_white);
	}
	else if(player.power<3.00){
		SetValueSubWeapon(0,0,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,2,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(1,1,true,2,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(1,2,true,2,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<4.00){
		SetValueSubWeapon(0,0,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,1,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,2,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,0,true,3,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(2,1,true,3,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(2,2,true,3,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<5.00){
		SetValueSubWeapon(0,0,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(2,1,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(2,2,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,0,true,4,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(3,1,true,4,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(3,2,true,4,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<6.00){
		SetValueSubWeapon(0,0,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,1,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,2,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(4,0,true,5,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(4,1,true,5,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(4,2,true,5,M_PI*118/80,50.0,bul_white);
	}
	else{
		SetValueSubWeapon(0,0,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(3,1,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(3,2,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(4,0,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(4,1,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(4,2,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(5,0,true,6,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(5,1,true,6,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(5,2,true,6,M_PI*118/80,50.0,bul_white);
	}
}


void SetSubWeaponShotInfomation_Far_Front(){
	if(player.power<1.00){

	}
	else if(player.power<2.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,30.0,bul_white);
	}
	else if(player.power<3.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(1,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(1,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(1,2,true,5,M_PI*31/20,30.0,bul_white);
	}
	else if(player.power<4.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*3/2,30.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(1,2,true,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(2,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(2,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(2,2,true,5,M_PI*31/20,30.0,bul_white);
	}
	else if(player.power<5.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(1,2,false,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(2,0,true,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(2,1,true,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(2,2,false,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(3,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(3,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(3,2,true,5,M_PI*31/20,30.0,bul_white);
	}
	else if(player.power<6.00){
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(1,2,false,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(2,0,true,3,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(2,1,false,3,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(2,2,false,3,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(3,0,true,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(3,1,true,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(3,2,false,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(4,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(4,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(4,2,true,5,M_PI*31/20,30.0,bul_white);
	}
	else{
		SetValueSubWeapon(0,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(1,1,true,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(1,2,false,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(2,0,true,3,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(2,1,false,3,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(2,2,false,3,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(3,0,true,3,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(3,1,false,3,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(3,2,false,3,M_PI*31/20,30.0,bul_white);
		SetValueSubWeapon(4,0,true,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(4,1,true,4,M_PI*31/20,30.0,bul_yellow);
		SetValueSubWeapon(4,2,false,4,M_PI*29/20,30.0,bul_yellow);
		SetValueSubWeapon(5,0,true,5,M_PI*3/2,30.0,bul_white);
		SetValueSubWeapon(5,1,true,5,M_PI*29/20,30.0,bul_white);
		SetValueSubWeapon(5,2,true,5,M_PI*31/20,30.0,bul_white);
	}
}

void SetSubWeaponShotInfomation_Far_Side(){
	if(player.power<1.00){

	}
	else if(player.power<2.00){
		SetValueSubWeapon(0,0,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,1,M_PI*3/2,50.0,bul_white);
	}
	else if(player.power<3.00){
		SetValueSubWeapon(0,0,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,2,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(1,1,true,2,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(1,2,true,2,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<4.00){
		SetValueSubWeapon(0,0,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,1,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,2,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,0,true,3,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(2,1,true,3,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(2,2,true,3,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<5.00){
		SetValueSubWeapon(0,0,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(2,1,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(2,2,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,0,true,4,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(3,1,true,4,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(3,2,true,4,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<6.00){
		SetValueSubWeapon(0,0,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,1,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,2,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(4,0,true,5,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(4,1,true,5,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(4,2,true,5,M_PI*118/80,50.0,bul_white);
	}
	else{
		SetValueSubWeapon(0,0,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(3,1,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(3,2,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(4,0,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(4,1,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(4,2,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(5,0,true,6,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(5,1,true,6,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(5,2,true,6,M_PI*118/80,50.0,bul_white);
	}
}

void SetSubWeaponShotInfomation_Far_Back(){
	if(player.power<1.00){

	}
	else if(player.power<2.00){
		SetValueSubWeapon(0,0,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,1,true,1,M_PI*3/2,50.0,bul_white);
		SetValueSubWeapon(0,2,true,1,M_PI*3/2,50.0,bul_white);
	}
	else if(player.power<3.00){
		SetValueSubWeapon(0,0,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,2,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,2,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(1,1,true,2,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(1,2,true,2,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<4.00){
		SetValueSubWeapon(0,0,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,3,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,1,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(1,2,true,3,M_PI*3/2,50.0,bul_green);
		SetValueSubWeapon(2,0,true,3,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(2,1,true,3,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(2,2,true,3,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<5.00){
		SetValueSubWeapon(0,0,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,4,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,4,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(2,1,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(2,2,true,4,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,0,true,4,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(3,1,true,4,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(3,2,true,4,M_PI*118/80,50.0,bul_white);
	}
	else if(player.power<6.00){
		SetValueSubWeapon(0,0,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,5,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,5,M_PI*122/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,6,M_PI*3/2,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,1,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(3,2,true,5,M_PI*118/80,50.0,bul_green);
		SetValueSubWeapon(4,0,true,5,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(4,1,true,5,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(4,2,true,5,M_PI*118/80,50.0,bul_white);
	}
	else{
		SetValueSubWeapon(0,0,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,1,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(0,2,true,6,M_PI*122/80,50.0,bul_white);
		SetValueSubWeapon(1,0,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(1,1,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(1,2,true,6,M_PI*124/80,50.0,bul_green);
		SetValueSubWeapon(2,0,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(2,1,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(2,2,true,6,M_PI*122/80,50.0,bul_blue);
		SetValueSubWeapon(3,0,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(3,1,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(3,2,true,6,M_PI*118/80,50.0,bul_blue);
		SetValueSubWeapon(4,0,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(4,1,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(4,2,true,6,M_PI*116/80,50.0,bul_green);
		SetValueSubWeapon(5,0,true,6,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(5,1,true,6,M_PI*118/80,50.0,bul_white);
		SetValueSubWeapon(5,2,true,6,M_PI*118/80,50.0,bul_white);
	}
}

void SetSubWeaponShotInfomation(){
	if(gameData.key[KEY_INPUT_LSHIFT]==1){
		if(player.attack_pattern==front_curve) SetSubWeaponShotInfomation_Near_Front();
		if(player.attack_pattern==side_curve)  SetSubWeaponShotInfomation_Near_Side();
		if(player.attack_pattern==back_curve)  SetSubWeaponShotInfomation_Near_Back();
	}
	else{
		if(player.attack_pattern==front_curve) SetSubWeaponShotInfomation_Far_Front();
		if(player.attack_pattern==side_curve)  SetSubWeaponShotInfomation_Far_Side();
		if(player.attack_pattern==back_curve)  SetSubWeaponShotInfomation_Far_Back();
	}
}




void Pl_SubWeaponUpdate(){
	pl_subWeapon.chip_rad+=M_PI/48;
	SetSubWeaponShotInfomation();
}

void Pl_SubWeaponDraw(){
	if((player.status!=normal)&&(player.status!=invincible))return;

	for(int i=0;i<(int)player.power;i++){
		DrawRotaGraph2(FIELD_OFFSET_X+Round(player.pos.x+PLAYER_WIDTH/2+pl_subWeapon.subWeapon[i].pos.x),
						FIELD_OFFSET_Y+Round(player.pos.y+PLAYER_HEIGHT/2+pl_subWeapon.subWeapon[i].pos.y),
						PL_SUBWEAPON_WIDTH/2,PL_SUBWEAPON_HEIGHT/2,1.0,pl_subWeapon.chip_rad,gameData.chip.pl_subwep,true);
	}
}

void Pl_SubWeaponInit(){
	pl_subWeapon.c=0;
	pl_subWeapon.chip_rad=0.00;

	SetSubWeaponShotInfomation();
}