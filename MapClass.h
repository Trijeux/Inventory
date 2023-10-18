#pragma once
#include "ItemClass.h"
#include <string>

class Map : public Item
{
public:
	Map(std::string _name) : Item(_name) {}
private:
};

