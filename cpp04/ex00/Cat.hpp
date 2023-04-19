#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(std::string type);
		Cat(Cat const &cat);
		~Cat(void);
		Cat &operator=(Cat const &cat);
		
		void makeSound(void) const;
};

#endif