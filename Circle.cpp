#include "Circle.h"

Circle::Circle(float r, sf::Color color) : r(r), color(color)
{
	circle.setFillColor(color);
	circle.setRadius(r);
}

void Circle::Update(float deltatime, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = circle.getPosition();
	sf::FloatRect bounds = circle.getGlobalBounds();

	int MoveSpeed = 200;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (position.x > 5) {
			circle.move(-1 * deltatime * MoveSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (position.x + bounds.width + 5 < windowSize.x) {
			circle.move(1 * deltatime * MoveSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (position.y + bounds.height + 5 < windowSize.y) {
			circle.move(0, 1 * deltatime * MoveSpeed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (position.y > 5) {
			circle.move(0, -1 * deltatime * MoveSpeed);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {

		circle.setScale(circle.getScale().x + 0.001, circle.getScale().y + 0.001);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {

		circle.setScale(circle.getScale().x - 0.001, circle.getScale().y - 0.001);
	}
}

void Circle::draw(sf::RenderWindow& window)
{
	window.draw(circle);
}

void Circle::move(float deltatime, int x, int y, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = circle.getPosition();
	sf::FloatRect bounds = circle.getGlobalBounds();

	int MoveSpeed = 200;

	if (x < 0)
	{
		if (position.x > 5) {
			circle.move(x * deltatime * MoveSpeed, 0);
		}
	}
	if (x > 0)
	{
		if (position.x + bounds.width + 5 < windowSize.x) {
			circle.move(x * deltatime * MoveSpeed, 0);
		}
	}
	if (y > 0)
	{
		if (position.y + bounds.height + 5 < windowSize.y) {
			circle.move(0, y * deltatime * MoveSpeed);
		}
	}
	if (y < 0)
	{
		if (position.y > 5) {
			circle.move(0, y * deltatime * MoveSpeed);
		}
	}

}

sf::FloatRect Circle::getbounds()
{
	return circle.getGlobalBounds();
}

bool Circle::intersect(sf::FloatRect rect)
{
	return circle.getGlobalBounds().intersects(rect);
}

void Circle::setColor(sf::Color color)
{
	circle.setFillColor(color);
}

Circle* Circle::clone()
{
	return new Circle(r, color);
}