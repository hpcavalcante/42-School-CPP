#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap const &scav);
		ScavTrap &operator=(ScavTrap const &scav);

		void attack(const std::string &target);
		void guardGate(void);
};

#endif