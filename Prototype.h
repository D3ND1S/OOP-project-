#pragma once
#include <unordered_map>
#include <string>
#include "Figure.h"

class Prototype
{
private:
	std::unordered_map<std::string, Figure*> map;

public:

	Figure* load(std::string key);

	void add(std::string key, Figure* figure);

	void erase(std::string key);

	bool print();


};

