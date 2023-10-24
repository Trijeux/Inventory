#pragma once
#include <vector>
#include "Bow.h"
#include "ForcePotion.h"
#include "HealthPotion.h"
#include "Map.h"
#include "Sword.h"

class Inventory
{
public:
	Inventory() { gameInit(); }
	~Inventory() { gameSavePotion(); }

	//Allow player to create an item
	void Add();

	//Allow player to use map or potion
	void Use();

	//Allow player to equip a weapon
	Weapon Equip();

	//Allow player to attack with equipped weapon
	void Attack(Weapon& equippedItem);

	//Show inventory
	void Display(int choose);


	Map GetMap(int chooseMap) { return MapStorage[chooseMap]; }
	int GetNbHealPotion() { return nbHealPotion; }
	int GetNbForcePotion() { return nbForcePotion; }
	Weapon GetWeaponInit() { return SwordsStorage[0]; }

private:

	std::vector<Map> MapStorage;
	std::vector<HealthPotion> HealthPotionStorage;
	std::vector<ForcePotion> ForcePotionStorage;
	std::vector<Sword> SwordsStorage;
	std::vector<Bow> BowStorage;


	int nbPotion;
	int nbHealPotion;
	int nbForcePotion;

	//Allow to initiate the last save
	void gameInit();

	//Allow to save potions when the player quit
	void gameSavePotion();

protected:
};

