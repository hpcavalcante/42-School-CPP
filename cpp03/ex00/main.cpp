#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap;
	ClapTrap clapclone(clap);
	ClapTrap clap2("Clap2");
	
	std::cout << "\n";
	clap.setAD(2);
	clap2.setAD(1);
	clap2.setEP(20);

	clapclone.setName("Clone");
	clapclone.attack(clap.getName());
	clap.takeDamage(clapclone.getAD());
	clap.attack(clap2.getName());
	clap2.takeDamage(clap.getAD());

	std::cout << "\n";
	for (int i = 0; i < 4; i++) {
		clap2.attack(clapclone.getName());
		if (clap2.getEP() > 0)
			clapclone.takeDamage(clap2.getAD());
	}
	
	std::cout << "\n";
	clapclone = clap2;
	clapclone.setName("Clone");
	clapclone.setAD(2);

	std::cout << "\n";
	for (int i = 0; i < 6; i++) {
		clapclone.beRepaired(1);
	}

	std::cout << "\n";
	clapclone.attack(clap.getName());
	clap.takeDamage(clapclone.getAD());

	std::cout << "\n";
	clap2.beRepaired(2);
	clap2.attack(clap.getName());
	clap.takeDamage(clap2.getAD());

	std::cout << "\n";
	for (int i = 0; i < 5; i++){
		clap.attack(clap2.getName());
		if (clap.getEP() > 0)
			clap2.takeDamage(clap.getAD());
		clap2.beRepaired(1);
	}

	std::cout << "\n";
	for (int i = 0; i < 5; i++) {
		clapclone.attack(clap2.getName());
		if (clapclone.getEP() > 0)
			clap2.takeDamage(clapclone.getAD());
		clap2.beRepaired(1);
	}
	return (0);
}