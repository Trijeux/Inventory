#include <iostream>
#include "Inventory.h"

void main()
{
	bool game = true;
	int chooseAction;
	Inventory myInvent;
	Weapon weaponEquipped = myInvent.GetWeaponInit();

	std::cout << "Bonjour et bien venue sur Inventory" << std::endl;
	std::cout << "Tu peux peux jouer avec ton Inventaire quitter et revenir quand tu veux car il y a des sauvgarde" << std::endl;
	std::cout << "Mais les potion son sauvgader entièrment mais parcontre tout les autre objet (comme l'epee) ne sauvgarde que la dernière creer";
	system("PAUSE");

	do
	{
		system("cls");
		std::cout << "Que veux tu faire :" << std::endl;
		std::cout << "Creer un item (1)" << std::endl;
		std::cout << "Equiper une arme (2)" << std::endl;
		std::cout << "Utiliser la cart ou une Potion (3)" << std::endl;
		std::cout << "Attaquer avec l'arme equiper (4)" << std::endl;
		std::cout << "Afficher le contenue de l'inventaire (5)" << std::endl;
		std::cout << "Quitter le jeux (6)" << std::endl;
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
			std::cout << "Ce n'ai pas une action valide" << std::endl;
			system("PAUSE");
			break;
		}
		}

	} while (game);
}
