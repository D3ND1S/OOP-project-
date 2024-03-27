#pragma once
#include "Memento.h"

class Controller; 

class CareTaker
{
private:
	Memento memento;
public:

	CareTaker() = default;

	void save_state(const Controller& cont);

	void load_state(Controller& cont);
};

