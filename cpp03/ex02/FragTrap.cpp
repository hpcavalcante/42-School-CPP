#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor called\n";
	this->setHP(100);
	this->setEP(100);
	this->setAD(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called\n";
	this->setHP(100);
	this->setEP(100);
	this->setAD(30);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called\n";
}

FragTrap::FragTrap(FragTrap const &frag) : ClapTrap() {
	std::cout << "FragTrap copy constructor called\n";
	*this = frag;
}

FragTrap &FragTrap::operator=(FragTrap const &frag) {
	std::cout << "FragTrap copy assignment operator called\n";
	this->setName(frag.getName());
	this->setHP(frag.getHP());
	this->setEP(frag.getEP());
	this->setAD(frag.getAD());
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	if (this->getHP() == 0) {
		std::cout << "FragTrap " << this->getName() << " cannot give high five because he is dead\n";
	}
	else {
		std::cout << "FragTrap " << this->getName() << " gives high five\n";
	}
}