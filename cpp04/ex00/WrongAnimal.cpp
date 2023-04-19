#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor called\n";
	*this = wrongAnimal;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal assignation operator called\n";
	this->type = wrongAnimal.type;
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal sound\n";
}