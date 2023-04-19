#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called\n";
	this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog constructor called\n";
}

Dog::Dog(Dog const &dog) : Animal(dog) {
	std::cout << "Dog copy constructor called\n";
	this->brain = new Brain(*dog.getBrain());
	*this = dog;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called\n";
	delete this->brain;
}

Dog &Dog::operator=(Dog const &dog) {
	std::cout << "Dog assignation operator called\n";
	this->type = dog.getType();
	*this->brain = *dog.getBrain();
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Bark! Bark!\n";
}

Brain *Dog::getBrain(void) const {
	return this->brain;
}
