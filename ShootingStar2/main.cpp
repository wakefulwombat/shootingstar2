//include,define
#define _GLOBAL_INSTANCE_
#include "common.h"


// main�֐��̊J�n
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE)	;		// debug�p�E�B���h�E�T�C�Y
	SetGraphMode(SCREEN_SIZE_WIDTH,SCREEN_SIZE_HEIGHT,16);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("���ʂ��悢");
	SetOutApplicationLogValidFlag(FALSE);
	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}
	GGS4OpenDevice(GGSDEVICE_DIRECTMUSIC,NULL);
	
	SetDrawScreen( DX_SCREEN_BACK ) ;	// �`����ʂ𗠉�ʂɂ���


	while (1) {
		ClearDrawScreen()	;	// ��ʃN���A
		
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
				DrawFormatString(20,200,GetColor(255,255,255),"���Ȃ��̘r�O...   �N�g�D���[��");
				DrawFormatString(20,220,GetColor(255,255,255),"���C�����Ζ{�C����");
			}
			else if(player.life>=-5){
				DrawFormatString(20,200,GetColor(255,255,255),"���Ȃ��̘r�O...   �j�������g�e�b�v��");
				DrawFormatString(20,220,GetColor(255,255,255),"�����j�R�j�R���Ȃ��ׂ̗ɔ�����鍬��");
			}
			else if(player.life>=-10){
				DrawFormatString(20,200,GetColor(255,255,255),"���Ȃ��̘r�O...   �_�S����");
				DrawFormatString(20,220,GetColor(255,255,255),"���� ���ɁI���ɁI");
			}
			else if(player.life>=-15){
				DrawFormatString(20,200,GetColor(255,255,255),"���Ȃ��̘r�O...   �~���S��");
				DrawFormatString(20,220,GetColor(255,255,255),"�����E�q");
			}
			else if(player.life>=-20){
				DrawFormatString(20,200,GetColor(255,255,255),"���Ȃ��̘r�O...   �V���S�X��");
				DrawFormatString(20,220,GetColor(255,255,255),"�e�P���E�� �e�P���E�� �����̃��C�h�͕s��`");
			}
			else{
				DrawFormatString(20,200,GetColor(255,255,255),"���Ȃ��̘r�O...   �C���V�̐؂�g��");
			}
		}

		ScreenFlip()	;		// redraw 1

		if (ProcessMessage() == -1 ) break	;	// windows���b�Z�[�W����
		if ( CheckHitKey(KEY_INPUT_ESCAPE ) == 1) break	;	// esc�L�[�ŏI��
	
	}

	DxLib_End()	;//DX���C�u�����I������
	GGS4CloseDevice();

	return 0	;
}