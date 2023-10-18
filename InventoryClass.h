#pragma once
#include <vector>
#include "ItemClass.h"

class Inventory
{
public:
	void Add(Item itemAdd);

	void Display();

private:
	std::vector<Item> ItemsStorage;

protected:
};

