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
			inter->Update(mousePosition, currentFigure, list, autox, autoy, composite, composites, currentpos, protopype, careTaker,*this);
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

void Controller::set_memento(Memento& memento) const
{
	if (list[0] != nullptr)
		memento.list[0] = list[0]->clone();

	if (list[1] != nullptr)
		memento.list[1] = list[1]->clone();

	if (list[2] != nullptr)
		memento.list[2] = list[2]->clone();

	for (auto& elem : composites)
	{
		memento.composites.push_back(elem->clone());
	}
	// Присвоювання до мементо 

}

void Controller::get_memento(Memento& memento)
{
	if (memento.list[0] != nullptr)
		list[0] = memento.list[0]->clone();

	if (memento.list[1] != nullptr)
		list[1] = memento.list[1]->clone();

	if (memento.list[2] != nullptr)
		list[2] = memento.list[2]->clone();

	composites.clear();
	for (auto& elem : memento.composites)
	{
		composites.push_back(elem->clone());
	}
	// Присвоювання з мементо 
}
