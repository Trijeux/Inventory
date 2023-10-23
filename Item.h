#pragma once
#include <string>

class Inventory;

class Item
{
public:
	Item(std::string name) : Name(name) {}
	std::string GetName() { return Name; }

private:
	std::string Name;
	
protected:

};

