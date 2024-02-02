#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <iostream>
#include <windows.h>

class Figure
{
public:

	Figure() = default;

	virtual Figure* clone() = 0;
	virtual bool check(float x, float y,sf::RenderWindow& window) { return false; } // повина бути абстрактою
	virtual void move(float deltatime, int x, int y, sf::RenderWindow& window) = 0;
	virtual sf::Vector2f getPosition() { return { 0,0 }; } // повина бути абстрактою
	virtual sf::FloatRect getbounds() { return sf::FloatRect(); }
	virtual bool intersect(sf::FloatRect rect) { return false; };
	virtual void setColor(sf::Color) { }
	virtual void add(Figure* a) = 0;
	virtual void remove(Figure* a) = 0;
	virtual void Update(float deltatime, sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};