#include "InventoryClass.h"
#include <iostream>


void Inventory::Add(Item itemToAdd)
{
	ItemsStorage.emplace_back(itemToAdd);
}


void Inventory::Display()
{
	int idx = 0;
	for (auto oneItem : ItemsStorage)
	{
		std::cout << idx << ":" << oneItem.getName() << std::endl;
		idx++;
	}

}