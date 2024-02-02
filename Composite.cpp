#include "Composite.h"

Composite* Composite::clone()
{
	Composite* temp = new Composite();
	for (Figure* elem : arr)
	{
		temp->add(elem->clone());
	}
	remove(nullptr);
	return temp;
}

void Composite::add(Figure* a)
{
	arr.push_back(a);
}

void Composite::remove(Figure* a)
{
	for (auto& figure : arr)
	{
		figure->remove(nullptr);
		arr.clear();
	}
}

void Composite::Update(float deltatime, sf::RenderWindow& window)
{
	int x, y;
	float scale;

	x = y = scale = 0;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		x = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		y = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {

		scale = 0.001;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {

		scale = -0.001;
	}

	for (auto& figure : arr)
	{
		if (figure->check(0, y * deltatime * 200, window) == false)
			y = 0;

		if (figure->check(x * deltatime * 200, 0, window) == false)
			x = 0;

		if (figure->checkScale(scale, window) == false)
			scale = 0;
	}

	for (auto* elem : arr)
	{
		elem->move(deltatime, x, y, window);
		elem->updateScale(scale);
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
	remove(nullptr);
}

bool Composite::check(float x, float y, sf::RenderWindow& window)
{
	bool result = true;
	for (auto& figure : arr)
	{
		result = figure->check(x, y, window);
		if (result == false)
			return false;
	}
	return result;
}

bool Composite::checkScale(float x, sf::RenderWindow& window)
{
	bool result = true;
	for (auto& figure : arr)
	{
		result = figure->checkScale(x, window);
		if (result == false)
			return false;
	}
	return result;
}
