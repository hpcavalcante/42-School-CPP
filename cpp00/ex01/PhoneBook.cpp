#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	open = 1;
	index = 0;
	size = 0;
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::setOpen(bool open) {
	this->open = open;
}

bool PhoneBook::isOpen() const {
	return open;
}

void	PhoneBook::addContact(void) {
	Contact newContact;
	if (this->index > 7)
		this->index = 0;
	while (newContact.getFirstName().empty()){
		std::cout << "First Name: ";
		std::string firstName;
		std::getline(std::cin, firstName);
		if (firstName.empty())
			std::cout << "\033[31mFirst name cannot be empty!\033[0m" << std::endl;
		else
			newContact.setFirstName(firstName);
	}
	while (newContact.getLastName().empty()){
		std::cout << "Last Name: ";
		std::string lastName;
		std::getline(std::cin, lastName);
		if (lastName.empty())
			std::cout << "\033[31mLast name cannot be empty!\033[0m" << std::endl;
		else
			newContact.setLastName(lastName);
	}
	while (newContact.getNickname().empty()){
		std::cout << "Nickname: ";
		std::string nickname;
		std::getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << "\033[31mNickname cannot be empty!\033[0m" << std::endl;
		else
			newContact.setNickname(nickname);
	}
	while (newContact.getPhoneNumber().empty()){
		std::cout << "Phone Number: ";
		std::string phoneNumber;
		std::getline(std::cin, phoneNumber);
		if (phoneNumber.empty())
			std::cout << "\033[31mPhone number cannot be empty!\033[0m" << std::endl;
		else
			newContact.setPhoneNumber(phoneNumber);
	}
	while (newContact.getSecret().empty()){
		std::cout << "Darkest Secret: ";
		std::string secret;
		std::getline(std::cin, secret);
		if (secret.empty())
			std::cout << "\033[31mDarkest secret cannot be empty!\033[0m" << std::endl;
		else
			newContact.setSecret(secret);
	}
	this->contact[this->index] = newContact;

	std::cout << "\033[33mContact added!\033[0m" << std::endl;
	this->index++;
	if (this->size < 8)
		this->size++;
}

void	PhoneBook::showInfo(int index) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "First Name: " << this->contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contact[index].getSecret() << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	PhoneBook::displayActualContacts(void) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << '|'
			<< std::right << std::setw(10) << "First Name" << '|'
			<< std::right << std::setw(10) << "Last Name" << '|'
			<< std::right << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::string firstName = this->contact[i].getFirstName().substr(0, 9);
		std::string lastName = this->contact[i].getLastName().substr(0, 9);
		std::string nickname = this->contact[i].getNickname().substr(0, 9);
		if (firstName.length() == 9) {
			firstName.replace(8, 1, ".");
		}
		if (lastName.length() == 9) {
			lastName.replace(8, 1, ".");
		}
		if (nickname.length() == 9) {
			nickname.replace(8, 1, ".");
		}
		std::cout << std::right << std::setw(10) << i << '|'
				<< std::right << std::setw(10) << firstName << '|'
				<< std::right << std::setw(10) << lastName << '|'
				<< std::right << std::setw(10) << nickname << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void	PhoneBook::showContacts(void) {
	this->displayActualContacts();
	std::string input;
	std::cout << "Enter index to see contact info" << std::endl;
	std::getline(std::cin, input);
	if (input[0] - '0' < this->size && input[0] - '0' >= 0)
		PhoneBook::showInfo(input[0] - '0');
	if (input[0] - '0' >= this->size || input[0] - '0' < 0)
		std::cout << "\033[31mWrong index! Please use only numbers and make sure they are part of the list above.\033[0m" << std::endl;
}