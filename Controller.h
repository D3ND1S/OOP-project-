#pragma once
#include "Interface.h"

class Controller
{
private:
	Figure* list[3]{};
	Figure* currentFigure;
	sf::RenderWindow* window;
	sf::Vector2i mousePosition;
	sf::Font* font;
	std::vector<Figure*> composites;
	Interface* inter;
	float autox, autoy;
	int currentpos;
	Composite* composite;

public:

	Controller(sf::RenderWindow& window, sf::Font* font);

	~Controller();

	void HandleInput();

	void Upadate(float deltatime);

	void Draw();
};