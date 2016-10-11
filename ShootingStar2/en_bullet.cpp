#include"common.h"


int GetEmptyBulletIndex(){
	for(int i=0;i<EN_BULLET_MAX;i++){
		if(en_bullet[i].f==false)return i;
	}
	return -1;
}

void En_BulletSet(Position pos,double v,double trans_rad,Bul_Color color,En_BulletKind kind,int movePattern,int e_index,double param1,double param2){
	int index=GetEmptyBulletIndex();
	if(index==-1)return;

	en_bullet[index].c=0;
	en_bullet[index].f=true;
	en_bullet[index].pos=pos;
	en_bullet[index].v=v;
	en_bullet[index].trans_rad=trans_rad;
	en_bullet[index].color=color;
	en_bullet[index].kind=kind;
	en_bullet[index].movePattern=movePattern;
	en_bullet[index].shot_e_index=e_index;
	en_bullet[index].param1=param1;
	en_bullet[index].param2=param2;
}


//’¼i
void En_BulletMovePattern_00(int index){
	en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
	en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
}

//‰ÁŒ¸‘¬’¼i(param2‚É‰Á‘¬“x)
void En_BulletMovePattern_01(int index){
	en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
	en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
	en_bullet[index].v += en_bullet[index].param2;
}

//Ž©‹@‘_‚¢‚É•Ï‰»(palam2‚ªØ‚è‘Ö‚í‚éŽžŠÔ)
void En_BulletMovePattern_02(int index){
	if(en_bullet[index].c==(int)en_bullet[index].param2){
		en_bullet[index].trans_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-en_bullet[index].pos.y,player.pos.x+PLAYER_WIDTH/2-en_bullet[index].pos.x);
	}
	else if((en_bullet[index].c>(int)en_bullet[index].param2)&&(en_bullet[index].c<=(int)en_bullet[index].param2+5)){

	}
	else{
		en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
		en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
	}
}

//d—Í‰Á‘¬“x‚ð“±“ü(palam2‚ªd—Í‰Á‘¬“x)
void En_BulletMovePattern_03(int index){
	double vx,vy;
	vx = en_bullet[index].v*cos(en_bullet[index].trans_rad);
	vy = en_bullet[index].v*sin(en_bullet[index].trans_rad);
	en_bullet[index].pos.x += vx;
	en_bullet[index].pos.y += vy;
	vy += en_bullet[index].param2;
	en_bullet[index].trans_rad = atan2(vy,vx);
}

/////////////////////////////////////////////////////////////
//«ƒ{ƒX—p

//stage1-1 barrage0—p barrage.c‚ªŽžŠÔ‚É‚È‚Á‚½‚ç’e‚ðƒXƒgƒbƒv
void En_BulletMovePattern_04(int index){
	int t=bo_barrage[en_bullet[index].shot_e_index].c%bo_barrage[en_bullet[index].shot_e_index].staticData->whole_time;

	if(t<bo_barrage[en_bullet[index].shot_e_index].staticData->small_group_bet_time*bo_barrage[en_bullet[index].shot_e_index].staticData->large_group_num+10){
		en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
		en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
	}
	else if(t==bo_barrage[en_bullet[index].shot_e_index].staticData->small_group_bet_time*bo_barrage[en_bullet[index].shot_e_index].staticData->large_group_num+10){
		en_bullet[index].color=bul_white;
		en_bullet[index].trans_rad=M_PI*2*GetRand(3600)/3600;
		en_bullet[index].v=2.0;
	}
	else if(t<=bo_barrage[en_bullet[index].shot_e_index].staticData->small_group_bet_time*bo_barrage[en_bullet[index].shot_e_index].staticData->large_group_num+150){

	}
	else{
		en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
		en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
	}
}

//stage1-3 barrage0—p “r’†‚Å’e‚ª‰ñ“]‰^“® param1‚ªŠp‘¬“xAparam2‚ªrot_rad
void En_BulletMovePattern_05(int index){
	en_bullet[index].pos.x += (en_bullet[index].v*cos(en_bullet[index].trans_rad) - bo_barrage[en_bullet[index].shot_e_index].staticData->param1*en_bullet[index].param1*sin(en_bullet[index].param2));
	en_bullet[index].pos.y += (en_bullet[index].v*sin(en_bullet[index].trans_rad) + bo_barrage[en_bullet[index].shot_e_index].staticData->param1*en_bullet[index].param1*cos(en_bullet[index].param2));
	en_bullet[index].param2 += en_bullet[index].param1;
}


//stage2-1 barrage1—p ŠgŽUŒ^‰~‰^“®
void En_BulletMovePattern_06(int index){
	double r = sqrt((boss.pos.x+ENEMY_WIDTH/2-en_bullet[index].pos.x)*(boss.pos.x+ENEMY_WIDTH/2-en_bullet[index].pos.x) + (boss.pos.y+ENEMY_HEIGHT/2-en_bullet[index].pos.y)*(boss.pos.y+ENEMY_HEIGHT/2-en_bullet[index].pos.y));
	en_bullet[index].pos.x+=(en_bullet[index].v*cos(en_bullet[index].trans_rad) - r*en_bullet[index].param1*sin(en_bullet[index].trans_rad));
	en_bullet[index].pos.y+=(en_bullet[index].v*sin(en_bullet[index].trans_rad) + r*en_bullet[index].param1*cos(en_bullet[index].trans_rad));
	en_bullet[index].trans_rad+=en_bullet[index].param1;
}


//stage2-3 barrage0 1—p
void En_BulletMovePattern_07(int index){
	if((en_bullet[index].v!=0.0)||(bo_barrage[en_bullet[index].shot_e_index].staticData->param3!=0.0)){
		en_bullet[index].v+=0.01;
		en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
		en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
	}
}


//stage2-4 barrage1—p
void En_BulletMovePattern_08(int index){
	en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
	en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
	en_bullet[index].v+=bo_barrage[en_bullet[index].shot_e_index].staticData->param2;
	if(en_bullet[index].c==160)en_bullet[index].color=bul_waterblue;
}


//stage 4-2 barrage1—p
void En_BulletMovePattern_09(int index){
	en_bullet[index].param2+=0.03;
	double vx = en_bullet[index].param1;
	double vy = en_bullet[index].param2;
	en_bullet[index].trans_rad=atan2(vy,vx);
	en_bullet[index].pos.x+=vx;
	en_bullet[index].pos.y+=vy;
}


//stage 4-3 barrage1—p //param1‚ÅˆÊ‘ŠŠp
void En_BulletMovePattern_10(int index){
	double vx = cos(en_bullet[index].trans_rad)*en_bullet[index].v - sin(en_bullet[index].trans_rad)*40.0*M_PI*2/180*cos(en_bullet[index].param1);
	double vy = sin(en_bullet[index].trans_rad)*en_bullet[index].v + cos(en_bullet[index].trans_rad)*40.0*M_PI*2/180*cos(en_bullet[index].param1);
	en_bullet[index].param1+=M_PI*2/180;

	en_bullet[index].pos.x+=vx;
	en_bullet[index].pos.y+=vy;
}


//stage 4-4 barrage1—p //
void En_BulletMovePattern_11(int index){
	if(en_bullet[index].c==50){
		en_bullet[index].trans_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-en_bullet[index].pos.y,player.pos.x+PLAYER_WIDTH/2-en_bullet[index].pos.x);
	}

	en_bullet[index].pos.x += en_bullet[index].v*cos(en_bullet[index].trans_rad);
	en_bullet[index].pos.y += en_bullet[index].v*sin(en_bullet[index].trans_rad);
}


//////////////////////////////////////////////////////////////

void(*En_BulletMovePattern[])(int)={
	En_BulletMovePattern_00,
	En_BulletMovePattern_01,
	En_BulletMovePattern_02,
	En_BulletMovePattern_03,
	En_BulletMovePattern_04,
	En_BulletMovePattern_05,
	En_BulletMovePattern_06,
	En_BulletMovePattern_07,
	En_BulletMovePattern_08,
	En_BulletMovePattern_09,
	En_BulletMovePattern_10,
	En_BulletMovePattern_11
};

bool En_BulletIsVisible(int index){
	if(en_bullet[index].c<20)return true;

	if((en_bullet[index].pos.x+gameData.eb_size[en_bullet[index].kind].width/2>0.0)&&(en_bullet[index].pos.x-gameData.eb_size[en_bullet[index].kind].width/2<(double)FIELD_SIZE_WIDTH)){
		if((en_bullet[index].pos.y+gameData.eb_size[en_bullet[index].kind].height/2>0.0)&&(en_bullet[index].pos.y-gameData.eb_size[en_bullet[index].kind].height/2<(double)FIELD_SIZE_HEIGHT)){
			return true;
		}
	}
	return false;
}

void En_BulletUpdate(){
	for(int i=0;i<EN_BULLET_MAX;i++){
		if(en_bullet[i].f==false)continue;

		en_bullet[i].c++;
		en_bullet[i].f=En_BulletIsVisible(i);

		En_BulletMovePattern[en_bullet[i].movePattern](i);
	}
}


void En_BulletDraw(){
	for(int i=0;i<EN_BULLET_MAX;i++){
		if(en_bullet[i].f==false) continue;

		SetDrawBlendMode(DX_BLENDMODE_ALPHA,230);
		DrawRotaGraph2(FIELD_OFFSET_X+Round(en_bullet[i].pos.x),FIELD_OFFSET_Y+Round(en_bullet[i].pos.y),gameData.eb_size[en_bullet[i].kind].width/2,gameData.eb_size[en_bullet[i].kind].height/2,
						1.0,en_bullet[i].trans_rad+M_PI/2,gameData.chip.e_bullet[en_bullet[i].kind][en_bullet[i].color],true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	}
}


void En_BulletInit(){
	for(int i=0;i<EN_BULLET_MAX;i++){
		en_bullet[i].f=false;
	}
}