#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() {
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	this->value = number << fractionalBits;
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	this->value = static_cast<int>(roundf(number * (1 << this->fractionalBits)));
}

Fixed &Fixed::operator = (Fixed const &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int raw) {
	this->value = raw;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->value) / (1 << this->fractionalBits));
}

int Fixed::toInt(void) const {
	return (this->value >> this->fractionalBits);
}

std::ostream &operator << (std::ostream &out, Fixed const &fn) {
	out << fn.toFloat();
	return (out);
}