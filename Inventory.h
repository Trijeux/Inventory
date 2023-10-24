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
	void Add();
	void Use();
	Weapon Equip();
	void Attack(Weapon& equippedItem);
	void Display(int choise);


	Map GetMap(int choiseMap) { return MapStorage[choiseMap]; }
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
	void gameInit();
	void gameSavePotion();
protected:
};

