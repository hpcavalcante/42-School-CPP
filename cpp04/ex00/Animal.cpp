#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) {
	std::cout << "Animal constructor called" << std::endl;
	this->type = type;
}

Animal::Animal(Animal const &animal) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &animal) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = animal.type;
	return *this;
}

std::string Animal::getType(void) const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}

void Animal::makeSound(void) const {
	std::cout << "Animal sound" << std::endl;
}