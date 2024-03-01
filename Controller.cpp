#include "Controller.h"

Controller::Controller(sf::RenderWindow& window, sf::Font* font) : window(&window), font(font), autox(0), autoy(0), currentpos(0)
{
	composite = new Composite();
	inter = new Interface(font);
	currentFigure = nullptr;
}

Controller::~Controller()
{
	for (int i = 0; i < 3; i++)
	{
		if (list[i] != nullptr)
			delete list[i];
		list[i] = nullptr;
	}
	composites.clear();
	delete inter;
}

void Controller::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::MouseMoved)
		{
			mousePosition.x = event.mouseMove.x;
			mousePosition.y = event.mouseMove.y;
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			inter->Update(mousePosition, currentFigure, list, autox, autoy, composite, composites, currentpos, protopype);
		}
	}

}
void Controller::Upadate(float deltatime)
{

	if (currentFigure != nullptr)
	{
		currentFigure->Update(deltatime, *window);

		if (currentFigure->check(autox, 0, *window))
		{
			currentFigure->move(deltatime, autox, 0, *window);
		}

		if (currentFigure->check(0, autoy, *window))
		{
			currentFigure->move(deltatime, 0, autoy, *window);
		}

		for (int i = 0; i < 3; i++)
		{
			if (currentFigure != list[i] && list[i] != nullptr)
			{

				if (currentFigure->intersect(list[i]->getbounds()))
				{
					currentFigure->setColor(sf::Color(255, 16, 83));
				}
			}
		}

	}

}

void Controller::Draw()
{
	window->clear();

	inter->draw(*window);

	for (auto ptr : list)
	{
		if (ptr != nullptr)
			ptr->draw(*window);
	}

	for (auto elem : composites)
	{
		elem->draw(*window);
	}

	composite->draw(*window);

	window->display();
}