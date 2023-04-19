#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog constructor called\n";
}

Dog::Dog(Dog const &dog) : Animal(dog) {
	std::cout << "Dog copy constructor called\n";
	*this = dog;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called\n";
}

Dog &Dog::operator=(Dog const &dog) {
	std::cout << "Dog assignation operator called\n";
	this->type = dog.type;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Bark! Bark!\n";
}

