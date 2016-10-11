#ifndef _DEFINE_
#include "define.h"
#define _DEFINE_
#endif

#ifndef _STRUCT_
#include "struct.h"
#define _STRUCT_
#endif

#ifdef _GLOBAL_INSTANCE_
#define GLOBAL
#else _GLOBAL_INSTANCE_
#define GLOBAL extern
#endif


GLOBAL GameData gameData;

GLOBAL Player player;
GLOBAL PlayerBullet pl_bullet[PL_BULLET_MAX];
GLOBAL PlayerBomb pl_bomb;
GLOBAL SubWeaponManage pl_subWeapon;

GLOBAL Enemy enemy[ENEMY_MAX];
GLOBAL EnemyBullet en_bullet[EN_BULLET_MAX];
GLOBAL EnemyLazer en_lazer[EN_LAZER_MAX];

GLOBAL Boss boss;
GLOBAL BossBarrage bo_barrage[BO_BARRAGE_MAX];

GLOBAL EnemyBarrage en_barrage[EN_BARRAGE_MAX];

GLOBAL Item item[ITEM_MAX];