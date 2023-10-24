#include <iostream>
#include <string>
#include <nlohmann/json.hpp>




std::string InputNameItem()
{
	std::string nameMap;
	std::cout << "Nom de l'Item : ";
	std::cin >> nameMap;
	std::cout << std::endl;

	return nameMap;
}
