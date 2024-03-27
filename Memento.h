#pragma once
#include "Figure.h"

class Controller;

class Memento
{
private:
	Figure* list[3]{};
	std::vector<Figure*> composites;
public:
	friend Controller;

	~Memento()
	{
		delete[] list;
		for (auto elem : composites)
		{
			delete elem;
		}
		composites.clear();
	}
};

