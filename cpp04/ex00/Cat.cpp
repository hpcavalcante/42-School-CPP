#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat constructor called\n";
}

Cat::Cat(Cat const &cat) : Animal(cat) {
	std::cout << "Cat copy constructor called\n";
	*this = cat;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called\n";
}

Cat &Cat::operator=(Cat const &cat) {
	std::cout << "Cat assignation operator called\n";
	this->type = cat.type;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Miau! Miau!\n";
}