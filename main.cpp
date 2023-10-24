#include <iostream>
#include "Inventory.h"

void main()
{
	bool game = true;
	int chooseAction;

	Inventory myInvent;
	Weapon weaponEquipped = myInvent.GetWeaponInit();

	//Welcome and program information
	std::cout << "Bonjour et bienvenu sur Inventory" << std::endl;
	std::cout << "Tu peux jouer avec ton Inventaire, quitter et revenir quand tu veux, car il y a des sauvgardes" << std::endl;
	std::cout << "Mais les potions sont sauvgadees entierement, par contre tout les autres objets (l'epee, l'arc et la carte) ne sauvgarde que la derniere creer" << std::endl;
	system("PAUSE");

	do
	{
		//Action choice
		system("cls");
		std::cout << "Que veux tu faire :" << std::endl;
		std::cout << "Creer un item (1)" << std::endl;
		std::cout << "Equiper une arme (2)" << std::endl;
		std::cout << "Utiliser la carte ou une potion (3)" << std::endl;
		std::cout << "Attaquer avec l'arme equipee (4)" << std::endl;
		std::cout << "Afficher le contenu de l'inventaire (5)" << std::endl;
		std::cout << "Quitter le jeu (6)" << std::endl;
		std::cin >> chooseAction;

		switch (chooseAction)
		{
		case 1:
		{
			system("cls");
			myInvent.Add();
			system("PAUSE");
			break;
		}
		case 2:
		{
			system("cls");
			weaponEquipped = myInvent.Equip();
			system("PAUSE");
			break;
		}
		case 3:
		{
			system("cls");
			myInvent.Use();
			system("PAUSE");
			break;
		}
		case 4:
		{
			system("cls");
			myInvent.Attack(weaponEquipped);
			system("PAUSE");
			break;
		}
		case 5:
		{
			system("cls");
			myInvent.Display(6);
			system("PAUSE");
				break;
		}
		case 6:
		{
			system("cls");
			std::cout << "Merci d'avoir utiliser Inventory" << std::endl;
			system("PAUSE");
			game = false;
			break;
		}
		default:
		{
			system("cls");
			std::cout << "Ce n'est pas une action valide" << std::endl;
			system("PAUSE");
			break;
		}
		}

	} while (game);
}
