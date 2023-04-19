#include "PhoneBook.hpp"
void	parse_input(std::string input, PhoneBook *phonebook) {
	if (input == "ADD" || input == "add")
		phonebook->addContact();
	if (input == "SEARCH" || input == "search")
		phonebook->showContacts();
	if (input == "EXIT" || input == "exit") {
		std::cout << "Bye!" << std::endl;
		phonebook->setOpen(false);
	}
}

int main(void) {
	PhoneBook	phonebook;
	std::string input;
	
	while (phonebook.isOpen()) {
		std::cout << "------------------------------------" << std::endl;
		std::cout << "| Use \033[1mADD\033[0m to create a new contact  |" << std::endl;
		std::cout << "| Use \033[1mSEARCH\033[0m to see contacts       |" << std::endl;
		std::cout << "| Use \033[1mEXIT\033[0m to close PhoneBook      |" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::getline(std::cin, input);
		parse_input(input, &phonebook);
	}
}
