#pragma once
#include "Figure.h"


class rectang : public Figure
{
private:
	float x;
	float y;
	sf::Color color;
	sf::RectangleShape rectangle;
public:
	rectang(float x, float y, sf::Color color);

	void Update(float deltatime, sf::RenderWindow& window) override;

	void draw(sf::RenderWindow& window) override;

	void add(Figure* a) override {}
	
	void remove(Figure* a) override { }
	
	void move(float deltatime, int x, int y, sf::RenderWindow& window) override;

	sf::FloatRect getbounds() override;

	bool intersect(sf::FloatRect rect) override;
	
	void setColor(sf::Color color) override;

	rectang* clone() override;

	bool check(float x, float y, sf::RenderWindow& window) override;
	
};