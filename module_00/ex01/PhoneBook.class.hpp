#ifndef PHONEBOOK_H
#define	PHONEBOOK_H

#include <string>
#include <iostream>
#include "Contact.class.hpp"

class PhoneBook {

public:

	int 	i;
	Contact contact[NBR];
	void	setContact(void);
	void	searchContact(void);
	void	getFieldInput(std::string& field, const std::string promptMsg);

	PhoneBook(void);
	~PhoneBook(void);
	
};

#endif