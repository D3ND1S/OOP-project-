#include "Prototype.h"

Figure* Prototype::load(std::string key)
{
	return map[key];
}

void Prototype::add(std::string key, Figure* figure)
{
	map[key] = figure->clone();
}

void Prototype::erase(std::string key)
{
	if (key == "all")
	{
		map.clear();
		return;
	}
	map.erase(key);
}

void Prototype::print()
{
	for (auto& elem : map)
	{
		std::cout << elem.first << std::endl;
	}
}


