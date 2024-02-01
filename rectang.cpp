#include "rectang.h"

rectang::rectang(float x, float y, sf::Color color) : x(x), y(y), color(color)
{
	rectangle.setFillColor(color);
	rectangle.setSize(sf::Vector2f(x, y));
	rectangle.setPosition(50, 50);
}

void rectang::Update(float deltatime, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = rectangle.getPosition();
	sf::FloatRect bounds = rectangle.getGlobalBounds();

	int MoveSpeed = 200;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (position.x > 5) {
			rectangle.move(-1 * deltatime * MoveSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (position.x + bounds.width + 5 < windowSize.x) {
			rectangle.move(1 * deltatime * MoveSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (position.y + bounds.height + 5 < windowSize.y) {
			rectangle.move(0, 1 * deltatime * MoveSpeed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (position.y > 5) {
			rectangle.move(0, -1 * deltatime * MoveSpeed);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {

		rectangle.setScale(rectangle.getScale().x + 0.001, rectangle.getScale().y + 0.001);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {

		rectangle.setScale(rectangle.getScale().x - 0.001, rectangle.getScale().y - 0.001);
	}
}

void rectang::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}

void rectang::move(float deltatime, int x, int y, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = rectangle.getPosition();
	sf::FloatRect bounds = rectangle.getGlobalBounds();

	int MoveSpeed = 200;

	if (x < 0)
	{
		if (position.x > 5) {
			rectangle.move(x * deltatime * MoveSpeed, 0);
		}
	}
	if (x > 0)
	{
		if (position.x + bounds.width + 5 < windowSize.x) {
			rectangle.move(x * deltatime * MoveSpeed, 0);
		}
	}
	if (y > 0)
	{
		if (position.y + bounds.height + 5 < windowSize.y) {
			rectangle.move(0, y * deltatime * MoveSpeed);
		}
	}
	if (y < 0)
	{
		if (position.y > 5) {
			rectangle.move(0, y * deltatime * MoveSpeed);
		}
	}

}

sf::FloatRect rectang::getbounds()
{
	return rectangle.getGlobalBounds();
}

bool rectang::intersect(sf::FloatRect rect)
{
	return rectangle.getGlobalBounds().intersects(rect);
}

void rectang::setColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

rectang* rectang::clone()
{
	return new rectang(x, y, color);
}
