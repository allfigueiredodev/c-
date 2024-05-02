#ifndef PHONEBOOK_H
#define	PHONEBOOK_H

#include <string>
#include <iostream>
#include "Contact.class.hpp"

class PhoneBook {

public:

	int 	i;
	Contact contact[8];
	void	setContact(void);
	void	searchContact(void);

	PhoneBook(void);
	~PhoneBook(void);
	
};

#endif