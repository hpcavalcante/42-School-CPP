#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &wrongAnimal);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(WrongAnimal const &wrongAnimal);
		
		void makeSound(void) const;
		std::string getType(void) const;
		void setType(std::string type);
};

#endif