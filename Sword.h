#pragma once
#include "Weapon.h"


class Sword : public Weapon
{
public:
	Sword(std::string _name, int _dp, int _bladeLength) : Weapon(_name, _dp), bladeLength(_bladeLength) {}
	int GetBladeLength() { return bladeLength; }
	int GetDP() { return DP; }
private:
	int bladeLength;
};

