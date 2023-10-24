#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "FonctionInventory.h"

using json = nlohmann::json;

void Inventory::Add()
{
	int choisePlayer;

	std::cout << "Quel item voulez vous creer :" << std::endl;
	std::cout << "Carte (1)" << std::endl << "Potion (2)" << std::endl << "Arme (3)" << std::endl;
	std::cin >> choisePlayer;

	switch (choisePlayer)
	{
	case 1:
	{
		json j;
		std::string nameItem = InputNameItem();

		Map itemAdd(nameItem);

		MapStorage.emplace_back(itemAdd);

		j["NameMap"] = nameItem;

		std::ofstream map("Map.json");
		map << std::setw(4) << j << std::endl;
		map.close();
		std::cout << "Vous avez creer " << nameItem << std::endl;
		break;
	}
	case 2:
	{
		int choisePotion;
		std::cout << "Quel type de potion" << std::endl;
		std::cout << "Soin (1) ou Force (2)" << std::endl;
		std::cin >> choisePotion;

		switch (choisePotion)
		{
		case 1:
		{
			std::string  nameItem = "HealthPotion";

			HealthPotion itemAdd(nameItem);

			nbHealPotion += 1;
			nbPotion += 1;

			HealthPotionStorage.emplace_back(itemAdd);
			std::cout << "Vous avez creer une potion de soin";
			break;
		}
		case 2:
		{
			std::string  nameItem = "ForcePotion";

			ForcePotion itemAdd(nameItem);

			nbForcePotion += 1;
			nbPotion += 1;

			ForcePotionStorage.emplace_back(itemAdd);
			std::cout << "Vous avez creer une potion de force";
			break;
		}
		}
		break;
	}
	case 3:
	{
		int choiseWeapon;

		std::cout << "Quel type d'arme voulez vous creer" << std::endl;
		std::cout << "Epee (1) ou Arc (2)" << std::endl;
		std::cin >> choiseWeapon;

		switch (choiseWeapon)
		{
		case 1:
		{
			json j;
			int dommage;
			int length;
			std::string  nameItem = InputNameItem();
			std::cout << "Les dommage de l'Epee" << std::endl;
			std::cin >> dommage;
			std::cout << "La longueur de la lame de l'Epee" << std::endl;
			std::cin >> length;

			Sword itemAdd(nameItem, dommage, length);

			SwordsStorage.emplace_back(itemAdd);

			j["NameSword"] = nameItem;
			j["DPS"] = dommage;
			j["BladeLenght"] = length;

			std::ofstream sword("Sword.json");
			sword << std::setw(4) << j << std::endl;
			sword.close();
			std::cout << "Vous avez creer " << nameItem << "Avec " << dommage << "de degat et avec une lame longue de " << length;
			break;
		}
		case 2:
		{
			json j;
			int dommage;
			int distance;
			std::string  nameItem = InputNameItem();
			std::cout << "Les dommage de l'arc" << std::endl;
			std::cin >> dommage;
			std::cout << "La distance de Tir de l'arc" << std::endl;
			std::cin >> distance;

			Bow itemAdd(nameItem, dommage, distance);

			BowStorage.emplace_back(itemAdd);

			j["NameBow"] = nameItem;
			j["DPS"] = dommage;
			j["Distance"] = distance;

			std::ofstream bow("Bow.json");
			bow << std::setw(4) << j << std::endl;
			bow.close();
			std::cout << "Vous avez creer " << nameItem << "Avec " << dommage << "de degat et avec une distance de tir de " << distance;
			break;
		}
		}
		break;
	}
	}
}

Weapon Inventory::Equip()
{
	int choise;
	int inputPlayer;

	// Attention aux numéros qui marchent pas
	std::cout << "Quel type arme voulez vous equipez : " << std::endl;
	std::cout << "Epee (2)" << std::endl;
	std::cout << "Arc (3)" << std::endl;
	std::cin >> choise;

	switch (choise)
	{

	case 2:
	{
		Display(choise);

		std::cin >> inputPlayer;

		Sword Epee = SwordsStorage[inputPlayer];

		std::cout << "Vous avez equiper " << Epee.GetName();

		return SwordsStorage[inputPlayer];
	}
	case 3:
	{
		Display(choise);

		std::cin >> inputPlayer;

		Bow bow = BowStorage[inputPlayer];

		std::cout << "Vous avez equiper " << bow.GetName();

		return BowStorage[inputPlayer];
	}
	}
}

void Inventory::Display(int choise)
{
	int idx = 0;
	switch (choise)
	{
	case 1:
	{
		for (Map oneItem : MapStorage)
		{
			std::cout << idx << ":" << oneItem.GetName() << std::endl;
			idx++;
		}
		break;
	}
	case 2:
	{
		for (Sword oneItem : SwordsStorage)
		{
			std::cout << idx << ":" << oneItem.GetName() << " DPS :" << oneItem.GetDP() << " / Taille de la Lame :" << oneItem.GetBladeLength() << std::endl;
			idx++;
		}
		break;
	}
	case 3:
	{
		for (Bow oneItem : BowStorage)
		{
			std::cout << idx << ":" << oneItem.GetName() << " DPS :" << oneItem.GetDP() << " / Distance de Tir :" << oneItem.GetDistance() << std::endl;
			idx++;
		}
		break;
	}
	case 4:
	{
		std::cout << "Nombre de Potion de Soin " << nbHealPotion << std::endl;
		for (HealthPotion oneItem : HealthPotionStorage)
		{
			std::cout << idx << ":" << oneItem.GetName() << std::endl;
			idx++;
		}
		break;
	}
	case 5:
	{
		std::cout << "Nombre de Potion de Force " << nbForcePotion << std::endl;
		for (ForcePotion oneItem : ForcePotionStorage)
		{
			std::cout << idx << ":" << oneItem.GetName() << std::endl;
			idx++;
		}
		break;
	}
	case 6:
		std::cout << "Map" << std::endl;
		for (Map oneItem : MapStorage)
		{
			std::cout << idx << ": " << oneItem.GetName() << std::endl;
			idx++;
		}

		std::cout << "Epee" << std::endl;
		for (Sword oneItem : SwordsStorage)
		{
			std::cout << idx << ":" << oneItem.GetName() << " DPS :" << oneItem.GetDP() << " / Taille de la Lame :" << oneItem.GetBladeLength() << std::endl;
			idx++;
		}

		std::cout << "Arc" << std::endl;
		for (Bow oneItem : BowStorage)
		{
			std::cout << idx << ":" << oneItem.GetName() << " DPS :" << oneItem.GetDP() << " / Distance de Tir :" << oneItem.GetDistance() << std::endl;
			idx++;
		}
		std::cout << std::endl;
		std::cout << "Nombre de Potion " << nbPotion << std::endl;
		std::cout << std::endl;

		std::cout << "Potion de Soin " << nbHealPotion << std::endl;
		for (HealthPotion oneItem : HealthPotionStorage)
		{
			std::cout << idx << ": " << oneItem.GetName() << std::endl;
			idx++;
		}

		std::cout << "Potion de Force " << nbForcePotion << std::endl;
		for (ForcePotion oneItem : ForcePotionStorage)
		{
			std::cout << idx << ": " << oneItem.GetName() << std::endl;
			idx++;
		}
	}

}

void Inventory::Use()
{
	int inputChoise;
	std::cout << "Que voulez vous utiliser :" << std::endl;
	std::cout << "Carte (1)" << std::endl;
	std::cout << "Potion de soin (2)" << std::endl;
	std::cout << "Potion de Force (3)" << std::endl;
	std::cin >> inputChoise;

	switch (inputChoise)
	{
	case 1:
	{
		int choisecard;
		std::cout << "Quel Cart voulez vous utiliser :" << std::endl;
		Display(1);
		std::cin >> choisecard;
		Item myMap = GetMap(choisecard);

		std::cout << "Vous etes a " << myMap.GetName() << std::endl;
		break;
	}
	case 2:
	{
		if (nbHealPotion > 0)
		{
			std::cout << "Vous vous etes Heal" << std::endl;
			nbPotion -= 1;
			nbHealPotion -= 1;
			HealthPotionStorage.erase(HealthPotionStorage.begin());
		}
		else if (nbHealPotion <= 0)
		{
			std::cout << "Vous n'avez plus de Potion de soin";
		}
		break;
	}
	case 3:
	{
		if (nbForcePotion > 0)
		{
			std::cout << "Vous vous etes Renforcer" << std::endl;
			nbPotion -= 1;
			nbForcePotion -= 1;
			ForcePotionStorage.erase(ForcePotionStorage.begin());
		}
		else if (nbForcePotion <= 0)
		{
			std::cout << "Vous n'avez plus de Potion de force";
		}
		break;
	}
	}
}

void Inventory::Attack(Weapon& equippedItem)
{
	std::cout << "Tu Attack de " << equippedItem.GetDP() << "avec " << equippedItem.GetName() << std::endl;
}

void Inventory::gameInit()
{
	json j;

	// Charger les données ----------------------------------------------------------
	std::ifstream map("Map.json");
	j = nlohmann::json::parse(map);
	std::string nameMap = j["NameMap"];
	map.close();
	Map mapAdd(nameMap);
	MapStorage.emplace_back(mapAdd);

	// Charger les données ----------------------------------------------------------
	std::ifstream sword("Sword.json");
	j = nlohmann::json::parse(sword);
	std::string nameSword = j["NameSword"];
	int DPSword = j["DPS"];
	int bladeLenght = j["BladeLenght"];
	sword.close();
	Sword swordAdd(nameSword, DPSword, bladeLenght);
	SwordsStorage.emplace_back(swordAdd);

	// Charger les données ----------------------------------------------------------
	std::ifstream bow("Bow.json");
	j = nlohmann::json::parse(bow);
	std::string nameBow = j["NameBow"];
	int DPSBow = j["DPS"];
	int distance = j["Distance"];
	bow.close();
	Bow bowAdd(nameBow, DPSBow, distance);
	BowStorage.emplace_back(bowAdd);

	// Charger les données ----------------------------------------------------------
	std::ifstream potionHeal("HealPotion.json");
	j = nlohmann::json::parse(potionHeal);
	int numberPotionHeal = j["NomberHealPotion"];
	potionHeal.close();
	for (int i = 0; i < numberPotionHeal; i++)
	{
		std::string  nameItem = "HealthPotion";

		HealthPotion potionHealAdd(nameItem);

		nbHealPotion += 1;
		nbPotion += 1;

		HealthPotionStorage.emplace_back(potionHealAdd);
	}

	// Charger les données ----------------------------------------------------------
	std::ifstream potionForce("ForcePotion.json");
	j = nlohmann::json::parse(potionForce);
	int numberPotionForce = j["NomberForcePotion"];
	potionForce.close();
	for (int i = 0; i < numberPotionForce; i++)
	{
		std::string  nameItem = "ForcePotion";

		ForcePotion potionForceAdd(nameItem);

		nbForcePotion += 1;
		nbPotion += 1;

		ForcePotionStorage.emplace_back(potionForceAdd);
	}
}

void Inventory::gameSavePotion()
{
	json j;

	j["NomberHealPotion"] = nbHealPotion;

	std::ofstream potionHeal("HealPotion.json");
	potionHeal << std::setw(4) << j << std::endl;
	potionHeal.close();

	j["NomberForcePotion"] = nbForcePotion;

	std::ofstream potionForce("ForcePotion.json");
	potionForce << std::setw(4) << j << std::endl;
	potionForce.close();
}
