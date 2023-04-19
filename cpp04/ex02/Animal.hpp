#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &animal);
		virtual ~Animal(void);
		Animal &operator=(Animal const &animal);
		
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
		void setType(std::string type);
};

#endif