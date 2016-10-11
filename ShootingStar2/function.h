#ifdef _GLOBAL_INSTANCE_
#define GLOBAL
#else
#define GLOBAL extern
#endif

#ifndef _STRUCT_
#include "struct.h"
#define _STRUCT_
#endif


GLOBAL void GameInit();
GLOBAL void stageDataInit();
GLOBAL void PlayerInit();
GLOBAL void Pl_BulletInit();
GLOBAL void Pl_SubWeaponInit();
GLOBAL void Pl_BombInit();
GLOBAL void EnemyInit();
GLOBAL void En_BulletInit();
GLOBAL void En_BarrageInit();


GLOBAL void GameStageUpdate();
GLOBAL void GameStageDraw();
GLOBAL void GameStagePreDraw();

GLOBAL void PlayerUpdate();
GLOBAL void PlayerDraw();

GLOBAL void Pl_BulletSet(Position pos,double v,double shot_rad,int power,Bul_Color color,bool playerShot=true);
GLOBAL void Pl_BulletUpdate();
GLOBAL void Pl_BulletDraw();

GLOBAL void Pl_SubWeaponUpdate();
GLOBAL void Pl_SubWeaponDraw();

GLOBAL void Pl_BombSet();
GLOBAL void Pl_BombUpdate();
GLOBAL void Pl_BombDraw();

GLOBAL void EnemySet(StaticEnemyData* staticData,StaticEnemyShotData* staticShotData);
GLOBAL void EnemyUpdate();
GLOBAL void EnemyDraw();

GLOBAL void En_BulletSet(Position pos,double v,double trans_rad,Bul_Color color,En_BulletKind kind,int movePattern,int e_index,double param1=0.0,double param2=0.0);
GLOBAL void En_BulletUpdate();
GLOBAL void En_BulletDraw();

GLOBAL void En_LazerSet(Position start,Position control,Position end,double v,double rad,int movePattern,int e_index,Bul_Color color,int div_num=EN_LAZER_DIV_MAX);
GLOBAL void En_LazerUpdate();
GLOBAL void En_LazerDraw();

GLOBAL void En_BarrageSet(StaticEnemyShotData* enemyShotData,int e_index);
GLOBAL void En_BarrageUpdate();

GLOBAL void ItemSet(Position pos,int itemPattern);
GLOBAL void ItemUpdate();
GLOBAL void ItemDraw();

GLOBAL void BossSet(Position startPos,int charaKind,int attackNum_MAX);
GLOBAL void BossUpdate();
GLOBAL void BossDraw();

GLOBAL void Bo_BarrageSet(StaticBossBarrageData* barrageData);
GLOBAL void Bo_BarrageUpdate();

GLOBAL void HitCHeckAllAndUpdate();

GLOBAL void OpeningUpdate();
GLOBAL void OpeningDraw();


GLOBAL int Round(double value);

GLOBAL Position GetPositionFromXY(double x,double y);
GLOBAL Position GetPosAdd(Position pos,double x,double y);

GLOBAL double GetFixedRad(double rad);
GLOBAL Direction GetDirectionFromRad(double rad);

GLOBAL void PlayerHited();
GLOBAL void PlayerPowerChanged(double variation,bool add);
GLOBAL void PlayerBombChanged(double variation,bool add);

GLOBAL void GameMusicPlay(MusicList index);

GLOBAL void GoToNextStage();

GLOBAL void Pl_SubWeaponMove_Approach();
GLOBAL void Pl_SubWeaponMove_Secission();
GLOBAL void SetSubWeaponShotInfomation();

GLOBAL void ItemSetToCollecting();
GLOBAL void ItemSetToCollectingNear();