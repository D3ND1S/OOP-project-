#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	float r;
	sf::Color color;
	sf::CircleShape circle;
public:

	Circle(float r, sf::Color color); 

	void Update(float deltatime, sf::RenderWindow& window) override;

	void draw(sf::RenderWindow& window) override;

	void add(Figure* a) override {}

	void remove(Figure* a) override {}

	void move(float deltatime, int x, int y, sf::RenderWindow& window) override;
	
	sf::FloatRect getbounds() override;
	
	bool intersect(sf::FloatRect rect) override; 

	void setColor(sf::Color color) override;

	Circle* clone() override;

};