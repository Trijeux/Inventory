#pragma once
#include <string>

class Item
{
public:
	Item(std::string name) : Name(name) {}

	void Use();
	std::string getName() { return Name; }

private:
	std::string Name;

protected:
};

