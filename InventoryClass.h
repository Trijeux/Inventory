#pragma once
#include <vector>
#include "ItemClass.h"

class Inventory
{
public:
	void Add(Item itemAdd);
	Item Equip(int number);
	void Display();

private:
	std::vector<Item> ItemsStorage;

protected:
};

