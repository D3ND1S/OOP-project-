#include "triang.h"

triang::triang(sf::Color color) : color(color)
{
	triangle.setFillColor(color);
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(200, 100));
	triangle.setPoint(1, sf::Vector2f(300, 100));
	triangle.setPoint(2, sf::Vector2f(250, 50));
	triangle.setOrigin(sf::Vector2f(200, 50));
}

void triang::Update(float deltatime, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = triangle.getPosition();
	sf::FloatRect bounds = triangle.getGlobalBounds();

	int MoveSpeed = 200;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (position.x > 5) {
			triangle.move(-1 * deltatime * MoveSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (position.x + bounds.width + 5 < windowSize.x) {
			triangle.move(1 * deltatime * MoveSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (position.y + bounds.height + 5 < windowSize.y) {
			triangle.move(0, 1 * deltatime * MoveSpeed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (position.y > 5) {
			triangle.move(0, -1 * deltatime * MoveSpeed);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {

		triangle.setScale(triangle.getScale().x + 0.001, triangle.getScale().y + 0.001);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {

		triangle.setScale(triangle.getScale().x - 0.001, triangle.getScale().y - 0.001);
	}
}



void triang::draw(sf::RenderWindow& window)
{
	window.draw(triangle);
}

void triang::move(float deltatime, int x, int y, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = triangle.getPosition();
	sf::FloatRect bounds = triangle.getGlobalBounds();

	int MoveSpeed = 200;
	
	triangle.move(x * deltatime * MoveSpeed, y * deltatime * MoveSpeed);
}

sf::FloatRect triang::getbounds()
{
	return triangle.getGlobalBounds();
}

bool triang::intersect(sf::FloatRect rect)
{
	return triangle.getGlobalBounds().intersects(rect);
}

void triang::setColor(sf::Color color)
{
	triangle.setFillColor(color);
}

triang* triang::clone()
{
	triang* clone = new triang(color);
	clone->triangle = this->triangle;
	return clone;
}

bool triang::check(float x, float y, sf::RenderWindow& window)
{

	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = triangle.getPosition();
	sf::FloatRect bounds = triangle.getGlobalBounds();

	if (x < 0)
	{
		if (position.x < 5) {
			return false;
		}
	}
	if (x > 0)
	{
		if (position.x + bounds.width + 5 > windowSize.x) {
			return false;
		}
	}
	if (y > 0)
	{
		if (position.y + bounds.height + 5 > windowSize.y) {
			return false;
		}
	}
	if (y < 0)
	{
		if (position.y < 5) {
			return false;
		}
	}

	return true;
}
