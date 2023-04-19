#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called\n";
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat constructor called\n";
}

Cat::Cat(Cat const &cat) : Animal(cat) {
	std::cout << "Cat copy constructor called\n";
	this->brain = new Brain(*cat.getBrain());
	*this = cat;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called\n";
	delete this->brain;
}

Cat &Cat::operator=(Cat const &cat) {
	std::cout << "Cat assignation operator called\n";
	this->type = cat.getType();
	*this->brain = *cat.getBrain();
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Miau! Miau!\n";
}

Brain *Cat::getBrain(void) const {
	return this->brain;
}