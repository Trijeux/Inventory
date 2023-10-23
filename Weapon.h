#pragma once
#include "Item.h"


class Weapon : public Item
{
public:
	Weapon(std::string _name, int _dp) : Item(_name), DP(_dp) {}
	int GetDP() { return DP; }
private:
protected:
	int DP;
};

