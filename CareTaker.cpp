#include "CareTaker.h"
#include "Controller.h"
#include <fstream>

void CareTaker::save_state(const Controller& cont)
{
	cont.set_memento(memento);

    std::ofstream outFile("memento.txt", std::ios::binary | std::ios::trunc);
    if (!outFile) {
        std::cout << "Failed to open file: " << "memento.txt" << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(this), sizeof(Memento));
    outFile.close();

}

void CareTaker::load_state(Controller& cont)
{   
    std::ifstream inFile("memento.txt", std::ios::binary);
    if (!inFile) {
        std::cout << "Failed to open file: " << "memento.txt" << std::endl;
        return;
    }

    inFile.read(reinterpret_cast<char*>(&memento), sizeof(Memento));
    inFile.close();

	cont.get_memento(memento);
}
