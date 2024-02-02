#include "Composite.h"

Composite* Composite::clone()
{
	Composite* temp = new Composite();
	for (Figure* elem : arr)
	{
		temp->add(elem->clone());
	}
	return temp;
}

void Composite::add(Figure* a) // Переробити щоб клон не створювався походу, а вже йшло посилання на клона
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

	x = y = 0;

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

	for (auto& figure : arr)
	{
		if (figure->check(0, y * deltatime * 200, window) == false)
			return;

		if (figure->check(x * deltatime * 200, 0, window) == false)
			return;

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) { // BETA

		//	circle.setScale(circle.getScale().x + 0.001, circle.getScale().y + 0.001);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {

		//   circle.setScale(circle.getScale().x - 0.001, circle.getScale().y - 0.001);
		//} 
	}

	for (auto* elem : arr)
	{
		elem->move(deltatime, x, y, window);
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
		if (result = false)
			return false;
	}
	return result;
}
