#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog(void);
		Dog(std::string type);
		Dog(Dog const &dog);
		~Dog(void);
		Dog &operator=(Dog const &dog);
		
		void makeSound(void) const;
		Brain *getBrain(void) const;
};

#endif