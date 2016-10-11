#include"common.h"


void GameMusicLoad(){
	GGS4AddListFromFileA("dat\\mid\\r1.mid",GGSLOAD_BUFFERED,m_st1);
	GGS4AddListFromFileA("dat\\mid\\r2.mid",GGSLOAD_BUFFERED,m_st2);
	GGS4AddListFromFileA("dat\\mid\\r3.mid",GGSLOAD_BUFFERED,m_st3);
	GGS4AddListFromFileA("dat\\mid\\r4.mid",GGSLOAD_BUFFERED,m_st4);
	GGS4AddListFromFileA("dat\\mid\\b1.mid",GGSLOAD_BUFFERED,m_st1_b);
	GGS4AddListFromFileA("dat\\mid\\b2.mid",GGSLOAD_BUFFERED,m_st2_b);
	GGS4AddListFromFileA("dat\\mid\\b3.mid",GGSLOAD_BUFFERED,m_st3_b);
	GGS4AddListFromFileA("dat\\mid\\b4.mid",GGSLOAD_BUFFERED,m_st4_b);
}

void GameMusicPlay(MusicList index){
	GGS4Play(GGSPLAY_LOOP,index,0,0,0);
}

void GameSELoad(){

}

void GamePictureLoad(){
	LoadDivGraph("dat\\pic\\back.png",4,4,1,FIELD_SIZE_WIDTH,FIELD_SIZE_HEIGHT,gameData.chip.back);
	gameData.chip.board[0]=LoadGraph("dat\\pic\\board_down.png");
	gameData.chip.board[1]=LoadGraph("dat\\pic\\board_left.png");
	gameData.chip.board[2]=LoadGraph("dat\\pic\\board_right.png");
	gameData.chip.board[3]=LoadGraph("dat\\pic\\board_up.png");
	
	int temp[22];
	LoadDivGraph("dat\\pic\\enemy.png",22,22,1,96,256,temp);
	for(int i=0;i<22;i++){
		for(int j=0;j<24;j++){
			gameData.chip.enemy[i][j] = DerivationGraph(ENEMY_WIDTH*(j%3),ENEMY_HEIGHT*(j-(j%3))/3,ENEMY_WIDTH,ENEMY_HEIGHT,temp[i]);
		}
	}

	LoadDivGraph("dat\\pic\\eb_small.png",8,8,1,12,12,gameData.chip.e_bullet[eb_small]);
	LoadDivGraph("dat\\pic\\eb_middle.png",8,8,1,30,30,gameData.chip.e_bullet[eb_middle]);
	LoadDivGraph("dat\\pic\\eb_large.png",8,8,1,64,64,gameData.chip.e_bullet[eb_large]);
	LoadDivGraph("dat\\pic\\eb_crystal.png",8,8,1,11,19,gameData.chip.e_bullet[eb_crystal]);
	LoadDivGraph("dat\\pic\\eb_fuda.png",8,8,1,18,20,gameData.chip.e_bullet[eb_fuda]);
	LoadDivGraph("dat\\pic\\eb_gun.png",8,8,1,11,19,gameData.chip.e_bullet[eb_gun]);
	LoadDivGraph("dat\\pic\\eb_knife.png",8,8,1,17,15,gameData.chip.e_bullet[eb_knife]);
	LoadDivGraph("dat\\pic\\eb_kunai.png",8,8,1,13,22,gameData.chip.e_bullet[eb_kunai]);
	LoadDivGraph("dat\\pic\\eb_money.png",8,8,1,19,18,gameData.chip.e_bullet[eb_money]);
	LoadDivGraph("dat\\pic\\eb_niddle.png",8,8,1,6,14,gameData.chip.e_bullet[eb_niddle]);
	LoadDivGraph("dat\\pic\\eb_oval.png",8,8,1,20,38,gameData.chip.e_bullet[eb_oval]);
	LoadDivGraph("dat\\pic\\eb_snow.png",8,8,1,16,16,gameData.chip.e_bullet[eb_snow]);
	LoadDivGraph("dat\\pic\\eb_star_s.png",8,8,1,20,20,gameData.chip.e_bullet[eb_star_s]);
	LoadDivGraph("dat\\pic\\eb_star_l.png",8,8,1,32,32,gameData.chip.e_bullet[eb_star_l]);
	LoadDivGraph("dat\\pic\\eb_lazer.png",8,8,1,18,28,gameData.chip.e_bullet[eb_lazer]);


	gameData.chip.e_spell = LoadGraph("dat\\pic\\e_spell.png");
	gameData.chip.pl_subwep = LoadGraph("dat\\pic\\pl_subwep.png");
	gameData.chip.boss_lifeBar = LoadGraph("dat\\pic\\life_bar.png");

	LoadDivGraph("dat\\pic\\item_l.png",4,4,1,12,12,gameData.chip.item[1]);
	LoadDivGraph("dat\\pic\\item_s.png",4,4,1,8,8,gameData.chip.item[0]);

	LoadDivGraph("dat\\pic\\explode.png",15,5,3,48,48,gameData.chip.explode);

	LoadDivGraph("dat\\pic\\player.png",3,3,1,32,32,gameData.chip.player);
	gameData.chip.pl_bomb = LoadGraph("dat\\pic\\pl_bomb.png");
	LoadDivGraph("dat\\pic\\pl_status.png",3,3,1,32,32,gameData.chip.pl_status);
}

Size TransformToSize(int width,int height){
	Size size;
	size.width=width;
	size.height=height;

	return size;
}

void SetEnemyBulletSize(){
	gameData.eb_size[eb_small] = TransformToSize(12,12);
	gameData.eb_size[eb_middle] = TransformToSize(30,30);
	gameData.eb_size[eb_large] = TransformToSize(64,64);
	gameData.eb_size[eb_crystal] = TransformToSize(11,19);
	gameData.eb_size[eb_fuda] = TransformToSize(18,20);
	gameData.eb_size[eb_gun] = TransformToSize(11,19);
	gameData.eb_size[eb_knife] = TransformToSize(17,15);
	gameData.eb_size[eb_kunai] = TransformToSize(13,22);
	gameData.eb_size[eb_money] = TransformToSize(19,18);
	gameData.eb_size[eb_niddle] = TransformToSize(6,14);
	gameData.eb_size[eb_oval] = TransformToSize(20,38);
	gameData.eb_size[eb_snow] = TransformToSize(16,16);
	gameData.eb_size[eb_star_s] = TransformToSize(20,20);
	gameData.eb_size[eb_star_l] = TransformToSize(32,32);
	gameData.eb_size[eb_lazer] = TransformToSize(18,28);
}

void SetCSVDataToStatics(int index_x,int index_y,char* input){
	gameData.stageData.enemyData[index_y].validable=true;

	switch(index_x){
	case 0:gameData.stageData.enemyData[index_y].appearTime				= atoi(input);
	case 1:gameData.stageData.enemyData[index_y].startPos.x				= (double)atoi(input);
	case 2:gameData.stageData.enemyData[index_y].startPos.y				= (double)atoi(input);
	case 3:gameData.stageData.enemyData[index_y].stopPos.x				= (double)atoi(input);
	case 4:gameData.stageData.enemyData[index_y].stopPos.y				= (double)atoi(input);
	case 5:gameData.stageData.enemyData[index_y].movePattern			= atoi(input);
	case 6:gameData.stageData.enemyData[index_y].charaKind				= atoi(input);
	case 7:gameData.stageData.enemyData[index_y].HP_MAX					= atoi(input);
	case 8:gameData.stageData.enemyData[index_y].move_v					= atof(input);
	case 9:gameData.stageData.enemyData[index_y].move_rad				= M_PI*2*atoi(input)/360;
	case 10:gameData.stageData.enemyData[index_y].move_bet_time			= atoi(input);
	case 11:gameData.stageData.enemyData[index_y].wait_time				= atoi(input);
	case 12:gameData.stageData.enemyData[index_y].itemDropPattern		= atoi(input);
	case 13:gameData.stageData.enemyShotData[index_y][0].attackPattern			= atoi(input);
	case 14:gameData.stageData.enemyShotData[index_y][0].shot_v					= atof(input);
	case 15:gameData.stageData.enemyShotData[index_y][0].shot_rad				= M_PI*2*atoi(input)/360;
	case 16:gameData.stageData.enemyShotData[index_y][0].shot_kind				= (En_BulletKind)atoi(input);
	case 17:gameData.stageData.enemyShotData[index_y][0].shot_bul_color			= (Bul_Color)atoi(input);
	case 18:gameData.stageData.enemyShotData[index_y][0].shotMovePattern		= atoi(input);
	case 19:gameData.stageData.enemyShotData[index_y][0].shotStartTime			= atoi(input);
	case 20:gameData.stageData.enemyShotData[index_y][0].small_group_num		= atoi(input);
	case 21:gameData.stageData.enemyShotData[index_y][0].small_group_bet_time	= atoi(input);
	case 22:gameData.stageData.enemyShotData[index_y][0].large_group_num		= atoi(input);
	case 23:gameData.stageData.enemyShotData[index_y][0].large_group_bet_time	= atoi(input);
	case 24:gameData.stageData.enemyShotData[index_y][0].total_group_num		= atoi(input);
	case 25:gameData.stageData.enemyShotData[index_y][0].param1					= atof(input);
	case 26:gameData.stageData.enemyShotData[index_y][0].param2					= atof(input);
	case 27:gameData.stageData.enemyShotData[index_y][1].attackPattern			= atoi(input);
	case 28:gameData.stageData.enemyShotData[index_y][1].shot_v					= atof(input);
	case 29:gameData.stageData.enemyShotData[index_y][1].shot_rad				= M_PI*2*atoi(input)/360;
	case 30:gameData.stageData.enemyShotData[index_y][1].shot_kind				= (En_BulletKind)atoi(input);
	case 31:gameData.stageData.enemyShotData[index_y][1].shot_bul_color			= (Bul_Color)atoi(input);
	case 32:gameData.stageData.enemyShotData[index_y][1].shotMovePattern		= atoi(input);
	case 33:gameData.stageData.enemyShotData[index_y][1].shotStartTime			= atoi(input);
	case 34:gameData.stageData.enemyShotData[index_y][1].small_group_num		= atoi(input);
	case 35:gameData.stageData.enemyShotData[index_y][1].small_group_bet_time	= atoi(input);
	case 36:gameData.stageData.enemyShotData[index_y][1].large_group_num		= atoi(input);
	case 37:gameData.stageData.enemyShotData[index_y][1].large_group_bet_time	= atoi(input);
	case 38:gameData.stageData.enemyShotData[index_y][1].total_group_num		= atoi(input);
	case 39:gameData.stageData.enemyShotData[index_y][1].param1					= atof(input);
	case 40:gameData.stageData.enemyShotData[index_y][1].param2					= atof(input);
	case 41:gameData.stageData.enemyShotData[index_y][2].attackPattern			= atoi(input);
	case 42:gameData.stageData.enemyShotData[index_y][2].shot_v					= atof(input);
	case 43:gameData.stageData.enemyShotData[index_y][2].shot_rad				= M_PI*2*atoi(input)/360;
	case 44:gameData.stageData.enemyShotData[index_y][2].shot_kind				= (En_BulletKind)atoi(input);
	case 45:gameData.stageData.enemyShotData[index_y][2].shot_bul_color			= (Bul_Color)atoi(input);
	case 46:gameData.stageData.enemyShotData[index_y][2].shotMovePattern		= atoi(input);
	case 47:gameData.stageData.enemyShotData[index_y][2].shotStartTime			= atoi(input);
	case 48:gameData.stageData.enemyShotData[index_y][2].small_group_num		= atoi(input);
	case 49:gameData.stageData.enemyShotData[index_y][2].small_group_bet_time	= atoi(input);
	case 50:gameData.stageData.enemyShotData[index_y][2].large_group_num		= atoi(input);
	case 51:gameData.stageData.enemyShotData[index_y][2].large_group_bet_time	= atoi(input);
	case 52:gameData.stageData.enemyShotData[index_y][2].total_group_num		= atoi(input);
	case 53:gameData.stageData.enemyShotData[index_y][2].param1					= atof(input);
	case 54:gameData.stageData.enemyShotData[index_y][2].param2					= atof(input);
	}
}

Position GetPositionFromXY(double x,double y){
	Position pos;
	pos.x=x;
	pos.y=y;
	return pos;
}

Position GetPosAdd(Position pos,double x,double y){
	pos.x += x;
	pos.y += y;
	return pos;
}

void GetCSVEnemyData(int stage){
	char fname[16];
	sprintf_s(fname,"dat\\csv\\%d.csv",stage);

	for(int i=0;i<EN_ORDER_MAX;i++){
		gameData.stageData.enemyData[i].validable=false;
	}

	int fp = FileRead_open(fname);
	while(FileRead_getc(fp)!='\n');

	char input[8];
	int index_x=0,index_y=0;

	for(int i=0;i<8;i++){
		input[i]=FileRead_getc(fp);
		if(input[i]==','){
			input[i]='\0';

			SetCSVDataToStatics(index_x,index_y,input);

			i=-1;
			index_x++;
			continue;
		}
		if(input[i]=='\n'){
			input[i]='\0';

			SetCSVDataToStatics(index_x,index_y,input);

			i=-1;
			index_x=0;
			index_y++;
			continue;
		}
		if(input[i]==EOF)break;
	}

	FileRead_close(fp);
}

void GoToNextStage(){
	gameData.stageData.backScroll_y=0;
	gameData.stageData.c=0;
	gameData.stageData.stage++;
	GetCSVEnemyData(gameData.stageData.stage);
	GameMusicPlay((MusicList)(gameData.stageData.stage*2-2));
}

void GameEnemyDataLoad(){
	SetEnemyBulletSize();
	GetCSVEnemyData(1);
}

void GameDataInit(){
	stageDataInit();
	PlayerInit();
	Pl_BulletInit();
	Pl_SubWeaponInit();
	Pl_BombInit();
	EnemyInit();
	En_BulletInit();
	En_BarrageInit();
}

void GameInit(){
	GameMusicLoad();
	GameSELoad();
	GamePictureLoad();
	GameEnemyDataLoad();
	GameDataInit();
	gameData.bossTotalAttack_c=	0;
}