#ifndef PHONEBOOK_CLASS_H
#define	PHONEBOOK_CLASS_H

#include "PhoneBook.hpp"

class PhoneBook {

public:

	int 		i;
	Contact 	contact[NBR];
	void		setContact(void);
	void		searchContact(void);
	std::string	getFieldInput(std::string field, const std::string promptMsg);

	PhoneBook(void);
	~PhoneBook(void);
	
};

#endif