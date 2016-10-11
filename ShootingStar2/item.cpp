#include"common.h"


int GetEmptyItemIndex(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].f==false)return i;
	}
	return -1;
}


//小power4つ
void ItemSetPattern_00(Position pos){
	int index;
	for(int i=0;i<4;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_power;
		item[index].size=item_small;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//小bomb4つ
void ItemSetPattern_01(Position pos){
	int index;
	for(int i=0;i<4;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_bomb;
		item[index].size=item_small;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//小score4つ
void ItemSetPattern_02(Position pos){
	int index;
	for(int i=0;i<4;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_score;
		item[index].size=item_small;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//小power3 小bomb2
void ItemSetPattern_03(Position pos){
	int index;
	for(int i=0;i<5;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=(ItemKind)(i%2);
		item[index].size=item_small;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//小power2 小bomb2 小score1
void ItemSetPattern_04(Position pos){
	int index;
	for(int i=0;i<5;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=(ItemKind)(i%3);
		item[index].size=item_small;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//大power2 小bomb2
void ItemSetPattern_05(Position pos){
	int index;
	for(int i=0;i<2;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_power;
		item[index].size=item_large;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
	for(int i=0;i<2;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_bomb;
		item[index].size=item_small;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//小power2 大bomb2
void ItemSetPattern_06(Position pos){
	int index;
	for(int i=0;i<2;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_bomb;
		item[index].size=item_large;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
	for(int i=0;i<2;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_power;
		item[index].size=item_small;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//小power1 小bomb1 大score2
void ItemSetPattern_07(Position pos){
	int index;

	index = GetEmptyItemIndex();
	item[index].f=true;
	item[index].c=0;
	item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
	item[index].v=-2.0-(double)GetRand(20)/10;
	item[index].kind=item_power;
	item[index].size=item_small;
	item[index].status=i_appearing;
	item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);

	index = GetEmptyItemIndex();
	item[index].f=true;
	item[index].c=0;
	item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
	item[index].v=-2.0-(double)GetRand(20)/10;
	item[index].kind=item_bomb;
	item[index].size=item_small;
	item[index].status=i_appearing;
	item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);

	for(int i=0;i<2;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_score;
		item[index].size=item_large;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//大power2 大bomb2
void ItemSetPattern_08(Position pos){
	int index;
	for(int i=0;i<4;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=(ItemKind)(i%2);
		item[index].size=item_large;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}

//大power30  大bomb15
void ItemSetPattern_09(Position pos){
	int index;
	for(int i=0;i<30;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_power;
		item[index].size=item_large;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
	for(int i=0;i<15;i++){
		index = GetEmptyItemIndex();

		item[index].f=true;
		item[index].c=0;
		item[index].trans_rad=M_PI*GetRand(150)/180+M_PI/6;
		item[index].v=-2.0-(double)GetRand(20)/10;
		item[index].kind=item_bomb;
		item[index].size=item_large;
		item[index].status=i_appearing;
		item[index].pos=GetPosAdd(pos,ENEMY_WIDTH/2,ENEMY_HEIGHT/2);
	}
}


void(*ItemSetPattern[])(Position)={
	ItemSetPattern_00,
	ItemSetPattern_01,
	ItemSetPattern_02,
	ItemSetPattern_03,
	ItemSetPattern_04,
	ItemSetPattern_05,
	ItemSetPattern_06,
	ItemSetPattern_07,
	ItemSetPattern_08,
	ItemSetPattern_09
};

void ItemSet(Position pos,int itemPattern){
	ItemSetPattern[itemPattern](pos);
}


//無敵時間中や画面上部に来たときなど、アイテムを自動回収するときに呼ぶ
void ItemSetToCollecting(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].f==false)continue;
		if(item[i].status!=i_normal) continue;

		item[i].c=0;
		item[i].status=i_collecting;
		item[i].v = sqrt((player.pos.x+PLAYER_WIDTH/2-item[i].pos.x)*(player.pos.x+PLAYER_WIDTH/2-item[i].pos.x)+(player.pos.y+PLAYER_HEIGHT/2-item[i].pos.y)*(player.pos.y+PLAYER_HEIGHT/2-item[i].pos.y))/20;
		item[i].trans_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-item[i].pos.y,player.pos.x+PLAYER_WIDTH/2-item[i].pos.x);
	}
}

//shiftキーで広範囲を集める。
void ItemSetToCollectingNear(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].f==false) continue;
		if(item[i].status!=i_normal) continue;

		if(((player.pos.x+PLAYER_WIDTH/2-item[i].pos.x)*(player.pos.x+PLAYER_WIDTH/2-item[i].pos.x) + (player.pos.y+PLAYER_HEIGHT/2-item[i].pos.y)*(player.pos.y+PLAYER_HEIGHT/2-item[i].pos.y)) < 4000){
			item[i].status=i_collecting_near;
		}
	}
}

void ItemMove(int index){
	item[index].pos.x += item[index].v*cos(item[index].trans_rad);
	item[index].pos.y += item[index].v*sin(item[index].trans_rad);
}

bool ItemIsVissible(int index){
	if(item[index].c<100)return true;

	if(item[index].size==item_small){
		if((item[index].pos.x-ITEM_S_WIDTH/2<FIELD_SIZE_WIDTH)&&(item[index].pos.x+ITEM_S_WIDTH/2>0)){
			if((item[index].pos.y-ITEM_S_HEIGHT/2<FIELD_SIZE_HEIGHT)&&(item[index].pos.y+ITEM_S_HEIGHT/2>0)){
				return true;
			}
		}
	}
	else{
		if((item[index].pos.x-ITEM_L_WIDTH/2<FIELD_SIZE_WIDTH)&&(item[index].pos.x+ITEM_L_WIDTH/2>0)){
			if((item[index].pos.y-ITEM_L_HEIGHT/2<FIELD_SIZE_HEIGHT)&&(item[index].pos.y+ITEM_L_HEIGHT/2>0)){
				return true;
			}
		}
	}
	return false;
}

void ItemUpdate(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].f==false)continue;

		item[i].c++;
		
		if(item[i].status==i_appearing){
			if(item[i].c==20)item[i].trans_rad=M_PI/2;
			if(item[i].c>=40)item[i].status=i_normal;
			item[i].v+=0.1;
		}
		else if(item[i].status==i_normal){
			item[i].v+=0.1;
			if(item[i].v>=1.5)item[i].v=1.5;
		}
		else if(item[i].status==i_collecting){
			item[i].trans_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-item[i].pos.y,player.pos.x+PLAYER_WIDTH/2-item[i].pos.x);
			item[i].v+=0.5;
		}
		else{
			item[i].trans_rad = atan2(player.pos.y+PLAYER_HEIGHT/2-item[i].pos.y,player.pos.x+PLAYER_WIDTH/2-item[i].pos.x);
			item[i].v+=1.0;
		}

		item[i].f = ItemIsVissible(i);
		ItemMove(i);
	}
}

void ItemDraw(){
	for(int i=0;i<ITEM_MAX;i++){
		if(item[i].f==false)continue;

		if(item[i].status==i_appearing){
			if(item[i].size==item_small){
				DrawRotaGraph2(FIELD_OFFSET_X+Round(item[i].pos.x),FIELD_OFFSET_Y+Round(item[i].pos.y),ITEM_S_WIDTH/2,ITEM_S_HEIGHT/2
														,1.0,M_PI/10*item[i].c,gameData.chip.item[item[i].size][item[i].kind],true);
			}
			else{
				DrawRotaGraph2(FIELD_OFFSET_X+Round(item[i].pos.x),FIELD_OFFSET_Y+Round(item[i].pos.y),ITEM_L_WIDTH/2,ITEM_L_HEIGHT/2
								,1.0,M_PI/10*item[i].c,gameData.chip.item[item[i].size][item[i].kind],true);
			}
		}
		else{
			if(item[i].size==item_small) DrawRotaGraph2(FIELD_OFFSET_X+Round(item[i].pos.x),FIELD_OFFSET_Y+Round(item[i].pos.y),ITEM_S_WIDTH/2,ITEM_S_HEIGHT/2
														,1.0,0.0,gameData.chip.item[item[i].size][item[i].kind],true);
			else DrawRotaGraph2(FIELD_OFFSET_X+Round(item[i].pos.x),FIELD_OFFSET_Y+Round(item[i].pos.y),ITEM_L_WIDTH/2,ITEM_L_HEIGHT/2
								,1.0,0.0,gameData.chip.item[item[i].size][item[i].kind],true);
		}
	}
}