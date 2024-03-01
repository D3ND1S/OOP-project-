#include "Interface.h"

Interface::Interface(sf::Font* font)
{

	currentbutton = nullptr;
	for (int i = 0; i < 6; i++)
	{
		buttons[i] = sf::RectangleShape(sf::Vector2f(130, 65));
		buttons[i].setFillColor(sf::Color(52, 53, 65));
		buttons[i].setPosition((i + 1) * 40 + 130 * i, 25);
		buttons[i].setOutlineColor(sf::Color(107, 107, 127));
		buttons[i].setOutlineThickness(4);
	}

	buttons[6] = sf::RectangleShape(sf::Vector2f(130, 65));
	buttons[6].setFillColor(sf::Color(52, 53, 65));
	buttons[6].setPosition(550, 120);
	buttons[6].setOutlineColor(sf::Color(107, 107, 127));
	buttons[6].setOutlineThickness(4);

	buttons[7] = sf::RectangleShape(sf::Vector2f(130, 65));
	buttons[7].setFillColor(sf::Color(52, 53, 65));
	buttons[7].setPosition(380, 120);
	buttons[7].setOutlineColor(sf::Color(107, 107, 127));
	buttons[7].setOutlineThickness(4);

	buttons[8] = sf::RectangleShape(sf::Vector2f(130, 65));
	buttons[8].setFillColor(sf::Color(52, 53, 65));
	buttons[8].setPosition(720, 120);
	buttons[8].setOutlineColor(sf::Color(107, 107, 127));
	buttons[8].setOutlineThickness(4);

	buttons[9] = sf::RectangleShape(sf::Vector2f(130, 65));
	buttons[9].setFillColor(sf::Color(52, 53, 65));
	buttons[9].setPosition(40, 120);
	buttons[9].setOutlineColor(sf::Color(107, 107, 127));
	buttons[9].setOutlineThickness(4);


	buttons[10] = sf::RectangleShape(sf::Vector2f(130, 65));
	buttons[10].setFillColor(sf::Color(52, 53, 65));
	buttons[10].setPosition(210, 120);
	buttons[10].setOutlineColor(sf::Color(107, 107, 127));
	buttons[10].setOutlineThickness(4);

	text[0].setString("Circle");
	text[0].setPosition(85, 50);

	text[1].setString("Triangle");
	text[1].setPosition(250, 50);

	text[2].setString("Rectangle");
	text[2].setPosition(415, 50);

	text[3].setString("Add to composite");
	text[3].setPosition(560, 50);

	text[4].setString("Reset");
	text[4].setPosition(765, 50);

	text[5].setString("Auto Move");
	text[5].setPosition(920, 50);

	text[6].setString("Composite");
	text[6].setPosition(580, 145);

	text[7].setString("Finish composite");
	text[7].setPosition(390, 145);

	text[8].setString("Next composite");
	text[8].setPosition(735, 145);

	text[9].setString("Save to prototype");
	text[9].setPosition(45, 145);

	text[10].setString("Load prototype");
	text[10].setPosition(225, 145);

	for (int i = 0; i < 11; i++)
	{
		text[i].setFont(*font); // Встановлення шрифту для тексту
		text[i].setCharacterSize(14); // Розмір символів тексту
		text[i].setFillColor(sf::Color::White); // Колір тексту
	}
}

void Interface::Update(sf::Vector2i mouseposition, Figure*& currentFigure, Figure* list[3], float& x, float& y, Composite* composite, std::vector<Figure*>& composites, int& currentpos
	, Prototype& prot)
{
	if (buttons[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{
		if (currentbutton == nullptr)
		{
			currentbutton = &buttons[0];
			buttons[0].setFillColor(sf::Color(52, 53, 65, 200));
		}
		else
		{
			currentbutton->setFillColor(sf::Color(52, 53, 65));
			currentbutton = &buttons[0];
			buttons[0].setFillColor(sf::Color(52, 53, 65, 200));
		}

		if (currentFigure != nullptr && currentFigure == list[1])
		{
			currentFigure->setColor(sf::Color::Green);
		}
		else if (currentFigure != nullptr && currentFigure == list[2])
		{
			currentFigure->setColor(sf::Color::Yellow);
		}

		if (list[0] == nullptr)
		{
			list[0] = new Circle(50, sf::Color::Cyan);
			currentFigure = list[0];
		}

		currentFigure = list[0];

		std::cout << "Button #1" << std::endl;
	}
	if (buttons[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{
		if (currentbutton == nullptr)
		{
			currentbutton = &buttons[1];
			buttons[1].setFillColor(sf::Color(52, 53, 65, 200));
		}
		else
		{
			currentbutton->setFillColor(sf::Color(52, 53, 65));
			currentbutton = &buttons[1];
			buttons[1].setFillColor(sf::Color(52, 53, 65, 200));
		}

		if (currentFigure != nullptr && currentFigure == list[0])
		{
			currentFigure->setColor(sf::Color::Cyan);
		}
		else if (currentFigure != nullptr && currentFigure == list[2])
		{
			currentFigure->setColor(sf::Color::Yellow);
		}

		if (list[1] == nullptr)
		{
			list[1] = new triang(sf::Color::Green);
			currentFigure = list[1];
		}

		currentFigure = list[1];

		std::cout << "Button #2" << std::endl;
	}
	if (buttons[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{
		if (currentbutton == nullptr)
		{
			currentbutton = &buttons[2];
			buttons[2].setFillColor(sf::Color(52, 53, 65, 200));
		}
		else
		{
			currentbutton->setFillColor(sf::Color(52, 53, 65));
			currentbutton = &buttons[2];
			buttons[2].setFillColor(sf::Color(52, 53, 65, 200));
		}

		if (currentFigure != nullptr && list[0] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Cyan);
		}
		else if (currentFigure != nullptr && list[1] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Green);
		}

		if (list[2] == nullptr)
		{
			list[2] = new rectang(150, 60, sf::Color::Yellow);
			currentFigure = list[2];
		}

		currentFigure = list[2];

		std::cout << "Button #3" << std::endl;
	}
	if (buttons[3].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{

		if (currentFigure != nullptr)
			composite->add(currentFigure->clone());

		std::cout << "Button #4" << std::endl;
	}
	if (buttons[4].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{
		if (currentbutton == nullptr)
		{
			currentbutton = &buttons[4];
			buttons[4].setFillColor(sf::Color(52, 53, 65, 200));
		}
		else
		{
			currentbutton->setFillColor(sf::Color(52, 53, 65));
			currentbutton = &buttons[4];
			buttons[4].setFillColor(sf::Color(52, 53, 65, 200));
		}

		list[0] = nullptr;
		list[1] = nullptr;
		list[2] = nullptr;

		composite->remove(nullptr);

		composites.clear();

		prot.erase("all");

		std::cout << "Button #5" << std::endl;
	}
	if (buttons[5].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{
		if (buttons[5].getFillColor() == sf::Color(52, 53, 65, 200))
		{
			buttons[5].setFillColor(sf::Color(52, 53, 65));
			x = 0; y = 0;
		}
		else
		{
			buttons[5].setFillColor(sf::Color(52, 53, 65, 200));
			x = 1; y = 1;
		}

		std::cout << "Button #6" << std::endl;
	}
	if (buttons[6].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{
		if (currentbutton == nullptr)
		{
			currentbutton = &buttons[6];
			buttons[6].setFillColor(sf::Color(52, 53, 65, 200));
		}
		else
		{
			currentbutton->setFillColor(sf::Color(52, 53, 65));
			currentbutton = &buttons[6];
			buttons[6].setFillColor(sf::Color(52, 53, 65, 200));
		}

		if (currentFigure != nullptr && list[0] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Cyan);
		}
		else if (currentFigure != nullptr && list[1] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Green);
		}
		else if (currentFigure != nullptr && currentFigure == list[2])
		{
			currentFigure->setColor(sf::Color::Yellow);
		}

		currentFigure = composite;

		std::cout << "Button #7" << std::endl;
	}


	if (buttons[7].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{

		if (currentFigure != nullptr && list[0] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Cyan);
		}
		else if (currentFigure != nullptr && list[1] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Green);
		}

		else if (currentFigure != nullptr && currentFigure == list[2])
		{
			currentFigure->setColor(sf::Color::Yellow);
		}

		composites.push_back(composite->clone());
		composite->remove(nullptr);
		composite = new Composite();

		std::cout << "Button #8" << std::endl;
	}

	if (buttons[8].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{
		if (currentbutton == nullptr)
		{
			currentbutton = &buttons[8];
			buttons[8].setFillColor(sf::Color(52, 53, 65, 200));
		}
		else
		{
			currentbutton->setFillColor(sf::Color(52, 53, 65));
			currentbutton = &buttons[8];
			buttons[8].setFillColor(sf::Color(52, 53, 65, 200));
		}

		if (currentFigure != nullptr && list[0] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Cyan);
		}
		else if (currentFigure != nullptr && list[1] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Green);
		}
		else if (currentFigure != nullptr && currentFigure == list[2])
		{
			currentFigure->setColor(sf::Color::Yellow);
		}

		if (currentpos < composites.size())
		{
			std::cout << currentpos << std::endl;
			currentFigure = composites[currentpos];
			currentpos++;
		}
		else
		{
			currentpos = 0;
			std::cout << currentpos << std::endl;
			currentFigure = composites[currentpos];
		}

		std::cout << "Button #9" << std::endl;
	}

	if (buttons[9].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{

		if (currentFigure != nullptr && list[0] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Cyan);
		}
		else if (currentFigure != nullptr && list[1] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Green);
		}
		else if (currentFigure != nullptr && currentFigure == list[2])
		{
			currentFigure->setColor(sf::Color::Yellow);
		}
		std::string name;
		std::cout << "Input name for prototype" << std::endl;
		std::cin >> name;
		if (currentFigure != nullptr)
			prot.add(name, currentFigure);

		std::cout << "Button #10" << std::endl;
	}


	if (buttons[10].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseposition)))
	{

		if (currentFigure != nullptr && list[0] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Cyan);
		}
		else if (currentFigure != nullptr && list[1] == currentFigure)
		{
			currentFigure->setColor(sf::Color::Green);
		}
		else if (currentFigure != nullptr && currentFigure == list[2])
		{
			currentFigure->setColor(sf::Color::Yellow);
		}
		
		std::string key;
		prot.print();
		std::cout << "Input key" << std::endl;
		std::cin >> key;
		composites.push_back(prot.load(key)->clone());

		std::cout << "Button #11" << std::endl;
	}
}

void Interface::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 11; i++)
	{
		window.draw(buttons[i]);
		window.draw(text[i]);
	}
}
