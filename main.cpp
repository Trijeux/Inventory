#include <iostream>
#include "FonctionInventory.h"
#include "InventoryClass.h"
#include "ItemClass.h"
#include "MapClass.h"

void main()
{
	Inventory invClass;

    for (int i = 0; i < 10; i++)
    {
        std::string nameMap = InputNameCard();

        Map itemToAdd(nameMap);

        invClass.Add(itemToAdd);

    }

    invClass.Display();

    int inputPlayerTemp;
	std::cout << "Cart a utiliser : ";
	std::cin >> inputPlayerTemp;

	    Item monItem = invClass.Equip(inputPlayerTemp);
    	monItem.Use();

}
