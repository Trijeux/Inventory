#pragma once
#include <vector>
#include "Bow.h"
#include "ForcePotion.h"
#include "HealthPotion.h"
#include "Map.h"
#include "Sword.h"
#include "Item.h"

class Inventory
{
public:
	void Add();
	Weapon Equip();
	void Display(int choise);
	Map GetMap(int choiseMap) { return MapStorage[choiseMap]; }
	void Use();
	void attack(Weapon& equippedItem);

private:
	std::vector<Map> MapStorage;
	std::vector<HealthPotion> HealthPotionStorage;
	std::vector<ForcePotion> ForcePotionStorage;
	std::vector<Sword> SwordsStorage;
	std::vector<Bow> BowStorage;
	int nbPotion;
	int nbHealPotion;
	int nbForcePotion;
protected:
};

