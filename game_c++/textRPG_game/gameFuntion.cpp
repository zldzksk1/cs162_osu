//cpp file

#include "gameFunction.hpp"


//validate the user input
int InputInt() 
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX; //if it return int_max, input is wrong;
	}

	return iInput;
}

//prompt main menu, and get an response, and return it
int OutputMainMenu()
{
	system("cls");
	cout << "******************LOBBY******************" << endl;
	cout << "1. Map" << endl;
	cout << "2. Store" << endl;
	cout << "3. Inventory" << endl;
	cout << "4. Exit" << endl;
	cout << "Please select menu: " << endl;
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;

	return iMenu;
}

//Func to prompt dungeon level and get response from a user
int OutputMapMenu()
{
	system("cls");
	cout << "******************MAP******************" << endl;
	cout << "1. Easy" << endl;
	cout << "2. Normal" << endl;
	cout << "3. Hard" << endl;
	cout << "4. Backward" << endl;
	cout << "Please select level: " << endl;

	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
		return MT_NONE;

	return iMenu;
}

//display the dungeon level tag
void OutputBattleTag(int iMenu)
{
	system("cls");
	switch (iMenu)
	{
	case MT_EASY:
		cout << "******************EASY******************" << endl;
		break;
	case MT_NORMAL:
		cout << "******************NORMAL******************" << endl;
		break;
	case MT_HARD:
		cout << "******************HARD******************" << endl;

		break;
	}
}

//Func to prompt battle menu and get response from a user
int OutputBattleMenu()
{
	cout << "1. Attack" << endl;
	cout << "2. Run Away" << endl;
	cout << "Please select a menu: ";

	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= BATTLE_NONE || iMenu > BATTLE_BACK)
		return BATTLE_NONE;
	return iMenu;
}

//In this function, OutputMapMenu() is implemented
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, _taglevelUpStatus* g_tLvUpTable)
{
	bool bLoop = true;

	while (bLoop)						//loop
	{

		int iMenu = OutputMapMenu();	//display Map Menu
	
		if (MT_BACK == iMenu)			//if user wants go back to previouse menu
			return;						//return nothing and break loop and function.

		//start combat
		else
			RunBattle(pPlayer, pMonsterArr, iMenu, g_tLvUpTable);
		
	}
}

//Function to process battle when user selects attack
void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster, _taglevelUpStatus* g_tLvUpTable)
{

	int iAttackMin = pPlayer->iAttackMin;										//Get current user's attack range
	int iAttackMax = pPlayer->iAttackMax;

	if (pPlayer->bEquip[EQ_WEAPON])												//if character equip a item
	{
		iAttackMin = pPlayer->iAttackMin + pPlayer->tEquip[EQ_WEAPON].iMin;		//get attack points of weapon
		iAttackMax = pPlayer->iAttackMax + pPlayer->tEquip[EQ_WEAPON].iMax;
	}

	int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;			//generate the attack points between min and max
	int iArmor = rand() % (pMonster->iArmorMax - pMonster->iArmorMax + 1) + pMonster->iArmorMin;		//calculate the monster's armor

	int iDamage = iAttack - iArmor;			//final dmg
	iDamage = iDamage < 1 ? 1 : iDamage;	//if dmg is less than 1 (monster's armor is much larger than play's attack) give dmg 1, other wise monster will get damage as much iDmage

	//update monster's hp
	pMonster->iHP -= iDamage;
	cout << pPlayer->strJobName << " gave damage " << iDamage << " to " << pMonster->strName << endl;	//prompt msg

	if (pMonster->iHP <= 0)		//if monster hp less or equal to 0, then monster dead
	{
		cout << pMonster->strName << " Dead" << endl;
		pPlayer->iExp += pMonster->iExp;				//user gets exp
		int iGold = rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) + pMonster->iGoldMin;		//monster drops golds
		pPlayer->tInventory.iGold += iGold;		//obtain gold

		cout << "Obtained Exp: " << pMonster->iExp << "\t Gold: " << iGold << endl;

		//recover the monster's HP and MP, for new game later
		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1])	//if user's exp exceed the level up exp limit
		{
			pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];	//then level up
			pPlayer->iLevel++;

			cout << "Level Up!" << endl;

			//inhence player's status
			int	iJobIndex = pPlayer->eJob - 1;
			int iHPUp = rand() % (g_tLvUpTable[iJobIndex].iHPMax - g_tLvUpTable[iJobIndex].iHPMin + 1) + g_tLvUpTable[iJobIndex].iHPMin;
			int iMPUp = rand() % (g_tLvUpTable[iJobIndex].iMPMax - g_tLvUpTable[iJobIndex].iMPMax + 1) + g_tLvUpTable[iJobIndex].iMPMax;

			pPlayer->iAttackMin += g_tLvUpTable[iJobIndex].iAttackMin;	//attack min increased
			pPlayer->iAttackMax += g_tLvUpTable[iJobIndex].iAttackMax;	//attack max increased
			pPlayer->iArmorMin += g_tLvUpTable[iJobIndex].iArmorMin;	//armor min increased
			pPlayer->iArmorMax += g_tLvUpTable[iJobIndex].iArmorMax;	//armor max increased
			pPlayer->iHPMax += iHPUp;	//HP up
			pPlayer->iMPMax += iMPUp;	//MP up

			//recover the HP & MP
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}
		return;
	}

	// if moster is still alive, then attack player
	iAttack = rand() % (pMonster->iAttackMax - pMonster->iAttackMin + 1) + pMonster->iAttackMin;	//attack points

	int iArmorMin = pPlayer->iArmorMin;		//get player's armor points
	int iArmorMax = pPlayer->iArmorMax;

	if (pPlayer->bEquip[EQ_ARMOR])	//if player's equip armor item
	{
		iArmorMin = pPlayer->iArmorMin + pPlayer->tEquip[EQ_ARMOR].iMin;	//then add up the armor points
		iArmorMax = pPlayer->iArmorMax + pPlayer->tEquip[EQ_ARMOR].iMax;
	}

	iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

	iDamage = iAttack - iArmor;			//calculate the dmg for player
	iDamage = iDamage < 1 ? 1 : iDamage;

	pPlayer->iHP -= iDamage;	//update the player's hp
	cout << pPlayer->strJobName << " received damage " << iDamage << " from " << pMonster->strName << endl;

	//player dead
	if (pPlayer->iHP <= 0)	//if player's hp less of equal to 0
	{
		cout << pPlayer->strName << " Dead" << endl;

		int iExp = pPlayer->iExp * 0.1f;		//lost exp
		int iGold = pPlayer->tInventory.iGold * 0.1f;		//lost gold

		pPlayer->iExp -= iExp;
		pPlayer->tInventory.iGold -= iGold;

		cout << "Player lost Exp: " << iExp << "\t Gold: " << iGold << endl;		//prompt how many exp and gold they lost
		pPlayer->iHP = pPlayer->iHPMax;	//recover HP and MP
		pPlayer->iMP = pPlayer->iMPMax;

	}
}

//
void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu, _taglevelUpStatus* g_tLvUpTable)
{
	_tagMonster tMonster = pMonsterArr[iMenu - 1];

	while (true)
	{
		system("cls");
		OutputBattleTag(iMenu);		//display game level

		OutputPlayer(pPlayer);		//display player info
		OutputMonster(&tMonster);	//display monster info

		switch (OutputBattleMenu())
		{
		case BATTLE_ATACK:	//attack 
			Battle(pPlayer, &tMonster, g_tLvUpTable);
			system("pause");
			break;
		case BATTLE_BACK:	//run away
			return;
		}
	}
}

//set players
void SetPlayer(_tagPlayer* pPlayer)
{
	cout << "Player Name: ";				//set plyaer name;
	cin.getline(pPlayer->strName, NAME_SIZE - 1);
	pPlayer->eJob = (JOB)SelectJob();		//get an user response using SelectJob() and cast it enum type

	pPlayer->iLevel = 1;			//set initial level
	pPlayer->iExp = 0;				//set initial exp
	pPlayer->tInventory.iGold = 10000;		//set initial gold

	switch (pPlayer->eJob)	//player will have differnet stats based on their job(class)
	{
	case JOB_KNIGHT:	//user chose Knights
		strcpy_s(pPlayer->strJobName, "Knights");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMax = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMPMax = 100;
		pPlayer->iMP = 100;
		break;
	case JOB_ARCHER:	//user chose Archer
		strcpy_s(pPlayer->strJobName, "Archer");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 15;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMPMax = 200;
		pPlayer->iMP = 200;
		break;	
	case JOB_WIZARD:	 //user chose Wizard
		strcpy_s(pPlayer->strJobName, "Wizard");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMax = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMPMax = 300;
		pPlayer->iMP = 300;
		break;
	}
}

//func to allow users to choose a character class
int SelectJob()
{
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "******************LOBBY******************" << endl;
		cout << "1. Knight" << endl;
		cout << "2. Archer" << endl;
		cout << "3. Wizard" << endl;
		cout << "Please select your class: " << endl;
		iJob = InputInt();

		if (iJob == INT_MAX || iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}
	return iJob;	//return int val

}

//func to improve status of character when player's level is up
_taglevelUpStatus CreateLvStatus(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHPMin, int iHPMax, int iMPMin, int iMPMax)
{
	_taglevelUpStatus tStatus = {};

	tStatus.iAttackMin = iAttackMin;
	tStatus.iAttackMax = iAttackMax;
	tStatus.iArmorMin = iArmorMin;
	tStatus.iArmorMax = iArmorMax;
	tStatus.iHPMin = iHPMin;
	tStatus.iHPMax = iHPMax;
	tStatus.iMPMin = iMPMin;
	tStatus.iMPMax = iMPMax;

	return tStatus;
}

//func to prompot player's information: level, gold, exp, hp, mp and all other info
void OutputPlayer(_tagPlayer* pPlayer)
{
	//player info
	cout << "******************Player******************" << endl;
	cout << "Name: " << pPlayer->strName << "\tClass: " << pPlayer->strJobName << endl;
	cout << "Lv: " << pPlayer->iLevel << "\tExp: " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;


	if (pPlayer->bEquip[EQ_WEAPON] == true)		//if user equip a weapon, display weapon atk point as well
	{
		cout << "Atk: " << pPlayer->iAttackMin << " + " << pPlayer->tEquip[EQ_WEAPON].iMin << " - " <<
			pPlayer->iAttackMax << " + " << pPlayer->tEquip[EQ_WEAPON].iMax << endl;

	}

	else
	{
		cout << "Atk: " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMax << endl;
	}

	if (pPlayer->bEquip[EQ_ARMOR] == true)	//if user equip a armor, display armor defense point as well
	{
		cout << "Amr: " << pPlayer->iArmorMin << " + " << pPlayer->tEquip[EQ_ARMOR].iMin << " - " <<
			pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax << endl;

	}

	else
	{
		cout << "Amr: " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	}


	cout << "HP: " << pPlayer->iHP << "/" << pPlayer->iHPMax << "\tMP: " << pPlayer->iMP << "/" << pPlayer->iMPMax << endl;
	cout << "Gold: " << pPlayer->tInventory.iGold << " Gold" << endl << endl;

}

//func to creat monster
_tagMonster CreateMonster(const char* pName, int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iMP, int iLevel, int iExp, int iGoldMin, int iGoldMax)
{
	_tagMonster tMonster = {};		//struct type of variable

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHPMax = iHP;
	tMonster.iHP = iHP;
	tMonster.iMPMax = iMP;
	tMonster.iMP = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;

	return tMonster;
}

//set Monsters for diffenet game level
void SetMonster(_tagMonster* pMonsterArr)
{
	pMonsterArr[0] = CreateMonster("Goblin", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);	//for easy mode
	pMonsterArr[1] = CreateMonster("Troll", 80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);	//normal mode
	pMonsterArr[2] = CreateMonster("Dragon", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);	//hard mode
}

//func to prompt monster info
void OutputMonster(_tagMonster* pMonster)
{
	cout << "******************Monster******************" << endl;
	cout << "Name: " << pMonster->strName << "\tClass: " << "Lv: " << pMonster->iLevel << endl;
	cout << "Atk: " << pMonster->iAttackMin << "-" << pMonster->iAttackMax << "\tAmr: " << pMonster->iArmorMin << "-" << pMonster->iArmorMax << endl;
	cout << "HP: " << pMonster->iHP << "/" << pMonster->iHPMax << "\tMP: " << pMonster->iMP << "/" << pMonster->iMPMax << endl;
	cout << "Gained Exp: " << pMonster->iExp << "\tGained Gold: " << pMonster->iGoldMin << "-" << pMonster->iGoldMax << endl << endl;

}

//func to display store menu
int OutputStoreMenu()
{
	while (true)
	{
		system("cls");
		cout << "******************STORE******************" << endl;
		cout << "1. Weapon Shop" << endl;
		cout << "2. Armor Shop" << endl;
		cout << "3. Back" << endl;
		cout << "Please select a menu" << endl;
		int iMenu = InputInt();

		if (iMenu < SM_NONE || iMenu > SM_BACK)
			return SM_NONE;

		return iMenu;	//return user's response
	}
}

//Display item list, and get user's reponse
int OutputStoreItemList(_tagInventory* pInventory, _tagItem* pStore, int iItemCount)
{
	//prompt items information 
	for (int i = 0; i < iItemCount; i++)
	{
		cout << i + 1 << ". NAME: " << pStore[i].strName << "\tTYPE: " << pStore[i].strTypeName << endl;
		cout << "Attack Power: " << pStore[i].iMin << "-" << pStore[i].iMax << endl;
		cout << "Buy Price: " << pStore[i].iPrice << "\tSell Price: " << pStore[i].iSell << endl;
		cout << "Description: " << pStore[i].strDesc << endl << endl;
	}

	cout << iItemCount + 1 << ". Back" << endl << endl;	//display back option
	cout << "GOLD: " << pInventory->iGold << endl;	//player's gold
	cout << "SPACE: " << INVENTORY_MAX - pInventory->iItemCount << endl;	//player's inventory space
	cout << "Select an item to purchase: ";
	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > iItemCount + 1)
		return INT_MAX;

	return iMenu;
}

//func to buy an item at Store
void BuyItem(_tagInventory* pInventory, _tagItem* pStore, int iItemCount, int iStoreType)
{
	while (true)
	{
		system("cls");
		switch (iStoreType)	//prompt shop name based on store type
		{
		case SM_WEAPON:
			cout << "******************WEAPON-STORE******************" << endl;
			break;
		case SM_ARMOR:
			cout << "******************ARMOR-STORE******************" << endl;
			break;
		}
		int iInput = OutputStoreItemList(pInventory, pStore, iItemCount);	//display item list via OutputStoreItemList() and get user response

		if (iInput == INT_MAX)
		{
			cout << "Entered wrong input" << endl;
			system("pause");
			continue;
		}

		else if (iInput == iItemCount + 1)	//when user select 'back to previouse menu'
			break;

		int iIndex = iInput - 1;

		//check inventory
		if (pInventory->iItemCount == INVENTORY_MAX)	//when ionventory is full
		{
			cout << "You can't purchase more item, your bag is full" << endl;
			system("pause");
			continue;
		}

		//not enough gold
		else if (pInventory->iGold < pStore[iIndex].iPrice)
		{
			cout << "You need more gold" << endl;
			system("pause");
			continue;
		}

		//add item into player inventory
		pInventory->tItem[pInventory->iItemCount] = pStore[iIndex];

		//inrease the player's inventory 
		pInventory->iItemCount++;

		//gold spent
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << "You purchased " << pStore[iIndex].strName << endl;
		system("pause");
	}
}

//func to run store
void RunStore(_tagInventory* pInventory, _tagItem* pWeapon, _tagItem* pArmor)
{
	while (true)
	{
		switch (OutputStoreMenu())	//display store menu and get response via OutputStoreMenu()
		{
		case SM_WEAPON:
			BuyItem(pInventory, pWeapon, STORE_WEAPON_MAX, SM_WEAPON);
			break;
		case SM_ARMOR:
			BuyItem(pInventory, pArmor, STORE_ARMOR_MAX, SM_ARMOR);
			break;
		case SM_NONE:
			break;
		case SM_BACK:
			return;
		}
	}
}

//func to creat item
_tagItem CreateItem(const char* pName, ITEM_TYPE eType, int iMin, int iMax, int iPrice, int iSell, const char* pDesc)
{
	_tagItem tItem = {};	//struct type of varaible
	strcpy_s(tItem.strName, pName);	//set item name
	strcpy_s(tItem.strDesc, pDesc);	//set item description

	//and set item type and other information
	tItem.eType = eType;

	switch (eType)
	{
	case IT_WEAPON:
		strcpy_s(tItem.strTypeName, "Weapon");
		break;
	case IT_ARMOR:
		strcpy_s(tItem.strTypeName, "Armor");
		break;
	}

	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;

	return tItem;	//return item
}

//func to show items in player's inventory, and get user response to equip the item
int OutputInventory(_tagPlayer* pPlayer)
{
	system("cls");
	cout << "******************INVENTORY******************" << endl;	//prompt location msg
	OutputPlayer(pPlayer);

	for (int i = 0; i < pPlayer->tInventory.iItemCount; i++)	//using for loop, prompt all items in inventory
	{
		cout << i + 1 << ". NAME: " << pPlayer->tInventory.tItem[i].strName << "\tTYPE: " << pPlayer->tInventory.tItem[i].strTypeName << endl;
		cout << "Attack Power: " << pPlayer->tInventory.tItem[i].iMin << "-" << pPlayer->tInventory.tItem[i].iMax << endl;
		cout << "Buy Price: " << pPlayer->tInventory.tItem[i].iPrice << "\tSell Price: " << pPlayer->tInventory.tItem[i].iSell << endl;
		cout << "Description: " << pPlayer->tInventory.tItem[i].strDesc << endl << endl;
	}

	//get user resposne 
	cout << pPlayer->tInventory.iItemCount + 1 << ". Backward" << endl << endl;
	cout << "Please select an time to equip: " << endl;
	int iMenu = InputInt();

	if (iMenu < 1 || iMenu > pPlayer->tInventory.iItemCount + 1)
		return INT_MAX;

	return iMenu;
}

//func to equip item
EQUIP ComputEquipType(ITEM_TYPE eType)
{
	EQUIP eq;

	switch (eType)
	{
	case IT_WEAPON:
		eq = EQ_WEAPON;		//if user decide to equip weapon, declare variable with item that used chose
		break;
	case IT_ARMOR:
		eq = EQ_ARMOR;		//if user decide to equip armor, declare variable with item that used chose
		break;
	}

	return eq;		//return
}

//func to run inventory option
void RunInventory(_tagPlayer* pPlayer)
{
	while (true)
	{
		int iInput = OutputInventory(pPlayer);	//prompt all items in inventory and get user response via OutputInventory()

		if (iInput == INT_MAX)
			continue;

		else if (iInput == pPlayer->tInventory.iItemCount + 1)	//when user chose to move back
			break;

		int idx = iInput - 1;

		EQUIP eq = ComputEquipType(pPlayer->tInventory.tItem[idx].eType);	//player equip item

		//if player equiped an item already, replace it with new one
		if (pPlayer->bEquip[eq] == true)
		{
			_tagItem tSwap = pPlayer->tEquip[eq];	//temp item
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];	//move old item to temp
			pPlayer->tInventory.tItem[idx] = tSwap;		//equip new item
		}

		//if nothing equiped, then equip the item, then inventory space will have one slot
		else
		{
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];

			for (int i = idx; i < pPlayer->tInventory.iItemCount; i++)
			{
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}
			pPlayer->tInventory.iItemCount--;	//since item is equiped, so inventy space have one empty space

			pPlayer->bEquip[eq] = true;
		}

		cout << pPlayer->tEquip[eq].strName << " is equiped" << endl;	//let user knows the item is equiped.

		system("puase");
	}
}

