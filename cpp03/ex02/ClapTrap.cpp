#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap parameter constructor called\n";
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &clap) {
	std::cout << "ClapTrap copy constructor called\n";
	*this = clap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clap) {
	std::cout << "ClapTrap copy assignment operator called\n";
	this->setName(clap.getName());
	this->setHP(clap.getHP());
	this->setEP(clap.getEP());
	this->setAD(clap.getAD());
	return (*this);
}

std::string ClapTrap::getName(void) const {
	return (this->name);
}

int	ClapTrap::getHP(void) const {
	return (this->hitPoints);
}

int	ClapTrap::getEP(void) const {
	return (this->energyPoints);
}

int	ClapTrap::getAD(void) const {
	return (this->attackDamage);
}

void ClapTrap::setName(std::string name) {
	this->name = name;
}

void ClapTrap::setHP(int hp) {
	this->hitPoints = hp;
}

void ClapTrap::setEP(int ep) {
	this->energyPoints = ep;
}

void ClapTrap::setAD(int ad) {
	this->attackDamage = ad;
}

void ClapTrap::attack(const std::string &target) {
	if (this->getHP() == 0) {
		std::cout << this->getName() << " cannot attack because " << target << " has already dead\n";
	}
	else if (this->getEP() == 0) {
		std::cout << this->getName() << " cannot attack because has no energy points left\n";
	}
	else {
		std::cout << "ClapTrap "<< this->getName() << " attacks " << target << ", causing " << this->getAD() << " points of damage!\n";
		this->setEP(this->getEP() - 1);
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHP() == 0) {
		std::cout << this->getName() << " is already dead, no damage taken\n";
	}
	else {
		std::cout << this->getName() << " takes " << amount << " of damage!\n";
		this->setHP(this->getHP() - amount);
		if (this->getHP() <= 0) {
			this->setHP(0);
			std::cout << this->getName() << " died...\n";
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHP() == 0) {
		std::cout << this->getName() << " can't be repaired because he is dead\n";
	}
	else if (this->getEP() == 0) {
		std::cout << this->getName() << " has no energy points left to be repaired\n";
	}
	else {
		std::cout << this->getName() << " repairs himself, recovering " << amount << " HP\n";
		this->setHP(this->getHP() + amount);
		this->setEP(this->getEP() - 1);
	}
}