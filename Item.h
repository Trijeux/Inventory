#pragma once
#include <string>

class Inventory;

class Item
{
public:

	Item(std::string name) : name(name) {}


	std::string GetName() { return name; }

private:

	std::string name;
	
protected:

};

