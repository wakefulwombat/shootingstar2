#include"common.h"


int GetEmptyEnemyIndex(){
	for(int i=0;i<ENEMY_MAX;i++){
		if(enemy[i].f==false)return i;
	}
	return -1;
}

double GetFixedRad(double rad){
	while(rad>M_PI*2){
		rad-=M_PI*2;
	}
	while(rad<0.0){
		rad+=M_PI*2;
	}

	return rad;
}

Direction GetDirectionFromRad(double rad){
	rad = GetFixedRad(rad);

	if(rad<M_PI/8){
		return dir_right;
	}
	else if(rad<M_PI*3/8){
		return dir_downright;
	}
	else if(rad<M_PI*5/8){
		return dir_down;
	}
	else if(rad<M_PI*7/8){
		return dir_downleft;
	}
	else if(rad<M_PI*9/8){
		return dir_left;
	}
	else if(rad<M_PI*11/8){
		return dir_upleft;
	}
	else if(rad<M_PI*13/8){
		return dir_up;
	}
	else if(rad<M_PI*15/8){
		return dir_upright;
	}
	else{
		return dir_right;
	}
}

void EnemySet(StaticEnemyData* staticData,StaticEnemyShotData *staticShotData){
	int index = GetEmptyEnemyIndex();
	if(index==-1)return;

	enemy[index].staticData = staticData;
	enemy[index].staticShotData[0] = staticShotData;
	enemy[index].staticShotData[1] = staticShotData+1;
	enemy[index].staticShotData[2] = staticShotData+2;


	enemy[index].f=true;
	enemy[index].c=0;
	enemy[index].chip_rad=0.00;
	enemy[index].status=normal;
	enemy[index].HP=staticData->HP_MAX;
	enemy[index].pos=staticData->startPos;
	enemy[index].direction=GetDirectionFromRad(staticData->move_rad);
	enemy[index].trans_rad=staticData->move_rad;

	//ボスのデータかどうか
	if(staticData->movePattern==21){
		enemy[index].f=false;
		GameMusicPlay((MusicList)(gameData.stageData.stage*2-1));
		BossSet(staticData->startPos,staticData->charaKind,staticData->HP_MAX);
	}
}

void EnemyAppearCheck(){
	for(int i=0;i<EN_ORDER_MAX;i++){
		if(gameData.stageData.enemyData[i].validable==false)return;

		if(gameData.stageData.enemyData[i].appearTime==gameData.stageData.c){

			EnemySet(&gameData.stageData.enemyData[i],gameData.stageData.enemyShotData[i]);
		}
	}
}


//非停止単純等速直進
void EnemyMovePattern_00(int index){
	enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
	enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
}

//一時停止有単純等速直進(move_v,move_rad,moveBetTime使用)
void EnemyMovePattern_01(int index){
	enemy[index].trans_rad=enemy[index].staticData->move_rad;

	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//一時停止有単純等速直進(stopPos,moveBetTime使用 move_v,move_radは一時停止後使用)
void EnemyMovePattern_02(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double dx=enemy[index].staticData->stopPos.x-enemy[index].staticData->startPos.x,dy=enemy[index].staticData->stopPos.y-enemy[index].staticData->startPos.y;
		double vx=dx/enemy[index].staticData->move_bet_time,vy=dy/enemy[index].staticData->move_bet_time;
		enemy[index].trans_rad=atan2(dy,dx);

		enemy[index].pos.x+=vx;
		enemy[index].pos.y+=vy;
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad=enemy[index].staticData->move_rad;
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//sin波非停止(stop_xを振れ幅,stop_yを振動角速度に使用)
void EnemyMovePattern_03(int index){
	double vx,vy;
	vx = cos(enemy[index].staticData->move_rad)*enemy[index].staticData->move_v - sin(enemy[index].staticData->move_rad)*enemy[index].staticData->stopPos.x*enemy[index].staticData->stopPos.y*2*M_PI/360*sin(M_PI/50*enemy[index].c);
	vy = sin(enemy[index].staticData->move_rad)*enemy[index].staticData->move_v + cos(enemy[index].staticData->move_rad)*enemy[index].staticData->stopPos.x*enemy[index].staticData->stopPos.y*2*M_PI/360*sin(M_PI/50*enemy[index].c);
	enemy[index].trans_rad = atan2(vy,vx);
	
	enemy[index].pos.x += vx;
	enemy[index].pos.y += vy;
}

//加速度直進(stopPos,moveBetTime使用 一時停止後move_v,move_rad使用)
void EnemyMovePattern_04(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double dx=enemy[index].staticData->stopPos.x-enemy[index].staticData->startPos.x,dy=enemy[index].staticData->stopPos.y-enemy[index].staticData->startPos.y;
		enemy[index].trans_rad = atan2(dy,dx);

		enemy[index].pos.x = enemy[index].staticData->startPos.x + 2.0*dx*enemy[index].c/enemy[index].staticData->move_bet_time - dx*enemy[index].c*enemy[index].c/enemy[index].staticData->move_bet_time/enemy[index].staticData->move_bet_time;
		enemy[index].pos.y = enemy[index].staticData->startPos.y + 2.0*dy*enemy[index].c/enemy[index].staticData->move_bet_time - dy*enemy[index].c*enemy[index].c/enemy[index].staticData->move_bet_time/enemy[index].staticData->move_bet_time;
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad = enemy[index].staticData->move_rad;

		enemy[index].pos.x += enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y += enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//bezier曲線(制御点0,0 一時停止後move_v,move_rad使用)
void EnemyMovePattern_05(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;
		enemy[index].pos.x = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.x + 2.0*t*(1.0-t)*0.0 + t*t*enemy[index].staticData->stopPos.x;
		enemy[index].pos.y = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.y + 2.0*t*(1.0-t)*0.0 + t*t*enemy[index].staticData->stopPos.y;

		double dx,dy;
		dx = -2.0*(1.0-t)*enemy[index].staticData->startPos.x + (2.0-4.0*t)*0.0 + 2.0*t*enemy[index].staticData->stopPos.x;
		dy = -2.0*(1.0-t)*enemy[index].staticData->startPos.y + (2.0-4.0*t)*0.0 + 2.0*t*enemy[index].staticData->stopPos.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad = enemy[index].staticData->move_rad;

		enemy[index].pos.x += enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y += enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//bezier曲線(制御点FIELD_SIZE_WIDTH,0 一時停止後move_v,move_rad使用)
void EnemyMovePattern_06(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;
		enemy[index].pos.x = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.x + 2.0*t*(1.0-t)*FIELD_SIZE_WIDTH + t*t*enemy[index].staticData->stopPos.x;
		enemy[index].pos.y = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.y + 2.0*t*(1.0-t)*0.0 + t*t*enemy[index].staticData->stopPos.y;

		double dx,dy;
		dx = -2.0*(1.0-t)*enemy[index].staticData->startPos.x + (2.0-4.0*t)*FIELD_SIZE_WIDTH + 2.0*t*enemy[index].staticData->stopPos.x;
		dy = -2.0*(1.0-t)*enemy[index].staticData->startPos.y + (2.0-4.0*t)*0.0 + 2.0*t*enemy[index].staticData->stopPos.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad = enemy[index].staticData->move_rad;

		enemy[index].pos.x += enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y += enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//bezier曲線(制御点0,0.6*FIELD_SIZE_HEIGHT 一時停止後move_v,move_rad使用)
void EnemyMovePattern_07(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;
		enemy[index].pos.x = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.x + 2.0*t*(1.0-t)*0.0 + t*t*enemy[index].staticData->stopPos.x;
		enemy[index].pos.y = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.y + 2.0*t*(1.0-t)*0.6*FIELD_SIZE_HEIGHT + t*t*enemy[index].staticData->stopPos.y;

		double dx,dy;
		dx = -2.0*(1.0-t)*enemy[index].staticData->startPos.x + (2.0-4.0*t)*0.0 + 2.0*t*enemy[index].staticData->stopPos.x;
		dy = -2.0*(1.0-t)*enemy[index].staticData->startPos.y + (2.0-4.0*t)*0.6*FIELD_SIZE_HEIGHT + 2.0*t*enemy[index].staticData->stopPos.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad = enemy[index].staticData->move_rad;

		enemy[index].pos.x += enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y += enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//bezier曲線(制御点FIELD_SIZE_WIDTH,0.6*FIELD_SIZE_HEIGHT 一時停止後move_v,move_rad使用)
void EnemyMovePattern_08(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;
		enemy[index].pos.x = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.x + 2.0*t*(1.0-t)*FIELD_SIZE_WIDTH + t*t*enemy[index].staticData->stopPos.x;
		enemy[index].pos.y = (1.0-t)*(1.0-t)*enemy[index].staticData->startPos.y + 2.0*t*(1.0-t)*0.6*FIELD_SIZE_HEIGHT + t*t*enemy[index].staticData->stopPos.y;

		double dx,dy;
		dx = -2.0*(1.0-t)*enemy[index].staticData->startPos.x + (2.0-4.0*t)*FIELD_SIZE_WIDTH + 2.0*t*enemy[index].staticData->stopPos.x;
		dy = -2.0*(1.0-t)*enemy[index].staticData->startPos.y + (2.0-4.0*t)*0.6*FIELD_SIZE_HEIGHT + 2.0*t*enemy[index].staticData->stopPos.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad = enemy[index].staticData->move_rad;

		enemy[index].pos.x += enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y += enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//ferguson coons曲線(初速終速0 一時停止後move_v,move_rad使用)
void EnemyMovePattern_09(int index){
	enemy[index].trans_rad=enemy[index].staticData->move_rad;

	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;
		enemy[index].pos.x = 2.0*(enemy[index].staticData->startPos.x-enemy[index].staticData->stopPos.x)*t*t*t - 3.0*(enemy[index].staticData->startPos.x-enemy[index].staticData->stopPos.x)*t*t + enemy[index].staticData->startPos.x;
		enemy[index].pos.y = 2.0*(enemy[index].staticData->startPos.y-enemy[index].staticData->stopPos.y)*t*t*t - 3.0*(enemy[index].staticData->startPos.y-enemy[index].staticData->stopPos.y)*t*t + enemy[index].staticData->startPos.y;
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//Catmull Rom spline曲線(制御点(-400,FIELD_SIZE_HEIGHT+400),(FIELD_SIZE_WIDTH+400,FIELD_SIZE_HEIGHT+400) 一時停止後move_v,move_rad使用)
void EnemyMovePattern_10(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		Position v0,v1,p0,p1;
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;

		v0 = GetPositionFromXY((enemy[index].staticData->stopPos.x-(-400.0))/2,(enemy[index].staticData->stopPos.y-(FIELD_SIZE_HEIGHT+400.0))/2);
		v1 = GetPositionFromXY((FIELD_SIZE_WIDTH+400.0-enemy[index].staticData->startPos.x)/2,(FIELD_SIZE_HEIGHT+400.0-enemy[index].staticData->startPos.y)/2);
		p0 = enemy[index].staticData->startPos;
		p1 = enemy[index].staticData->stopPos;

		enemy[index].pos.x = (2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t*t + (-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t*t + v0.x*t + p0.x;
		enemy[index].pos.y = (2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t*t + (-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t*t + v0.y*t + p0.y;

		double dx,dy;
		dx = 3.0*(2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t + 2.0*(-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t +v0.x;
		dy = 3.0*(2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t + 2.0*(-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t +v0.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad=enemy[index].staticData->move_rad;
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//Catmull Rom spline曲線(制御点(-400,-400),(FIELD_SIZE_WIDTH+400,-400) 一時停止後move_v,move_rad使用)
void EnemyMovePattern_11(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		Position v0,v1,p0,p1;
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;

		v0 = GetPositionFromXY((enemy[index].staticData->stopPos.x-(-400.0))/2,(enemy[index].staticData->stopPos.y-(-400.0))/2);
		v1 = GetPositionFromXY((FIELD_SIZE_WIDTH+400.0-enemy[index].staticData->startPos.x)/2,(-400.0-enemy[index].staticData->startPos.y)/2);
		p0 = enemy[index].staticData->startPos;
		p1 = enemy[index].staticData->stopPos;

		enemy[index].pos.x = (2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t*t + (-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t*t + v0.x*t + p0.x;
		enemy[index].pos.y = (2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t*t + (-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t*t + v0.y*t + p0.y;

		double dx,dy;
		dx = 3.0*(2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t + 2.0*(-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t +v0.x;
		dy = 3.0*(2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t + 2.0*(-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t +v0.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad=enemy[index].staticData->move_rad;
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//Catmull Rom spline曲線(制御点(-400,-400),(FIELD_SIZE_WIDTH+400,FIELD_SIZE_HEIGHT+400) 一時停止後move_v,move_rad使用)
void EnemyMovePattern_12(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		Position v0,v1,p0,p1;
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;

		v0 = GetPositionFromXY((enemy[index].staticData->stopPos.x-(-400.0))/2,(enemy[index].staticData->stopPos.y-(-400.0))/2);
		v1 = GetPositionFromXY((FIELD_SIZE_WIDTH+400.0-enemy[index].staticData->startPos.x)/2,(FIELD_SIZE_HEIGHT+400.0-enemy[index].staticData->startPos.y)/2);
		p0 = enemy[index].staticData->startPos;
		p1 = enemy[index].staticData->stopPos;

		enemy[index].pos.x = (2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t*t + (-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t*t + v0.x*t + p0.x;
		enemy[index].pos.y = (2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t*t + (-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t*t + v0.y*t + p0.y;

		double dx,dy;
		dx = 3.0*(2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t + 2.0*(-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t +v0.x;
		dy = 3.0*(2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t + 2.0*(-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t +v0.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad=enemy[index].staticData->move_rad;
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//Catmull Rom spline曲線(制御点(-400,FIELD_SIZE_HEIGHT+400),(-400,FIELD_SIZE_HEIGHT+400) 一時停止後move_v,move_rad使用)
void EnemyMovePattern_13(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		Position v0,v1,p0,p1;
		double t = (double)enemy[index].c/enemy[index].staticData->move_bet_time;

		v0 = GetPositionFromXY((enemy[index].staticData->stopPos.x-(-400.0))/2,(enemy[index].staticData->stopPos.y-(FIELD_SIZE_HEIGHT+400.0))/2);
		v1 = GetPositionFromXY((400.0-enemy[index].staticData->startPos.x)/2,(FIELD_SIZE_HEIGHT+400.0-enemy[index].staticData->startPos.y)/2);
		p0 = enemy[index].staticData->startPos;
		p1 = enemy[index].staticData->stopPos;

		enemy[index].pos.x = (2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t*t + (-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t*t + v0.x*t + p0.x;
		enemy[index].pos.y = (2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t*t + (-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t*t + v0.y*t + p0.y;

		double dx,dy;
		dx = 3.0*(2.0*p0.x - 2.0*p1.x + v0.x + v1.x)*t*t + 2.0*(-3.0*p0.x + 3.0*p1.x - 2.0*v0.x - v1.x)*t +v0.x;
		dy = 3.0*(2.0*p0.y - 2.0*p1.y + v0.y + v1.y)*t*t + 2.0*(-3.0*p0.y + 3.0*p1.y - 2.0*v0.y - v1.y)*t +v0.y;
		enemy[index].trans_rad = atan2(dy,dx);
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else{
		enemy[index].trans_rad=enemy[index].staticData->move_rad;
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
}

//等速1/4円運動時計回り(stopPos_xには半径rを、stopPos_yには0を入れておく。stopPos_yはrot_radとして使う。moveBetTimeが過ぎてから回転を始め、rot_radがM_PI/2を超えたら終わる。)
void EnemyMovePattern_14(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
	else{
		if(enemy[index].staticData->stopPos.y>M_PI/2){
			enemy[index].trans_rad = enemy[index].staticData->move_rad+M_PI/2;
			enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].trans_rad);
			enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].trans_rad);
		}
		else{
			double w = enemy[index].staticData->move_v/enemy[index].staticData->stopPos.x;
			enemy[index].trans_rad+=w;
			enemy[index].staticData->stopPos.y+=w;

			enemy[index].pos.x -= enemy[index].staticData->stopPos.x*w*sin(enemy[index].trans_rad-M_PI/2);
			enemy[index].pos.y += enemy[index].staticData->stopPos.x*w*cos(enemy[index].trans_rad-M_PI/2);
		}
	}
}

//等速1/4円運動反時計回り(stopPos_xには半径rを、stopPos_yには0を入れておく。stopPos_yはrot_radとして使う。moveBetTimeが過ぎてから回転を始め、rot_radがM_PI/2を超えたら終わる。)
void EnemyMovePattern_15(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
	else{
		if(enemy[index].staticData->stopPos.y>M_PI/2){
			enemy[index].trans_rad = enemy[index].staticData->move_rad-M_PI/2;
			enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].trans_rad);
			enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].trans_rad);
		}
		else{
			double w = enemy[index].staticData->move_v/enemy[index].staticData->stopPos.x;
			enemy[index].trans_rad-=w;
			enemy[index].staticData->stopPos.y+=w;

			enemy[index].pos.x -= enemy[index].staticData->stopPos.x*w*sin(enemy[index].trans_rad-M_PI/2);
			enemy[index].pos.y += enemy[index].staticData->stopPos.x*w*cos(enemy[index].trans_rad-M_PI/2);
		}
	}
}

//等速1/8円運動時計回り(stopPos_xには半径rを、stopPos_yには0を入れておく。stopPos_yはrot_radとして使う。moveBetTimeが過ぎてから回転を始め、rot_radがM_PI/4を超えたら終わる。)
void EnemyMovePattern_16(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
	else{
		if(enemy[index].staticData->stopPos.y>M_PI/4){
			enemy[index].trans_rad = enemy[index].staticData->move_rad+M_PI/4;
			enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].trans_rad);
			enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].trans_rad);
		}
		else{
			double w = enemy[index].staticData->move_v/enemy[index].staticData->stopPos.x;
			enemy[index].trans_rad+=w;
			enemy[index].staticData->stopPos.y+=w;

			enemy[index].pos.x -= enemy[index].staticData->stopPos.x*w*sin(enemy[index].trans_rad-M_PI/2);
			enemy[index].pos.y += enemy[index].staticData->stopPos.x*w*cos(enemy[index].trans_rad-M_PI/2);
		}
	}
}

//等速1/8円運動反時計回り(stopPos_xには半径rを、stopPos_yには0を入れておく。stopPos_yはrot_radとして使う。moveBetTimeが過ぎてから回転を始め、rot_radがM_PI/4を超えたら終わる。)
void EnemyMovePattern_17(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
	else{
		if(enemy[index].staticData->stopPos.y>M_PI/4){
			enemy[index].trans_rad = enemy[index].staticData->move_rad-M_PI/4;
			enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].trans_rad);
			enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].trans_rad);
		}
		else{
			double w = enemy[index].staticData->move_v/enemy[index].staticData->stopPos.x;
			enemy[index].trans_rad-=w;
			enemy[index].staticData->stopPos.y+=w;

			enemy[index].pos.x -= enemy[index].staticData->stopPos.x*w*sin(enemy[index].trans_rad-M_PI/2);
			enemy[index].pos.y += enemy[index].staticData->stopPos.x*w*cos(enemy[index].trans_rad-M_PI/2);
		}
	}
}

//等速1/2円運動時計回り(stopPos_xには半径rを、stopPos_yには0を入れておく。stopPos_yはrot_radとして使う。moveBetTimeが過ぎてから回転を始め、rot_radがM_PI/4を超えたら終わる。)
void EnemyMovePattern_18(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
	else{
		if(enemy[index].staticData->stopPos.y>M_PI){
			enemy[index].trans_rad = enemy[index].staticData->move_rad+M_PI;
			enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].trans_rad);
			enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].trans_rad);
		}
		else{
			double w = enemy[index].staticData->move_v/enemy[index].staticData->stopPos.x;
			enemy[index].trans_rad+=w;
			enemy[index].staticData->stopPos.y+=w;

			enemy[index].pos.x -= enemy[index].staticData->stopPos.x*w*sin(enemy[index].trans_rad-M_PI/2);
			enemy[index].pos.y += enemy[index].staticData->stopPos.x*w*cos(enemy[index].trans_rad-M_PI/2);
		}
	}
}

//等速1/2円運動反時計回り(stopPos_xには半径rを、stopPos_yには0を入れておく。stopPos_yはrot_radとして使う。moveBetTimeが過ぎてから回転を始め、rot_radがM_PI/4を超えたら終わる。)
void EnemyMovePattern_19(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].staticData->move_rad);
		enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].staticData->move_rad);
	}
	else{
		if(enemy[index].staticData->stopPos.y>M_PI){
			enemy[index].trans_rad = enemy[index].staticData->move_rad-M_PI;
			enemy[index].pos.x+=enemy[index].staticData->move_v*cos(enemy[index].trans_rad);
			enemy[index].pos.y+=enemy[index].staticData->move_v*sin(enemy[index].trans_rad);
		}
		else{
			double w = enemy[index].staticData->move_v/enemy[index].staticData->stopPos.x;
			enemy[index].trans_rad-=w;
			enemy[index].staticData->stopPos.y+=w;

			enemy[index].pos.x -= enemy[index].staticData->stopPos.x*w*sin(enemy[index].trans_rad-M_PI/2);
			enemy[index].pos.y += enemy[index].staticData->stopPos.x*w*cos(enemy[index].trans_rad-M_PI/2);
		}
	}
}

//加速度直進(stopPos,moveBetTime使用 一時停止後自機へ)
void EnemyMovePattern_20(int index){
	if(enemy[index].c <= enemy[index].staticData->move_bet_time){
		double dx=enemy[index].staticData->stopPos.x-enemy[index].staticData->startPos.x,dy=enemy[index].staticData->stopPos.y-enemy[index].staticData->startPos.y;
		enemy[index].trans_rad = atan2(dy,dx);

		enemy[index].pos.x = enemy[index].staticData->startPos.x + 2.0*dx*enemy[index].c/enemy[index].staticData->move_bet_time - dx*enemy[index].c*enemy[index].c/enemy[index].staticData->move_bet_time/enemy[index].staticData->move_bet_time;
		enemy[index].pos.y = enemy[index].staticData->startPos.y + 2.0*dy*enemy[index].c/enemy[index].staticData->move_bet_time - dy*enemy[index].c*enemy[index].c/enemy[index].staticData->move_bet_time/enemy[index].staticData->move_bet_time;
	}
	else if(enemy[index].c < enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = M_PI/2;
	}
	else if(enemy[index].c == enemy[index].staticData->move_bet_time+enemy[index].staticData->wait_time){
		enemy[index].trans_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-enemy[index].pos.y-ENEMY_HEIGHT/2,player.pos.x+PLAYER_WIDTH/2-enemy[index].pos.x-ENEMY_WIDTH/2);
	}
	else{
		enemy[index].pos.x += enemy[index].staticData->move_v*cos(enemy[index].trans_rad);
		enemy[index].pos.y += enemy[index].staticData->move_v*sin(enemy[index].trans_rad);
	}
}


void(*EnemyMovePattern[])(int)={
	EnemyMovePattern_00,
	EnemyMovePattern_01,
	EnemyMovePattern_02,
	EnemyMovePattern_03,
	EnemyMovePattern_04,
	EnemyMovePattern_05,
	EnemyMovePattern_06,
	EnemyMovePattern_07,
	EnemyMovePattern_08,
	EnemyMovePattern_09,
	EnemyMovePattern_10,
	EnemyMovePattern_11,
	EnemyMovePattern_12,
	EnemyMovePattern_13,
	EnemyMovePattern_14,
	EnemyMovePattern_15,
	EnemyMovePattern_16,
	EnemyMovePattern_17,
	EnemyMovePattern_18,
	EnemyMovePattern_19,
	EnemyMovePattern_20
};



bool EnemyIsVissible(int index){
	if(enemy[index].c<100)return true;

	if((enemy[index].pos.x+ENEMY_WIDTH>0)&&(enemy[index].pos.x<FIELD_SIZE_WIDTH)){
		if((enemy[index].pos.y+ENEMY_HEIGHT>0)&&(enemy[index].pos.y<FIELD_SIZE_HEIGHT)){
			return true;
		}
	}
	return false;
}

void EnemyUpdate(){
	EnemyAppearCheck();

	for(int i=0;i<ENEMY_MAX;i++){
		if(enemy[i].f==false)continue;

		enemy[i].c++;
		
		if(enemy[i].status==normal){
			if(enemy[i].c%12==0)enemy[i].chip_rad+=M_PI/2;
			enemy[i].f=EnemyIsVissible(i);

			EnemyMovePattern[enemy[i].staticData->movePattern](i);
			enemy[i].direction = GetDirectionFromRad(enemy[i].trans_rad);

			for(int j=0;j<3;j++){
				if(enemy[i].staticShotData[j]->attackPattern==-1)break;
				
				if(enemy[i].c==enemy[i].staticShotData[j]->shotStartTime){
					En_BarrageSet(enemy[i].staticShotData[j],i);
				}
			}

			if(enemy[i].HP<0){
				enemy[i].c=0;
				enemy[i].status=dead;
				ItemSet(enemy[i].pos,enemy[i].staticData->itemDropPattern);
			}
		}

		if(enemy[i].status==dead){
			if(enemy[i].c>=90)enemy[i].f=false;
		}
	}
}

void EnemyDraw(){
	for(int i=0;i<ENEMY_MAX;i++){
		if(enemy[i].f==false)continue;

		if(enemy[i].status==normal){
			DrawGraph(FIELD_OFFSET_X+Round(enemy[i].pos.x),FIELD_OFFSET_Y+Round(enemy[i].pos.y),gameData.chip.enemy[enemy[i].staticData->charaKind][3*enemy[i].direction+1+Round(sin(enemy[i].chip_rad))],true);
		}
		if(enemy[i].status==dead){
			DrawGraph(FIELD_OFFSET_X+Round(enemy[i].pos.x)-(EXPLODE_WIDTH-ENEMY_WIDTH)/2,FIELD_OFFSET_Y+Round(enemy[i].pos.y)-(EXPLODE_HEIGHT-ENEMY_HEIGHT)/2,gameData.chip.explode[(enemy[i].c-enemy[i].c%6)/6],true);
		}

	}
}

void EnemyInit(){
	for(int i=0;i<ENEMY_MAX;i++){
		enemy[i].f=false;
	}
}