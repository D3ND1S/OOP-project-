#include "Composite.h"

Composite* Composite::clone()
{
	Composite* temp = new Composite();
	for (Figure* elem : arr)
	{
		temp->add(elem);
	}
	return temp;
}

void Composite::add(Figure* a)
{
	arr.push_back(a->clone());
}

void Composite::remove(Figure* a)
{
	int iterator = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == a)
		{
			iterator = i;
			break;
		}
	}
	arr.erase(arr.begin() + iterator);
}

void Composite::Update(float deltatime, sf::RenderWindow& window)
{
	for (Figure* elem : arr)
	{
		elem->Update(deltatime, window);
	}
}

void Composite::draw(sf::RenderWindow& window)
{
	for (Figure* elem : arr)
	{
		elem->draw(window);
	}
}

void Composite::move(float deltatime, int x, int y, sf::RenderWindow& window)
{
	for (Figure* elem : arr)
	{
		elem->move(deltatime, x, y, window);
	}
}

Composite::~Composite()
{
	for (Figure* elem : arr)
	{
		delete elem;
	}
}