#include "CareTaker.h"
#include "Controller.h"

void CareTaker::save_state(const Controller& cont)
{
	cont.set_memento(memento);
}

void CareTaker::load_state(Controller& cont)
{
	cont.get_memento(memento);
}
