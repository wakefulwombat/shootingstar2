#include"common.h"


void OpeningUpdate(){
	if(CheckHitKey(KEY_INPUT_A)==1){
		gameData.gameStatusStage=stage_game;
		GameInit();
		player.attack_pattern = front_curve;
	}
	if(CheckHitKey(KEY_INPUT_B)==1){
		gameData.gameStatusStage=stage_game;
		GameInit();
		player.attack_pattern = side_curve;
	}
	if(CheckHitKey(KEY_INPUT_C)==1){
		gameData.gameStatusStage=stage_game;
		GameInit();
		player.attack_pattern = back_curve;
	}
}

void OpeningDraw(){
	DrawFormatString(20,400,GetColor(255,255,255),"A,B,CÇÃÇ«ÇÍÇ©ÉLÅ[ÇâüÇ∑ÇÃÇæ...");
}