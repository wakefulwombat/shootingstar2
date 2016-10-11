#include"common.h"

void GameStageUpdate(){
	gameData.stageData.c++;
	gameData.stageData.backScroll_y++;
}

void GameStageDraw(){
	DrawGraph(0,0,gameData.chip.board[dir_up],false);
	DrawGraph(0,FIELD_OFFSET_Y,gameData.chip.board[dir_left],false);
	DrawGraph(FIELD_OFFSET_X+FIELD_SIZE_WIDTH,FIELD_OFFSET_Y,gameData.chip.board[dir_right],false);
	DrawGraph(0,FIELD_OFFSET_Y+FIELD_SIZE_HEIGHT,gameData.chip.board[dir_down],false);

	for(int i=0;i<(int)player.power;i++){
		DrawGraph(SCOREBOARD_OFFSET_X+90+PL_STATUS_WIDTH*i,SCOREBOARD_OFFSET_Y+100,gameData.chip.pl_status[0],true);
	}

	for(int i=0;i<(int)player.bomb;i++){
		DrawGraph(SCOREBOARD_OFFSET_X+90+PL_STATUS_WIDTH*i,SCOREBOARD_OFFSET_Y+170,gameData.chip.pl_status[1],true);
	}

	for(int i=0;i<player.life;i++){
		DrawGraph(SCOREBOARD_OFFSET_X+90+PL_STATUS_WIDTH*i,SCOREBOARD_OFFSET_Y+240,gameData.chip.pl_status[2],true);
	}

	if((gameData.key[KEY_INPUT_LSHIFT]==1)||(player.status==invincible)){
		DrawGraph(FIELD_OFFSET_X+Round(player.pos.x)+PLAYER_WIDTH/2-gameData.eb_size[eb_small].width/2,
					FIELD_OFFSET_Y+Round(player.pos.y)+PLAYER_HEIGHT/2-gameData.eb_size[eb_small].height/2,
					gameData.chip.e_bullet[eb_small][bul_red],true);
	}

	if(boss.f==true){
		if((boss.status==b_normal)||(boss.status==b_preparing)){
			DrawRectGraph(FIELD_OFFSET_X+20,FIELD_OFFSET_Y+10,0,0,476*boss.HP/boss.moveData.HP_MAX,6,gameData.chip.boss_lifeBar,true,false);
			for(int i=0;i<boss.attack_num-boss.attack_c;i++){
				DrawGraph(FIELD_OFFSET_X+20+14*i,FIELD_OFFSET_Y+18,gameData.chip.e_spell,true);
			}
		}
	}

	//DrawFormatString(SCOREBOARD_OFFSET_X+90,SCOREBOARD_OFFSET_Y+310,GetColor(255,255,255),"counter=%d",gameData.stageData.c);
	//DrawFormatString(SCOREBOARD_OFFSET_X+90,SCOREBOARD_OFFSET_Y+340,GetColor(255,255,255),"power=%f",player.power);
	//DrawFormatString(SCOREBOARD_OFFSET_X+90,SCOREBOARD_OFFSET_Y+370,GetColor(255,255,255),"bomb=%f",player.bomb);
	//DrawFormatString(SCOREBOARD_OFFSET_X+90,SCOREBOARD_OFFSET_Y+400,GetColor(255,255,255),"life=%d",player.life);
}

void GameStagePreDraw(){
	DrawGraph(FIELD_OFFSET_X,FIELD_OFFSET_Y+gameData.stageData.backScroll_y%(FIELD_SIZE_HEIGHT)-FIELD_SIZE_HEIGHT,gameData.chip.back[gameData.stageData.stage-1],false);
	DrawGraph(FIELD_OFFSET_X,FIELD_OFFSET_Y+gameData.stageData.backScroll_y%(FIELD_SIZE_HEIGHT),gameData.chip.back[gameData.stageData.stage-1],false);
}

int Round(double x){
	return (int)( x < 0.0 ? x-0.4999 : x+0.4999);
}

void stageDataInit(){
	gameData.stageData.c=0;
	gameData.stageData.backScroll_y=0;
	gameData.stageData.score=0;
	gameData.stageData.scoreHold=0;
	gameData.stageData.stage=1;

	GameMusicPlay((MusicList)(gameData.stageData.stage*2-2));
}