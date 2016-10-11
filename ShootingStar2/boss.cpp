#include"common.h"

///////////////////////////////////////////////////////////////////

//stage1
void BossStaticMovePattern_00(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=200;
	boss.moveData.waitTime=200;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_01(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=200;
	boss.moveData.waitTime=200;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_02(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=200;
	boss.moveData.waitTime=200;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

//stage2
void BossStaticMovePattern_03(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=200;
	boss.moveData.waitTime=300;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_04(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=200;
	boss.moveData.waitTime=300;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_05(){
	boss.moveData.HP_MAX=12000;
	boss.moveData.movePattern=1;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_06(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=1;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

//stage3
void BossStaticMovePattern_07(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_08(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_09(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_10(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=200;
	boss.moveData.waitTime=300;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

//stage4
void BossStaticMovePattern_11(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=200;
	boss.moveData.waitTime=300;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_12(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=1;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_13(){
	boss.moveData.HP_MAX=8000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_14(){
	boss.moveData.HP_MAX=16000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}

void BossStaticMovePattern_15(){
	boss.moveData.HP_MAX=16000;
	boss.moveData.movePattern=0;
	boss.moveData.movingBetTime=100;
	boss.moveData.waitTime=100;
	boss.moveData.startPos=GetPositionFromXY(242.0,150.0);
	boss.moveData.itemDropPattern=0;
}


void(*BossStaticMovePattern[])()={
	BossStaticMovePattern_00,
	BossStaticMovePattern_01,
	BossStaticMovePattern_02,
	BossStaticMovePattern_03,
	BossStaticMovePattern_04,
	BossStaticMovePattern_05,
	BossStaticMovePattern_06,
	BossStaticMovePattern_07,
	BossStaticMovePattern_08,
	BossStaticMovePattern_09,
	BossStaticMovePattern_10,
	BossStaticMovePattern_11,
	BossStaticMovePattern_12,
	BossStaticMovePattern_13,
	BossStaticMovePattern_14,
	BossStaticMovePattern_15
};

//É{ÉXÇÃçUåÇñàÇ…åƒÇ‘ÅB
void GetBossStaticMoveData(){
	BossStaticMovePattern[gameData.bossTotalAttack_c]();
	boss.startPos=boss.pos;
	boss.stopPos=boss.moveData.startPos;
}
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//stage1

//ÉpÅ[ÉtÉFÉNÉgÉtÉäÅ[ÉY
void BossStaticShotPattern_00(){
	boss.barrageData[0].attackPattern=0;
	boss.barrageData[0].shot_v=5.0;
	//boss.barrageData[0].shot_trans_rad=random;
	boss.barrageData[0].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[0].shot_kind=eb_middle;
	//boss.barrageData[0].shot_bul_color=random;
	boss.barrageData[0].shotStartTime=200;
	boss.barrageData[0].shotMovePattern=4;
	boss.barrageData[0].small_group_num=3;
	boss.barrageData[0].small_group_bet_time=5;
	boss.barrageData[0].large_group_num=40;
	boss.barrageData[0].large_group_bet_time=200;
	boss.barrageData[0].whole_time=400;
	
	boss.barrageData[1].attackPattern=1;
	boss.barrageData[1].shot_v=6.0;
	boss.barrageData[1].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[1].shot_kind=eb_middle;
	boss.barrageData[1].shot_bul_color=bul_blue;
	boss.barrageData[1].shotStartTime=420;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=5;
	boss.barrageData[1].small_group_bet_time=10;
	boss.barrageData[1].large_group_num=5;
	boss.barrageData[1].large_group_bet_time=200;
	boss.barrageData[1].whole_time=400;

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

//Ç†Ç‚Ç‚í èÌíe
void BossStaticShotPattern_01(){
	boss.barrageData[0].attackPattern=2;
	boss.barrageData[0].shot_v=3.0;
	boss.barrageData[0].shot_trans_rad=M_PI*2*GetRand(3600)/3600;
	boss.barrageData[0].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[0].shot_kind=eb_middle;
	boss.barrageData[0].shot_bul_color=bul_red;
	boss.barrageData[0].shotStartTime=50;
	boss.barrageData[0].movePattern=0;
	boss.barrageData[0].small_group_num=3;
	boss.barrageData[0].small_group_bet_time=10;
	boss.barrageData[0].param1=20.0;//â~îºåa
	boss.barrageData[0].param2=M_PI*18.0/180;//âÒì]äpë¨ìx[deg]
	boss.barrageData[0].param3=6.0;//â~Çç\ê¨Ç∑ÇÈíeÇÃêî

	boss.barrageData[1].attackPattern=2;
	boss.barrageData[1].shot_v=4.0;
	boss.barrageData[1].shot_trans_rad=M_PI*2*GetRand(3600)/3600;
	boss.barrageData[1].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[1].shot_kind=eb_middle;
	boss.barrageData[1].shot_bul_color=bul_blue;
	boss.barrageData[1].shotStartTime=50;
	boss.barrageData[1].movePattern=0;
	boss.barrageData[1].small_group_num=2;
	boss.barrageData[1].small_group_bet_time=10;
	boss.barrageData[1].param1=20.0;//â~îºåa
	boss.barrageData[1].param2=-24.0*M_PI/180;//âÒì]äpë¨ìx[deg]
	boss.barrageData[1].param3=6.0;//â~Çç\ê¨Ç∑ÇÈíeÇÃêî

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

//Ç†Ç‚Ç‚í èÌàüéÌ
void BossStaticShotPattern_02(){
	boss.barrageData[0].attackPattern=3;
	boss.barrageData[0].shot_v=2.0;
	boss.barrageData[0].shot_trans_rad=M_PI*2*GetRand(3600)/3600;
	boss.barrageData[0].shot_rot_rad=M_PI/180;
	boss.barrageData[0].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[0].shot_kind=eb_small;
	boss.barrageData[0].shot_bul_color=bul_red;
	boss.barrageData[0].shotStartTime=30;
	boss.barrageData[0].shotMovePattern=5;
	boss.barrageData[0].small_group_num=4;
	boss.barrageData[0].small_group_bet_time=30;
	boss.barrageData[0].param1=50.0;//â~îºåa
	boss.barrageData[0].param2=M_PI*10.0/180;//âÒì]äpë¨ìx[deg]
	boss.barrageData[0].param3=8.0;//â~Çç\ê¨Ç∑ÇÈíeÇÃêî

	boss.barrageData[1].attackPattern=3;
	boss.barrageData[1].shot_v=3.0;
	boss.barrageData[1].shot_trans_rad=M_PI*2*GetRand(3600)/3600;
	boss.barrageData[1].shot_rot_rad=-M_PI/180;
	boss.barrageData[1].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[1].shot_kind=eb_small;
	boss.barrageData[1].shot_bul_color=bul_blue;
	boss.barrageData[1].shotStartTime=50;
	boss.barrageData[1].shotMovePattern=5;
	boss.barrageData[1].small_group_num=3;
	boss.barrageData[1].small_group_bet_time=20;
	boss.barrageData[1].param1=50.0;//â~îºåa
	boss.barrageData[1].param2=-16.0*M_PI/180;//âÒì]äpë¨ìx[deg]
	boss.barrageData[1].param3=8.0;//â~Çç\ê¨Ç∑ÇÈíeÇÃêî

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

//stage2
void BossStaticShotPattern_03(){
	boss.barrageData[0].attackPattern=4;
	boss.barrageData[0].shot_v=3.0;
	boss.barrageData[0].shot_trans_rad=0.0;
	boss.barrageData[0].shot_rot_rad=0.0;
	boss.barrageData[0].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[0].shot_kind=eb_crystal;
	//boss.barrageData[0].shot_bul_color=const;
	boss.barrageData[0].shotStartTime=5;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=7;
	boss.barrageData[0].small_group_bet_time=3;
	boss.barrageData[0].param1=M_PI*5/180;//rot_radÇÃäpë¨ìx
	boss.barrageData[0].param2=M_PI*8/180;//trans_radÇÃäpë¨ìx
	boss.barrageData[0].param3=100.0;//îºåa

	boss.barrageData[1].attackPattern=5;
	boss.barrageData[1].shot_v=2.0;
	boss.barrageData[1].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[1].shot_kind=eb_small;
	boss.barrageData[1].shot_bul_color=bul_white;
	boss.barrageData[1].shotStartTime=5;
	boss.barrageData[1].shotMovePattern=6;
	boss.barrageData[1].small_group_num=6;
	boss.barrageData[1].small_group_bet_time=100;
	boss.barrageData[1].param1=M_PI*0.2/180;//âÒì]äpë¨ìx

	boss.barrageData[2].attackPattern=5;
	boss.barrageData[2].shot_v=2.0;
	boss.barrageData[2].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[2].shot_kind=eb_small;
	boss.barrageData[2].shot_bul_color=bul_white;
	boss.barrageData[2].shotStartTime=5;
	boss.barrageData[2].shotMovePattern=6;
	boss.barrageData[2].small_group_num=6;
	boss.barrageData[2].small_group_bet_time=100;
	boss.barrageData[2].param1=-M_PI*0.2/180;//âÒì]äpë¨ìx

	for(int i=3;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_04(){
	boss.barrageData[0].attackPattern=6;
	boss.barrageData[0].shot_v=3.0;
	boss.barrageData[0].shot_rot_rad=0.0;
	boss.barrageData[0].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[0].shot_kind=eb_crystal;
	boss.barrageData[0].shot_bul_color=bul_red;
	boss.barrageData[0].shotStartTime=5;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=4;
	boss.barrageData[0].small_group_bet_time=2;
	boss.barrageData[0].param1=M_PI*11.2/180;//rot_radÇÃäpë¨ìx
	boss.barrageData[0].param2=10.0;//îºåa

	boss.barrageData[1].attackPattern=6;
	boss.barrageData[1].shot_v=3.0;
	boss.barrageData[1].shot_rot_rad=0.0;
	boss.barrageData[1].startPos=GetPosAdd(boss.pos,(double)ENEMY_WIDTH/2,(double)ENEMY_HEIGHT/2);
	boss.barrageData[1].shot_kind=eb_crystal;
	boss.barrageData[1].shot_bul_color=bul_waterblue;
	boss.barrageData[1].shotStartTime=5;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=4;
	boss.barrageData[1].small_group_bet_time=2;
	boss.barrageData[1].param1=-M_PI*11.2/180;//rot_radÇÃäpë¨ìx
	boss.barrageData[1].param2=10.0;//îºåa

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_05(){
	boss.barrageData[0].attackPattern=7;
	boss.barrageData[0].shot_v=0.0;
	boss.barrageData[0].shot_rot_rad=0.0;
	boss.barrageData[0].startPos=GetPositionFromXY(258.0,160.0);
	boss.barrageData[0].shot_kind=eb_kunai;
	boss.barrageData[0].shot_bul_color=bul_green;
	boss.barrageData[0].shotStartTime=10;
	boss.barrageData[0].shotMovePattern=7;
	boss.barrageData[0].small_group_num=1;
	boss.barrageData[0].small_group_bet_time=1;
	boss.barrageData[0].large_group_bet_time=5;
	boss.barrageData[0].param1=0.01;//cèâä˙íl
	boss.barrageData[0].param2=0.1;//cëùå∏ó 
	boss.barrageData[0].param3=0.0;//ÉtÉâÉO

	boss.barrageData[1].attackPattern=7;
	boss.barrageData[1].shot_v=0.0;
	boss.barrageData[1].shot_rot_rad=0.0;
	boss.barrageData[1].startPos=GetPositionFromXY(258.0,160.0);
	boss.barrageData[1].shot_kind=eb_kunai;
	boss.barrageData[1].shot_bul_color=bul_blue;
	boss.barrageData[1].shotStartTime=65;
	boss.barrageData[1].shotMovePattern=7;
	boss.barrageData[1].small_group_num=1;
	boss.barrageData[1].small_group_bet_time=1;
	boss.barrageData[1].large_group_bet_time=5;
	boss.barrageData[1].param1=0.99;//cèâä˙íl
	boss.barrageData[1].param2=-0.1;//cëùå∏ó 
	boss.barrageData[1].param3=0.0;//ÉtÉâÉO

	boss.barrageData[2].attackPattern=7;
	boss.barrageData[2].shot_v=0.0;
	boss.barrageData[2].shot_rot_rad=0.0;
	boss.barrageData[2].startPos=GetPositionFromXY(258.0,160.0);
	boss.barrageData[2].shot_kind=eb_kunai;
	boss.barrageData[2].shot_bul_color=bul_waterblue;
	boss.barrageData[2].shotStartTime=120;
	boss.barrageData[2].shotMovePattern=7;
	boss.barrageData[2].small_group_num=1;
	boss.barrageData[2].small_group_bet_time=1;
	boss.barrageData[2].large_group_bet_time=5;
	boss.barrageData[2].param1=0.01;//cèâä˙íl
	boss.barrageData[2].param2=0.1;//cëùå∏ó 
	boss.barrageData[2].param3=0.0;//ÉtÉâÉO

	boss.barrageData[3].attackPattern=7;
	boss.barrageData[3].shot_v=0.0;
	boss.barrageData[3].shot_rot_rad=0.0;
	boss.barrageData[3].startPos=GetPositionFromXY(258.0,160.0);
	boss.barrageData[3].shot_kind=eb_kunai;
	boss.barrageData[3].shot_bul_color=bul_purple;
	boss.barrageData[3].shotStartTime=175;
	boss.barrageData[3].shotMovePattern=7;
	boss.barrageData[3].small_group_num=1;
	boss.barrageData[3].small_group_bet_time=1;
	boss.barrageData[3].large_group_bet_time=5;
	boss.barrageData[3].param1=0.99;//cèâä˙íl
	boss.barrageData[3].param2=-0.1;//cëùå∏ó 
	boss.barrageData[3].param3=0.0;//ÉtÉâÉO

	//ë»â~xïù200.0 //ë»â~yïù120.0 //äpë¨ìxM_PI*2/180
	for(int i=4;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_06(){
	//é©ã@ë_Ç¢
	boss.barrageData[0].attackPattern=8;
	boss.barrageData[0].shot_v=2.0;
	boss.barrageData[0].shot_rot_rad=M_PI;
	boss.barrageData[0].startPos=GetPositionFromXY(258.0,180.0);
	boss.barrageData[0].shot_kind=eb_fuda;
	boss.barrageData[0].shot_bul_color=bul_yellow;
	boss.barrageData[0].shotStartTime=5;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=4;
	boss.barrageData[0].small_group_bet_time=50;
	boss.barrageData[0].param1=M_PI*3.5/180;//rot_radë¨ìx

	//ÇŒÇÁÇ‹Ç´
	boss.barrageData[1].attackPattern=9;
	boss.barrageData[1].shot_v=0.0;
	boss.barrageData[1].shot_rot_rad=0.0;
	boss.barrageData[1].startPos=GetPositionFromXY(258.0,180.0);
	boss.barrageData[1].shot_kind=eb_fuda;
	boss.barrageData[1].shot_bul_color=bul_green;
	boss.barrageData[1].shotStartTime=5;
	boss.barrageData[1].shotMovePattern=8;
	boss.barrageData[1].small_group_num=8;
	boss.barrageData[1].small_group_bet_time=8;
	boss.barrageData[1].param1=M_PI*2.5/180;
	boss.barrageData[1].param2=0.005;

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

//stage3
void BossStaticShotPattern_07(){
	boss.barrageData[0].attackPattern=10;
	boss.barrageData[0].shot_v=1.0;
	boss.barrageData[0].shot_trans_rad=M_PI/4;
	boss.barrageData[0].startPos=GetPositionFromXY(0.0,0.0);
	boss.barrageData[0].shot_kind=eb_money;
	boss.barrageData[0].shot_bul_color=bul_orange;
	boss.barrageData[0].shotStartTime=20;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=3;
	boss.barrageData[0].small_group_bet_time=4;
	boss.barrageData[0].large_group_num=3;
	boss.barrageData[0].large_group_bet_time=30;
	boss.barrageData[0].param1=0.0;//äpìx
	boss.barrageData[0].param2=M_PI*3/180;//äpë¨ìx
	boss.barrageData[0].param3=M_PI*30/180;

	boss.barrageData[1].attackPattern=10;
	boss.barrageData[1].shot_v=1.0;
	boss.barrageData[1].shot_trans_rad=M_PI*3/4;
	boss.barrageData[1].startPos=GetPositionFromXY((double)FIELD_SIZE_WIDTH,0.0);
	boss.barrageData[1].shot_kind=eb_money;
	boss.barrageData[1].shot_bul_color=bul_orange;
	boss.barrageData[1].shotStartTime=20;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=3;
	boss.barrageData[1].small_group_bet_time=4;
	boss.barrageData[1].large_group_num=3;
	boss.barrageData[1].large_group_bet_time=30;
	boss.barrageData[1].param1=0.0;//äpìx
	boss.barrageData[1].param2=M_PI*3/180;//äpë¨ìx
	boss.barrageData[1].param3=M_PI*30/180;

	boss.barrageData[2].attackPattern=10;
	boss.barrageData[2].shot_v=1.0;
	boss.barrageData[2].shot_trans_rad=M_PI*7/4;
	boss.barrageData[2].startPos=GetPositionFromXY(0.0,(double)FIELD_SIZE_HEIGHT);
	boss.barrageData[2].shot_kind=eb_money;
	boss.barrageData[2].shot_bul_color=bul_orange;
	boss.barrageData[2].shotStartTime=20;
	boss.barrageData[2].shotMovePattern=0;
	boss.barrageData[2].small_group_num=3;
	boss.barrageData[2].small_group_bet_time=4;
	boss.barrageData[2].large_group_num=3;
	boss.barrageData[2].large_group_bet_time=30;
	boss.barrageData[2].param1=0.0;//äpìx
	boss.barrageData[2].param2=M_PI*3/180;//äpë¨ìx
	boss.barrageData[2].param3=M_PI*30/180;

	boss.barrageData[3].attackPattern=10;
	boss.barrageData[3].shot_v=1.0;
	boss.barrageData[3].shot_trans_rad=M_PI*5/4;
	boss.barrageData[3].startPos=GetPositionFromXY((double)FIELD_SIZE_WIDTH,(double)FIELD_SIZE_HEIGHT);
	boss.barrageData[3].shot_kind=eb_money;
	boss.barrageData[3].shot_bul_color=bul_orange;
	boss.barrageData[3].shotStartTime=20;
	boss.barrageData[3].shotMovePattern=0;
	boss.barrageData[3].small_group_num=3;
	boss.barrageData[3].small_group_bet_time=4;
	boss.barrageData[3].large_group_num=3;
	boss.barrageData[3].large_group_bet_time=30;
	boss.barrageData[3].param1=0.0;//äpìx
	boss.barrageData[3].param2=M_PI*3/180;//äpë¨ìx
	boss.barrageData[3].param3=M_PI*30/180;

	for(int i=4;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_08(){
	boss.barrageData[0].attackPattern=11;
	boss.barrageData[0].shot_v=0.0;
	boss.barrageData[0].shot_rot_rad=M_PI*2*GetRand(3600)/3600;
	boss.barrageData[0].startPos=player.pos;
	boss.barrageData[0].shot_kind=eb_crystal;
	boss.barrageData[0].shot_bul_color=bul_blue;
	boss.barrageData[0].shotStartTime=1;
	boss.barrageData[0].shotMovePattern=1;
	boss.barrageData[0].small_group_num=8;
	boss.barrageData[0].small_group_bet_time=3;
	boss.barrageData[0].large_group_num=16;
	boss.barrageData[0].large_group_bet_time=200;
	boss.barrageData[0].param1=0.01;//â¡ë¨ìx
	boss.barrageData[0].param2=M_PI*3/180;

	for(int i=1;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_09(){
	boss.barrageData[0].attackPattern=12;
	boss.barrageData[0].shot_v=5.0;
	boss.barrageData[0].shot_rot_rad=0.0;
	boss.barrageData[0].startPos=GetPositionFromXY(108.0,160.0);
	boss.barrageData[0].shot_kind=eb_lazer;
	boss.barrageData[0].shot_bul_color=bul_green;
	boss.barrageData[0].shotStartTime=10;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=6;
	boss.barrageData[0].small_group_bet_time=15;
	boss.barrageData[0].param1=M_PI*10/180;

	boss.barrageData[1].attackPattern=12;
	boss.barrageData[1].shot_v=5.0;
	boss.barrageData[1].shot_rot_rad=0.0;
	boss.barrageData[1].startPos=GetPositionFromXY(408.0,160.0);
	boss.barrageData[1].shot_kind=eb_lazer;
	boss.barrageData[1].shot_bul_color=bul_green;
	boss.barrageData[1].shotStartTime=10;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=6;
	boss.barrageData[1].small_group_bet_time=15;
	boss.barrageData[1].param1=-M_PI*10/180;

	boss.barrageData[2].attackPattern=13;
	boss.barrageData[2].shot_v=1.5;
	boss.barrageData[2].shot_rot_rad=0.0;
	boss.barrageData[2].startPos=GetPositionFromXY(108.0,160.0);
	boss.barrageData[2].shot_kind=eb_middle;
	boss.barrageData[2].shot_bul_color=bul_blue;
	boss.barrageData[2].shotStartTime=50;
	boss.barrageData[2].shotMovePattern=0;
	boss.barrageData[2].small_group_bet_time=100;

	for(int i=3;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_10(){
	boss.barrageData[0].attackPattern=14;
	boss.barrageData[0].shot_v=2.0;
	boss.barrageData[0].shot_rot_rad=0.0;
	boss.barrageData[0].startPos=boss.pos;
	boss.barrageData[0].shot_kind=eb_small;
	boss.barrageData[0].shot_bul_color=bul_yellow;
	boss.barrageData[0].shotStartTime=5;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=16;
	boss.barrageData[0].small_group_bet_time=5;
	boss.barrageData[0].param1=M_PI*5/180;
	boss.barrageData[0].param2=M_PI*120/180;

	boss.barrageData[1].attackPattern=21;
	boss.barrageData[1].shot_v=3.0;
	boss.barrageData[1].shot_trans_rad=M_PI/2;
	boss.barrageData[1].startPos=boss.pos;
	boss.barrageData[1].shot_kind=eb_middle;
	boss.barrageData[1].shot_bul_color=bul_yellow;
	boss.barrageData[1].shotStartTime=5;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=1;
	boss.barrageData[1].small_group_bet_time=12;

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

//stage4
void BossStaticShotPattern_11(){
	boss.barrageData[0].attackPattern=15;
	boss.barrageData[0].shot_v=2.0;
	boss.barrageData[0].shot_rot_rad=M_PI/2;
	boss.barrageData[0].startPos=boss.pos;
	boss.barrageData[0].shot_kind=eb_middle;
	boss.barrageData[0].shot_bul_color=bul_yellow;
	boss.barrageData[0].shotStartTime=5;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=16;
	boss.barrageData[0].small_group_bet_time=20;
	boss.barrageData[0].param1=M_PI*15/180;

	boss.barrageData[1].attackPattern=15;
	boss.barrageData[1].shot_v=2.0;
	boss.barrageData[1].shot_rot_rad=M_PI/2;
	boss.barrageData[1].startPos=boss.pos;
	boss.barrageData[1].shot_kind=eb_middle;
	boss.barrageData[1].shot_bul_color=bul_yellow;
	boss.barrageData[1].shotStartTime=5;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=16;
	boss.barrageData[1].small_group_bet_time=20;
	boss.barrageData[1].param1=-M_PI*15/180;

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_12(){
	boss.barrageData[0].attackPattern=16;
	boss.barrageData[0].shot_v=3.0;
	boss.barrageData[0].shot_rot_rad=0.00;
	boss.barrageData[0].shot_trans_rad=M_PI*3/2;
	boss.barrageData[0].startPos=boss.pos;
	boss.barrageData[0].shot_kind=eb_middle;
	boss.barrageData[0].shot_bul_color=bul_waterblue;
	boss.barrageData[0].shotStartTime=5;
	boss.barrageData[0].shotMovePattern=9;
	boss.barrageData[0].small_group_num=12;
	boss.barrageData[0].small_group_bet_time=8;
	boss.barrageData[0].param1=M_PI*15/180;//äpë¨ìx
	boss.barrageData[0].param2=M_PI/3;//êUÇÍïù

	boss.barrageData[1].attackPattern=22;
	boss.barrageData[1].shot_v=3.0;
	boss.barrageData[1].shot_trans_rad=M_PI/2;
	boss.barrageData[1].startPos=boss.pos;
	boss.barrageData[1].shot_kind=eb_crystal;
	boss.barrageData[1].shot_bul_color=bul_blue;
	boss.barrageData[1].shotStartTime=100;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=6;
	boss.barrageData[1].small_group_bet_time=10;
	boss.barrageData[1].param1=M_PI*30/180;//äpìx

	for(int i=2;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_13(){
	boss.barrageData[0].attackPattern=17;
	boss.barrageData[0].shot_v=1.5;
	boss.barrageData[0].shot_trans_rad=M_PI/2;
	boss.barrageData[0].startPos=boss.pos;
	boss.barrageData[0].shot_kind=eb_small;
	boss.barrageData[0].shot_bul_color=bul_blue;
	boss.barrageData[0].shotStartTime=10;
	boss.barrageData[0].shotMovePattern=10;
	boss.barrageData[0].small_group_num=3;
	boss.barrageData[0].small_group_bet_time=10;
	boss.barrageData[0].param1=M_PI*5/180;//äpë¨ìx
	boss.barrageData[0].param2=30.0;//äpìxïœâªãñóeó 

	for(int i=1;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_14(){
	boss.barrageData[0].attackPattern=18;
	boss.barrageData[0].shot_v=1.0;
	boss.barrageData[0].shot_trans_rad=M_PI/2;
	boss.barrageData[0].startPos=GetPositionFromXY(0.0,-40.0);
	boss.barrageData[0].shot_kind=eb_large;
	//boss.barrageData[0].shot_bul_color=random;
	boss.barrageData[0].shotStartTime=50;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].small_group_num=100;
	boss.barrageData[0].small_group_bet_time=500;

	boss.barrageData[1].attackPattern=18;
	boss.barrageData[1].shot_v=1.0;
	boss.barrageData[1].shot_trans_rad=M_PI/2;
	boss.barrageData[1].startPos=GetPositionFromXY(80.0,-40.0);
	boss.barrageData[1].shot_kind=eb_large;
	//boss.barrageData[1].shot_bul_color=random;
	boss.barrageData[1].shotStartTime=300;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].small_group_num=100;
	boss.barrageData[1].small_group_bet_time=500;

	boss.barrageData[2].attackPattern=19;
	boss.barrageData[2].shot_v=4.0;
	boss.barrageData[2].startPos=boss.pos;
	boss.barrageData[2].shot_kind=eb_knife;
	boss.barrageData[2].shot_bul_color=bul_red;
	boss.barrageData[2].shotStartTime=50;
	boss.barrageData[2].shotMovePattern=0;
	boss.barrageData[2].small_group_num=9;
	boss.barrageData[2].small_group_bet_time=90;
	boss.barrageData[2].param1=M_PI*150/180;

	boss.barrageData[3].attackPattern=19;
	boss.barrageData[3].shot_v=4.0;
	boss.barrageData[3].startPos=boss.pos;
	boss.barrageData[3].shot_kind=eb_knife;
	boss.barrageData[3].shot_bul_color=bul_purple;
	boss.barrageData[3].shotStartTime=50;
	boss.barrageData[3].shotMovePattern=11;
	boss.barrageData[3].small_group_num=8;
	boss.barrageData[3].small_group_bet_time=90;
	boss.barrageData[3].param1=M_PI*140/180;

	for(int i=4;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void BossStaticShotPattern_15(){
	boss.barrageData[0].whole_time=700;
	boss.barrageData[0].attackPattern=20;
	boss.barrageData[0].move_v=3.0;
	boss.barrageData[0].shot_v=0.5;
	boss.barrageData[0].shot_trans_rad=M_PI*GetRand(1800)/1800;
	boss.barrageData[0].startPos=GetPositionFromXY(38.0,0.0);
	boss.barrageData[0].shot_kind=eb_fuda;
	boss.barrageData[0].shot_bul_color=bul_red;
	boss.barrageData[0].shotMovePattern=0;
	boss.barrageData[0].shotStartTime=10;
	boss.barrageData[0].param1=M_PI*15/180;

	boss.barrageData[1].whole_time=700;
	boss.barrageData[1].attackPattern=20;
	boss.barrageData[1].move_v=3.0;
	boss.barrageData[1].shot_v=0.5;
	boss.barrageData[1].shot_trans_rad=M_PI*GetRand(1800)/1800;
	boss.barrageData[1].startPos=GetPositionFromXY(148.0,0.0);
	boss.barrageData[1].shot_kind=eb_fuda;
	boss.barrageData[1].shot_bul_color=bul_green;
	boss.barrageData[1].shotMovePattern=0;
	boss.barrageData[1].shotStartTime=10;
	boss.barrageData[1].param1=M_PI*15/180;

	boss.barrageData[2].whole_time=700;
	boss.barrageData[2].attackPattern=20;
	boss.barrageData[2].move_v=3.0;
	boss.barrageData[2].shot_v=0.5;
	boss.barrageData[2].shot_trans_rad=M_PI*GetRand(1800)/1800;
	boss.barrageData[2].startPos=GetPositionFromXY(258.0,0.0);
	boss.barrageData[2].shot_kind=eb_fuda;
	boss.barrageData[2].shot_bul_color=bul_blue;
	boss.barrageData[2].shotMovePattern=0;
	boss.barrageData[2].shotStartTime=10;
	boss.barrageData[2].param1=M_PI*15/180;

	boss.barrageData[3].whole_time=700;
	boss.barrageData[3].attackPattern=20;
	boss.barrageData[3].move_v=3.0;
	boss.barrageData[3].shot_v=0.5;
	boss.barrageData[3].shot_trans_rad=M_PI*GetRand(1800)/1800;
	boss.barrageData[3].startPos=GetPositionFromXY(368.0,0.0);
	boss.barrageData[3].shot_kind=eb_fuda;
	boss.barrageData[3].shot_bul_color=bul_purple;
	boss.barrageData[3].shotMovePattern=0;
	boss.barrageData[3].shotStartTime=10;
	boss.barrageData[3].param1=M_PI*15/180;

	boss.barrageData[4].whole_time=700;
	boss.barrageData[4].attackPattern=20;
	boss.barrageData[4].move_v=3.0;
	boss.barrageData[4].shot_v=0.5;
	boss.barrageData[4].shot_trans_rad=M_PI*GetRand(1800)/1800;
	boss.barrageData[4].startPos=GetPositionFromXY(478.0,0.0);
	boss.barrageData[4].shot_kind=eb_fuda;
	boss.barrageData[4].shot_bul_color=bul_orange;
	boss.barrageData[4].shotMovePattern=0;
	boss.barrageData[4].shotStartTime=10;
	boss.barrageData[4].param1=M_PI*15/180;

	for(int i=5;i<BO_BARRAGE_MAX;i++){
		boss.barrageData[i].attackPattern=-1;
	}
}

void(*BossStaticShotPattern[])()={
	BossStaticShotPattern_00,
	BossStaticShotPattern_01,
	BossStaticShotPattern_02,
	BossStaticShotPattern_03,
	BossStaticShotPattern_04,
	BossStaticShotPattern_05,
	BossStaticShotPattern_06,
	BossStaticShotPattern_07,
	BossStaticShotPattern_08,
	BossStaticShotPattern_09,
	BossStaticShotPattern_10,
	BossStaticShotPattern_11,
	BossStaticShotPattern_12,
	BossStaticShotPattern_13,
	BossStaticShotPattern_14,
	BossStaticShotPattern_15
};

//É{ÉXÇÃçUåÇñàÇ…åƒÇ‘ÅB
void GetBossStaticShotData(){
	BossStaticShotPattern[gameData.bossTotalAttack_c]();
}
/////////////////////////////////////////////////////////////////////////

void BossSet(Position startPos,int charaKind,int attackNum_MAX){
	if(boss.f==true)return;

	boss.f=true;
	boss.c=0;
	boss.chip_rad=0.00;
	boss.attack_c=0;

	boss.charaKind=charaKind;
	boss.attack_num=attackNum_MAX;

	GetBossStaticMoveData();
	GetBossStaticShotData();

	boss.status=b_next_preparing;
	boss.startPos=startPos;
	boss.stopPos=boss.moveData.startPos;
}


//à⁄ìÆ
void BossMovePattern_00(){
	int t = (boss.c%(boss.moveData.movingBetTime+boss.moveData.waitTime));
	if(t==0){
		boss.startPos = boss.pos;
		boss.stopPos = GetPositionFromXY(50.0+GetRand(384),50.0+GetRand(100));
		boss.trans_rad = atan2(boss.stopPos.y-boss.startPos.y,boss.stopPos.x-boss.startPos.x);
	}
	else if(t<boss.moveData.movingBetTime){
		boss.pos.x = boss.startPos.x + 2.0*(boss.stopPos.x-boss.startPos.x)*t/boss.moveData.movingBetTime - (boss.stopPos.x-boss.startPos.x)*t*t/boss.moveData.movingBetTime/boss.moveData.movingBetTime;
		boss.pos.y = boss.startPos.y + 2.0*(boss.stopPos.y-boss.startPos.y)*t/boss.moveData.movingBetTime - (boss.stopPos.y-boss.startPos.y)*t*t/boss.moveData.movingBetTime/boss.moveData.movingBetTime;
	}
	else{
		boss.trans_rad=M_PI/2;
	}
}

//í‚é~
void BossMovePattern_01(){

}

void(*BossMovePattern[])()={
	BossMovePattern_00,
	BossMovePattern_01
};

void BossMove(){
	BossMovePattern[boss.moveData.movePattern]();
}

void BossUpdate(){
	if(boss.f==false)return;

	boss.c++;
	if(boss.c%10==0)boss.chip_rad+=M_PI/2;

	if(boss.status==b_preparing){
		if(boss.c<=100){
			boss.HP = boss.moveData.HP_MAX*boss.c/100;
			boss.trans_rad=M_PI/2;
		}
		else if(boss.c==150){
			boss.c=0;
			boss.startPos=boss.pos;
			boss.status=b_normal;
		}
	}
	else if(boss.status==b_normal){
		BossMove();
		for(int i=0;i<BO_BARRAGE_MAX;i++){
			if(boss.barrageData[i].attackPattern==-1)break;

			if(boss.c==boss.barrageData[i].shotStartTime){
				Bo_BarrageSet(&boss.barrageData[i]);
			}
		}

		if(boss.HP<0){
			ItemSet(boss.pos,9);
			boss.HP=0;
			boss.attack_c++;
			gameData.bossTotalAttack_c++;
			for(int i=0;i<BO_BARRAGE_MAX;i++){
				bo_barrage[i].f=false;
			}
			for(int i=0;i<EN_BULLET_MAX;i++){
				if(en_bullet[i].f==true){
					en_bullet[i].f=false;
				}
			}
			if(boss.attack_c==boss.attack_num){
				boss.c=0;
				boss.status=b_dead;
			}
			else{
				GetBossStaticMoveData();
				GetBossStaticShotData();
				boss.c=0;
				boss.status=b_next_preparing;
			}
		}
	}
	else if(boss.status==b_next_preparing){
		//200ÉJÉEÉìÉgÇ≈éüÇÃäJénínì_Ç‹Ç≈à⁄ìÆÇ∑ÇÈ
		if(boss.c<=200){
			boss.trans_rad = atan2(boss.stopPos.y-boss.startPos.y,boss.stopPos.x-boss.startPos.x);
			boss.pos.x = boss.startPos.x + 2.0*(boss.stopPos.x-boss.startPos.x)*boss.c/200 - (boss.stopPos.x-boss.startPos.x)*boss.c*boss.c/200/200;
			boss.pos.y = boss.startPos.y + 2.0*(boss.stopPos.y-boss.startPos.y)*boss.c/200 - (boss.stopPos.y-boss.startPos.y)*boss.c*boss.c/200/200;
		}
		else if(boss.c<=250){
			boss.trans_rad=M_PI/2;
		}
		else{
			//çUåÇäJén
			boss.c=0;
			boss.status=b_preparing;
		}
	}
	else{
		if(boss.c>=450){
			boss.f=false;
			if(gameData.stageData.stage!=4){
				GoToNextStage();
			}
			else{
				gameData.gameStatusStage=stage_end;
			}
		}
	}

	boss.trans_rad=GetFixedRad(boss.trans_rad);
	boss.direction=GetDirectionFromRad(boss.trans_rad);
}


void BossDraw(){
	if(boss.f==false)return;

	if(boss.status==b_dead){
		if(boss.c<90){
			DrawGraph(FIELD_OFFSET_X+Round(boss.pos.x)-(EXPLODE_WIDTH-ENEMY_WIDTH)/2,FIELD_OFFSET_Y+Round(boss.pos.y)-(EXPLODE_HEIGHT-ENEMY_HEIGHT)/2,gameData.chip.explode[(boss.c-boss.c%6)/6],true);
		}
	}
	else{
		DrawGraph(FIELD_OFFSET_X+Round(boss.pos.x),FIELD_OFFSET_Y+Round(boss.pos.y),gameData.chip.enemy[boss.charaKind][3*boss.direction+1+Round(sin(boss.chip_rad))],true);
	}
}