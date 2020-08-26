/*************************************************************************************************************************
**	program: play.cpp
**	Author: Sangyun Lee
**	Description: This is to practice game programming. I wrote this code and majority of the code were adopted from the 
**				 online lecture from Assort Rock Game Academy.
**				 Purpose of this coding practice is to understand the game data structure. It is very baic game player,
**				 but good practice to see how game should be ran and desgined.
**************************************************************************************************************************/


#include"gameFunction.hpp"	//incldue game function header file

int main()
{
	srand((unsigned int)time(0));	//srand to offset the pattern of rand()

	//define player
	_tagPlayer tPlayer = {};
	SetPlayer(&tPlayer);

	//declare the monster and set
	_tagMonster tMonsterArr[MT_BACK - 1] = {};
	SetMonster(tMonsterArr);

	//level up table
	_taglevelUpStatus g_tLvUpTable[JOB_END - 1] = {};

	//declare levelup status
	g_tLvUpTable[JOB_KNIGHT - 1] = CreateLvStatus(4, 10, 8, 16, 50, 100, 10, 20);
	g_tLvUpTable[JOB_ARCHER - 1] = CreateLvStatus(10, 15, 5, 10, 30, 60, 30, 50);
	g_tLvUpTable[JOB_WIZARD - 1] = CreateLvStatus(15, 20, 3, 7, 20, 40, 50, 100);

	//Item list on store
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	//set up items
	tStoreWeapon[0] = CreateItem("Wooden Sword", IT_WEAPON, 5, 10, 1000, 500, "It made by wood");
	tStoreWeapon[1] = CreateItem("Wooden Bow", IT_WEAPON, 20, 10, 7000, 3500, "It made by wood");
	tStoreWeapon[2] = CreateItem("Wooden Wand", IT_WEAPON, 90, 150, 30000, 15000, "It made by wood");

	tStoreArmor[0] = CreateItem("Fabric Armor", IT_ARMOR, 2, 5, 1000, 500, "It made by wood");
	tStoreArmor[1] = CreateItem("Leather Armor", IT_ARMOR, 10, 20, 7000, 3500, "It made by leather");
	tStoreArmor[2] = CreateItem("Steel Armor", IT_ARMOR, 70, 90, 30000, 15000, "It made by steel");

	//run game
	bool bLoop = true;
	while (bLoop)
	{
		switch (OutputMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr, g_tLvUpTable);
			break;
		case MM_STORE:
			RunStore(&tPlayer.tInventory, tStoreWeapon, tStoreArmor);
			break;
		case MM_INVENTORY:
			RunInventory(&tPlayer);
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}

	return 0;
}