#pragma once
#include <SFML/Graphics.hpp>

class Singleton
{

public:
	static sf::RenderWindow& getInstance() {
		static sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");
		return window;
	}

private:
	Singleton() {}
	~Singleton() {}
};

