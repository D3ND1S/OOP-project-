#pragma once
#include "rectang.h"
#include "triang.h"
#include "Circle.h"
#include "Composite.h"
#include "Prototype.h"
#include "CareTaker.h"


class Interface
{
private:

	sf::RectangleShape buttons[12];
	sf::Text text[12];
	sf::Text temp;
	sf::RectangleShape* currentbutton;

public:

	Interface(sf::Font* font);

	void Update(sf::Vector2i mouseposition, Figure*& currentFigure, Figure* list[3], float& x, float& y, Composite* composite, std::vector<Figure*>& composites,int& currentpos
		, Prototype& prot, CareTaker& careTaker,Controller& controller);

	void draw(sf::RenderWindow& window);
	
};

