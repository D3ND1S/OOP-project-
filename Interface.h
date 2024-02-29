#pragma once
#include "rectang.h"
#include "triang.h"
#include "Circle.h"
#include "Composite.h"

class Interface
{
private:

	sf::RectangleShape buttons[9];
	sf::Text text[9];
	sf::Text temp;
	sf::RectangleShape* currentbutton;

public:

	Interface(sf::Font* font);

	void Update(sf::Vector2i mouseposition, Figure*& currentFigure, Figure* list[3], float& x, float& y, Composite* composite, std::vector<Figure*>& composites,int& currentpos);

	void draw(sf::RenderWindow& window);
	
};

