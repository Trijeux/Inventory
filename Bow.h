#pragma once
#include "Weapon.h"

class Bow :public Weapon
{
public:

    Bow(std::string _name, int _dp, int _distance) : Weapon(_name, _dp), distance(_distance) {}

    int GetDistance() { return distance; }

    int GetDP() { return DP; }

private:

    int distance;
};

