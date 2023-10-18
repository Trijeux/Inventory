#include "FonctionInventory.h"

#include <iostream>
#include <string>


std::string InputNameCard()
{
	std::string nameMap;
	std::cout << "Nom de la map : ";
	std::cin >> nameMap;
	std::cout << std::endl;

	return nameMap;
}
