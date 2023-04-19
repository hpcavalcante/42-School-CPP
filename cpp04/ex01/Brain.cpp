#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "Empty idea\n";
	}
}

Brain::Brain(Brain const &brain) {
	std::cout << "Brain copy constructor called\n";
	*this = brain;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called\n";
}

Brain &Brain::operator=(Brain const &brain) {
	std::cout << "Brain assignation operator called\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.getIdea(i);
	}
	return *this;
}

std::string Brain::getIdea(int i) const {
	return this->ideas[i];
}

void Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}