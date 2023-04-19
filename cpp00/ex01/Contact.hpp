#ifndef CONTACT_HPP
 #define CONTACT_HPP
#include <iostream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;
	public:
		Contact();
		~Contact();

		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setSecret(std::string secret);

		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getSecret();
};

#endif