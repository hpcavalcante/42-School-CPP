#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(WrongCat const &wrongCat);
		~WrongCat(void);
		WrongCat &operator=(WrongCat const &wrongCat);
		
		void makeSound(void) const;
};

#endif