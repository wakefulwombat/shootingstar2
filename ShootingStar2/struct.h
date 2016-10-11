#ifndef _DEFINE_
#include "define.h"
#define _DEFINE_
#endif


enum GameStatusStage{
	stage_start,
	stage_game=99,
	stage_end=100
};

////////////////////データ///////////////////////////////
struct Size{
	int width;
	int height;
};

struct Position{
	double x,y;
};

enum En_BulletKind{
	eb_small,
	eb_middle,
	eb_large,
	eb_crystal,
	eb_fuda,
	eb_gun,
	eb_knife,
	eb_kunai,
	eb_money,
	eb_niddle,
	eb_oval,
	eb_snow,
	eb_star_s,
	eb_star_l,
	eb_lazer
};

enum Bul_Color{
	bul_red,
	bul_orange,
	bul_yellow,
	bul_green,
	bul_waterblue,
	bul_blue,
	bul_purple,
	bul_white
};


struct StaticEnemyData{
	bool validable;//有効性
	int appearTime,charaKind,HP_MAX;
	Position startPos,stopPos;
	int movePattern,itemDropPattern;
	int move_bet_time,wait_time;
	double move_v,move_rad;
};

struct StaticEnemyShotData{//弾幕に関するデータ
	int attackPattern,shotMovePattern;
	int shotStartTime;
	double shot_v,shot_rad;
	En_BulletKind shot_kind;
	Bul_Color shot_bul_color;
	int small_group_num,small_group_bet_time,large_group_num,large_group_bet_time,total_group_num;
	double param1,param2;//任意のパラメータ
};

struct StaticBossMoveData{
	Position startPos;
	int movePattern;
	int movingBetTime,waitTime;
	int HP_MAX,itemDropPattern;
};

struct StaticBossBarrageData{
	int attackPattern,movePattern,shotMovePattern;
	int shotStartTime;
	double shot_v,shot_trans_rad,shot_rot_rad,move_v,move_trans_rad;
	En_BulletKind shot_kind;
	Bul_Color shot_bul_color;
	int small_group_num,small_group_bet_time,large_group_num,large_group_bet_time,whole_time;
	Position startPos;
	double param1,param2,param3;//任意のパラメータ
};

struct StageData{
	int c,stage;
	long score,scoreHold;
	int backScroll_y;
	StaticEnemyData enemyData[EN_ORDER_MAX];
	StaticEnemyShotData enemyShotData[EN_ORDER_MAX][3];
};

struct ChipData{
	int back[4];
	int board[4];
	int explode[15];
	int player[3];
	int pl_bomb;
	int pl_status[3];
	int enemy[EN_KIND_MAX][24];
	int e_bullet[15][8];//[kind][color]
	int e_spell;
	int pl_subwep;
	int boss_lifeBar;
	int item[2][4];//[size][kind]
};

enum MusicList{
	m_st1,m_st1_b,
	m_st2,m_st2_b,
	m_st3,m_st3_b,
	m_st4,m_st4_b
};

enum SoundList{

};

enum Direction{
	dir_down,
	dir_left,
	dir_right,
	dir_up,
	dir_downleft,
	dir_upleft,
	dir_downright,
	dir_upright
};


enum ItemSize{
	item_small,
	item_large
};

enum ItemKind{
	item_power,
	item_bomb,
	item_score,
	item_life
};

enum CharaStatus{
	normal,
	dead,
	recovering,
	invincible,
	preparing
};

enum BossStatus{
	b_preparing,
	b_normal,
	b_next_preparing,
	b_dead
};

enum ItemStatus{
	i_appearing,
	i_normal,
	i_collecting,
	i_collecting_near
};

enum SubWeaponPost{
	front_curve,
	side_curve,
	back_curve
};

struct GameData{
	ChipData chip;
	Size eb_size[15];
	StageData stageData;
	char key[256];
	int bossTotalAttack_c;
	GameStatusStage gameStatusStage;
};

/////////////////////////////////////////////////////////


///////////////////////オブジェクト//////////////////////

struct Player{
	Position pos;
	double v,shot_v,chip_rad;
	int c,shot_c;
	CharaStatus status;
	double power,bomb;
	int shot_power,bomb_power;
	int life;
	SubWeaponPost attack_pattern;
};

struct PlayerSubWeapon{
	Position pos;
	bool shot_f[3];
	int power[3];
	double shot_bul_rad[3],shot_v[3];
	Bul_Color shot_bul_color[3];
};

struct SubWeaponManage{
	int c;
	double chip_rad;
	PlayerSubWeapon subWeapon[PL_SUBWEAPON_MAX];
};

struct PlayerBullet{
	Position pos;
	double v,rad;
	int power;
	bool f,playerShot;
	int c;
	Bul_Color color;
};

struct PlayerBomb{
	Position pos;
	bool f;
	int c;
	double v,rot_rad;
};

struct Enemy{
	Position pos;
	bool f;
	int c;
	Direction direction;
	StaticEnemyData* staticData;
	StaticEnemyShotData *staticShotData[3];
	CharaStatus status;
	int HP;
	double chip_rad,trans_rad;
};

struct EnemyBullet{
	Position pos;
	bool f;
	int c,movePattern,shot_e_index;
	double v,trans_rad;
	double param1,param2;
	En_BulletKind kind;
	Bul_Color color;
};

struct EnemyLazerDiv{
	bool start,end,f;
	Position center;
	double rad;
	int c;
};

struct EnemyLazer{
	EnemyLazerDiv lazerDiv[EN_LAZER_DIV_MAX];
	Position startPos,controlPos,endPos;
	int c,movePattern,div_num,div_c,e_index;
	bool f;
	double v,trans_rad;
	Bul_Color color;
};

struct EnemyBarrage{//弾幕生成構造体
	bool f;
	int c,e_index;
	double shot_v,shot_rad;
	int small_group_num_c,small_group_bet_time_c,large_group_num_c,large_group_bet_time_c,total_group_num_c;
	StaticEnemyShotData* staticData;
};

struct Item{
	bool f;
	int c;
	double trans_rad,v;
	Position pos;
	ItemSize size;
	ItemKind kind;
	ItemStatus status;
};

struct Boss{
	bool f;
	int c,HP,charaKind;
	int attack_c,attack_num;
	double chip_rad,trans_rad;
	Direction direction;
	BossStatus status;
	Position pos,startPos,stopPos;
	StaticBossMoveData moveData;
	StaticBossBarrageData barrageData[BO_BARRAGE_MAX];
};

struct BossBarrage{
	bool f;
	int c;
	double shot_v,shot_rad,move_v,move_trans_rad;
	int small_group_num_c,small_group_bet_time_c,large_group_num_c,large_group_bet_time_c;
	StaticBossBarrageData* staticData;
	Position pos;
};