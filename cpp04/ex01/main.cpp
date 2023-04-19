#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void){
	Animal *animals[10];
	
	std::cout << "Default tests:\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	std::cout << "\n";
	std::cout << "More tests:";
	for (int i = 0; i < 10; i++) {
		if (i < 5) {
			std::cout << "\n";
			std::cout << "* Dog constructors *\n";
			animals[i] = new Dog();
		}
		else {
			std::cout << "\n";
			std::cout << "* Cat constructors *\n";
			animals[i] = new Cat();
		}
	}

	std::cout << "\n";
	for (int i = 0; i < 10; i++) {
		if (i < 5) {
			Dog* dog = dynamic_cast<Dog*>(animals[i]);
			if (dog) {
				Brain* brain = dog->getBrain();
				brain->setIdea(i, "Dog Idea");
			}
		}
		else {
			Cat* cat = dynamic_cast<Cat*>(animals[i]);
			if (cat) {
				Brain* brain = cat->getBrain();
				brain->setIdea(i, "Cat Idea");
			}
		}
	}

	std::cout << "\n";
	std::cout << "Dog ideas:\n";
	for (int i = 0; i < 5; i++) {
		Dog* dog = dynamic_cast<Dog*>(animals[i]);
		if (dog) {
			Brain* brain = dog->getBrain();
			std::cout << brain->getIdea(i) << "\n";
		}
	}
	std::cout << "\n";
	std::cout << "Cat ideas:\n";
	for (int i = 5; i < 10; i++) {
		Cat* cat = dynamic_cast<Cat*>(animals[i]);
		if (cat) {
			Brain* brain = cat->getBrain();
			std::cout << brain->getIdea(i) << "\n";
		}
	}

	for (int i = 0; i < 10; i++) {
		std::cout << "\n";
		delete animals[i];
	}

	return (0);
}