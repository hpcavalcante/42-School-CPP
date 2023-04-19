#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap const &frag);
		FragTrap &operator=(FragTrap const &frag);

		void highFivesGuys(void);
};

#endif