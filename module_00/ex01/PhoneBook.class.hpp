#ifndef PHONEBOOK_H
#define	PHONEBOOK_H

#include <string>
#include <iostream>
#include "Contact.class.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

private:

	static Contact contact[8];
};

#endif