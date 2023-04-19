#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constructor called\n";
	this->setName("ScavTrap");
	this->setHP(100);
	this->setEP(50);
	this->setAD(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor called\n";
	this->setName(name);
	this->setHP(100);
	this->setEP(50);
	this->setAD(20);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const &scav) : ClapTrap() {
	std::cout << "ScavTrap copy constructor called\n";
	*this = scav;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scav) {
	std::cout << "ScavTrap copy assignment operator called\n";
	this->setName(scav.getName());
	this->setHP(scav.getHP());
	this->setEP(scav.getEP());
	this->setAD(scav.getAD());
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->getHP() == 0) {
		std::cout << "ScavTrap " << this->getName() << " cannot attack because he is dead\n";
	}
	else if (this->getEP() == 0) {
		std::cout << "ScavTrap " << this->getName() << " cannot attack because he is out of energy\n";
	}
	else {
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAD() << " points of damage!\n";
		this->setEP(this->getEP() - 1);
	}
}

void ScavTrap::guardGate(void) {
	if (this->getHP() == 0) {
		std::cout << "ScavTrap " << this->getName() << " cannot enter in Gate keeper mode because he is dead\n";
	}
	else {
		std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode\n";
	}
}