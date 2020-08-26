
//all the library and enum data tpe
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;
#include<time.h>

#ifndef GAMEFUNCTION
#define GAMEFUNCTION

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10

const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 18000, 28000, 40000, 52000, 64000, 80000, 98000, 120000 };

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT,
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK,
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END,
};

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX,
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATACK,
	BATTLE_BACK,
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK,
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK,
};


struct _tagItem
{
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem tItem[INVENTORY_MAX];
	int	iItemCount;
	int iGold;
};

struct _tagPlayer
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	_tagItem tEquip[EQ_MAX];
	bool bEquip[EQ_MAX];
	_tagInventory tInventory;
};

struct _tagMonster
{
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;
	int iGoldMin;
	int iGoldMax;
};

struct _taglevelUpStatus
{
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHPMin;
	int iHPMax;
	int iMPMin;
	int iMPMax;
};


//furntion protoType

int InputInt(); //function to get user reposne and validate and return the choice
int OutputMainMenu();	//main menu

//funs related to battle 
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, _taglevelUpStatus* g_tLvUpTable);
void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster, _taglevelUpStatus* g_tLvUpTable);
void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu, _taglevelUpStatus* g_tLvUpTable);
int OutputBattleMenu();
int OutputMapMenu();
void OutputBattleTag(int iMenu);

//func related to player
void SetPlayer(_tagPlayer* pPlayer);
int SelectJob();
_taglevelUpStatus CreateLvStatus(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHPMin, int iHPMax, int iMPMin, int iMPMax);
void OutputPlayer(_tagPlayer* pPlayer);

//funcs related to creating monster
_tagMonster CreateMonster(const char* pName, int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iMP, int iLevel, int iExp, int iGoldMin, int iGoldMax);
void SetMonster(_tagMonster* pMonsterArr);
void OutputMonster(_tagMonster* pMonster);

//funcs related to store
int OutputStoreMenu();
int OutputStoreItemList(_tagInventory* pInventory, _tagItem* pStore, int iItemCount);
void BuyItem(_tagInventory* pInventory, _tagItem* pStore, int iItemCount, int iStoreType);
void RunStore(_tagInventory* pInventory, _tagItem* pWeapon, _tagItem* pArmor);
_tagItem CreateItem(const char* pName, ITEM_TYPE eType, int iMin, int iMax, int iPrice, int iSell, const char* pDesc);

//funcs related to inventory
int OutputInventory(_tagPlayer* pPlayer);
EQUIP ComputEquipType(ITEM_TYPE eType);
void RunInventory(_tagPlayer* pPlayer);
#endif // !GAMEFUNCTION
