#pragma once
#include "Interface.h"
#include "Prototype.h"

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
	Prototype protopype;
	CareTaker careTaker;

public:

	Controller(sf::RenderWindow& window, sf::Font* font);

	~Controller();

	void HandleInput();

	void Upadate(float deltatime);

	void Draw();

	void set_memento(Memento& memento) const;

	void get_memento(Memento& memento);
};