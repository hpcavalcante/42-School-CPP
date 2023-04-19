#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contact[8];
	int		index;
	int		size;
	bool	open;
public:
	PhoneBook();
	~PhoneBook();
	
	void	addContact();
	void	showContacts();
	void	showInfo(int index);
	void	displayActualContacts();
	void	setOpen(bool open);
	bool	isOpen() const;
};

#endif
