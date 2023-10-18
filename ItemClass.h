#pragma once
#include <string>
#include "InventoryClass.h"

class Item : public Inventory
{
public:
	Item(std::string name) : Name(name) {}

	void Use();
	std::string getName() { return Name; }

private:
	std::string Name;

protected:
};

