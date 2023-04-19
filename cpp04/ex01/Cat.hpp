#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat(void);
		Cat(std::string type);
		Cat(Cat const &cat);
		~Cat(void);
		Cat &operator=(Cat const &cat);
		
		void makeSound(void) const;
		Brain *getBrain(void) const;
};

#endif