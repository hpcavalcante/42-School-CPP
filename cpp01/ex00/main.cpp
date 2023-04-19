#include "Zombie.hpp"

int main() {
	Zombie *zombie = newZombie("Asmodeus");
	zombie->announce();
	delete zombie;
	randomChump("Akeldama");
	return (0);
}