#include <SFML/Graphics.hpp>
#include "Controller.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML");


	sf::Clock deltaTimeClock;
	sf::Time deltatime;
	float deltaTimeInSeconds;


	sf::Font font;
	if (!font.loadFromFile("H:/university/OOP/lab 4 OOP/Lab 4 OOP/Libraries/SFML-2.6.0/fonts/arialbd.ttf")) {
		std::cout << "Error loading font file!" << std::endl;
		return 0;
	}

	Controller contr(window, &font);

	while (window.isOpen())
	{
		deltatime = deltaTimeClock.restart();
		deltaTimeInSeconds = deltatime.asSeconds();

		contr.HandleInput();
		contr.Upadate(deltaTimeInSeconds);
		contr.Draw();

	}

	return 0;
}