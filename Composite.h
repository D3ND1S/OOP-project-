#pragma once
#include "Figure.h"

class Composite : public Figure
{
private:
	std::vector<Figure*> arr;
public:
	Composite* clone() override;

	void add(Figure* a) override;
	
	void remove(Figure* a) override;

	void Update(float deltatime, sf::RenderWindow& window) override;
	
	void draw(sf::RenderWindow& window) override;

	void move(float deltatime, int x, int y, sf::RenderWindow& window);

	~Composite();

	bool check(float x, float y, sf::RenderWindow& window) override;
};