//include,define
#define _GLOBAL_INSTANCE_
#include "common.h"


// main関数の開始
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE)	;		// debug用ウィンドウサイズ
	SetGraphMode(SCREEN_SIZE_WIDTH,SCREEN_SIZE_HEIGHT,16);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("死ぬがよい");
	SetOutApplicationLogValidFlag(FALSE);
	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}
	GGS4OpenDevice(GGSDEVICE_DIRECTMUSIC,NULL);
	
	SetDrawScreen( DX_SCREEN_BACK ) ;	// 描画先画面を裏画面にする


	while (1) {
		ClearDrawScreen()	;	// 画面クリア
		
		if(gameData.gameStatusStage==stage_start){
			OpeningUpdate();
			OpeningDraw();
		}
		if(gameData.gameStatusStage==stage_game){
		GameStageUpdate();
		PlayerUpdate();
		Pl_BulletUpdate();
		Pl_SubWeaponUpdate();
		Pl_BombUpdate();
		EnemyUpdate();
		BossUpdate();
		Bo_BarrageUpdate();
		En_BulletUpdate();
		En_LazerUpdate();
		En_BarrageUpdate();
		ItemUpdate();


		GameStagePreDraw();
		PlayerDraw();
		Pl_BulletDraw();
		Pl_SubWeaponDraw();
		Pl_BombDraw();
		EnemyDraw();
		BossDraw();
		ItemDraw();
		En_LazerDraw();
		En_BulletDraw();

		GameStageDraw();

		HitCHeckAllAndUpdate();
		}

		if(gameData.gameStatusStage==stage_end){
			if(player.life>=0){
				DrawFormatString(20,200,GetColor(255,255,255),"あなたの腕前...   クトゥルー級");
				DrawFormatString(20,220,GetColor(255,255,255),"星辰揃えば本気だす");
			}
			else if(player.life>=-5){
				DrawFormatString(20,200,GetColor(255,255,255),"あなたの腕前...   ニャルラトテップ級");
				DrawFormatString(20,220,GetColor(255,255,255),"いつもニコニコあなたの隣に這い寄る混沌");
			}
			else if(player.life>=-10){
				DrawFormatString(20,200,GetColor(255,255,255),"あなたの腕前...   ダゴン級");
				DrawFormatString(20,220,GetColor(255,255,255),"ああ 窓に！窓に！");
			}
			else if(player.life>=-15){
				DrawFormatString(20,200,GetColor(255,255,255),"あなたの腕前...   ミ＝ゴ級");
				DrawFormatString(20,220,GetColor(255,255,255),"頭が胞子");
			}
			else if(player.life>=-20){
				DrawFormatString(20,200,GetColor(255,255,255),"あなたの腕前...   ショゴス級");
				DrawFormatString(20,220,GetColor(255,255,255),"テケリ・リ テケリ・リ うちのメイドは不定形");
			}
			else{
				DrawFormatString(20,200,GetColor(255,255,255),"あなたの腕前...   イワシの切り身級");
			}
		}

		ScreenFlip()	;		// redraw 1

		if (ProcessMessage() == -1 ) break	;	// windowsメッセージ処理
		if ( CheckHitKey(KEY_INPUT_ESCAPE ) == 1) break	;	// escキーで終了
	
	}

	DxLib_End()	;//DXライブラリ終了処理
	GGS4CloseDevice();

	return 0	;
}