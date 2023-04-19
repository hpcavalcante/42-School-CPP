#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(WrongCat const &wrongCat) : WrongAnimal(wrongCat) {
	std::cout << "WrongCat copy constructor called\n";
	*this = wrongCat;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called\n";
}

WrongCat &WrongCat::operator=(WrongCat const &wrongCat) {
	std::cout << "WrongCat assignation operator called\n";
	this->type = wrongCat.type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Miau! Miau!\n";
}