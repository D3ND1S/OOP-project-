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
		if (check(rectangle.getScale().x + 0.001, rectangle.getScale().y + 0.001, window))
			rectangle.setScale(rectangle.getScale().x + 0.001, rectangle.getScale().y + 0.001);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
		if (rectangle.getScale().x > 0.03 && rectangle.getScale().y > 0.03)
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

	rectangle.move(x * deltatime * MoveSpeed, y * deltatime * MoveSpeed);

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
	rectang* clone = new rectang(x, y, color);
	clone->rectangle = this->rectangle;
	return clone;
}

bool rectang::check(float x, float y, sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::Vector2f position = rectangle.getPosition();
	sf::FloatRect bounds = rectangle.getGlobalBounds();

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

bool rectang::checkScale(float x, sf::RenderWindow& window)
{
	bool result = true;

	if (x > 0)
	{
		if (!check(rectangle.getScale().x + 0.001, rectangle.getScale().y + 0.001, window))
			return false;
	}
	else if (x < 0)
	{
		if (rectangle.getScale().x < 0.03 && rectangle.getScale().y < 0.03)
			return false;
	}

	return result;
}

void rectang::updateScale(float x)
{
	rectangle.setScale(rectangle.getScale().x + x, rectangle.getScale().y + x);
}
