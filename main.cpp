#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Singleton.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	sf::Clock deltaTimeClock;
	sf::Time deltatime;
	float deltaTimeInSeconds;

	sf::Font font;
	if (!font.loadFromFile("H:/university/OOP/lab 4 OOP/Lab 4 OOP/Libraries/SFML-2.6.0/fonts/arialbd.ttf")) {
		std::cout << "Error loading font file!" << std::endl;
		return 0;
	}

	sf::RenderWindow* ptr = &Singleton::getInstance();
	std::cout << "First prt : " << ptr << std::endl;
	ptr = &Singleton::getInstance();
	std::cout << "Second prt : " << ptr << std::endl;


	Controller contr(Singleton::getInstance(), &font);

	while (Singleton::getInstance().isOpen())
	{
		deltatime = deltaTimeClock.restart();
		deltaTimeInSeconds = deltatime.asSeconds();

		contr.HandleInput();
		contr.Upadate(deltaTimeInSeconds);
		contr.Draw();

	}

	return 0;
}