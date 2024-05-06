/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:51:40 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/06 19:55:44 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	this->i = 0;
	for (size_t j = 0; j < NBR; j++)
		this->contact[j].setIndex(-1);
	return ;
};

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
};

std::string	PhoneBook::getFieldInput(std::string field, const std::string promptMsg)
{
	std::string temp;

	std::cout << promptMsg << std::endl;
	if (!field.empty())
		field.clear();
	while(temp.empty())
	{
		std::getline(std::cin, temp);
		if (temp.empty())
		{
			std::cout << promptMsg << std::endl;
			std::cout << "This field can't be empty" << std::endl;
		}
	}
	return (temp);
}

void	PhoneBook::setContact(void)
{
	std::string temp;
	
	if (this->i <= NBR - 1)
	{
		this->contact[this->i].setIndex(this->i + 1);
		this->contact[this->i].setFirstName(PhoneBook::getFieldInput(this->contact[this->i].getFirstName(),
			"Please inform the contact first name"));
		this->contact[this->i].setLastName(PhoneBook::getFieldInput(this->contact[this->i].getLastName(),
			"Please inform the contact last name"));
		this->contact[this->i].setPhoneNumber(PhoneBook::getFieldInput(this->contact[this->i].getPhoneNumber(),
			"Please inform the contact phone number"));
		this->contact[this->i].setNickName(PhoneBook::getFieldInput(this->contact[this->i].getNickName(),
			"Please inform the contact nick name"));
		this->contact[this->i].setDarkestSecret(PhoneBook::getFieldInput(this->contact[this->i].getDarkestSecret(),
			"Please inform the contact darkest secret"));
	}
	this->i++;
	if (this->i == NBR)
	{
		this->i = 0;
		std::cout << "Becarefull!!! Next add will overwrite the oldest contact!!!" << std::endl;
		return ;
	}
	std::cout << "Contact added to phonebook" << std::endl;
}

std::string	formatCol(const std::string str)
{
	std::string	result;

	result = str;
	if (result.length() > 10){
		result.resize(10);
		result[result.length() - 1] = '.';
	}
	return (result);		
}

void	PhoneBook::searchContact(void)
{
	int i = 0;
	int tempIndex = 0;
	
	if (this->contact[0].getIndex() == -1)
	{
		std::cout << "The phonebook is still empty, try to fill it with new contacts using the \"ADD\" option at the main menu" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << std::endl;
	while (i <= NBR - 1)
	{
		if (this->contact[i].getIndex() != -1)
		{
			std::cout << std::setw(10) << this->contact[i].getIndex() << "|";
			std::cout << std::setw(10) << formatCol(this->contact[i].getFirstName()) << "|";
			std::cout << std::setw(10) << formatCol(this->contact[i].getLastName()) << "|";
			std::cout << std::setw(10) << formatCol(this->contact[i].getNickName()) << std::endl;
		}
		i++;
	}
	std::cout << "Please select an entry" << std::endl;
	while (tempIndex < 1 || tempIndex > NBR)
	{
		std::cin >> tempIndex;
		std::cin.ignore();
		if ( tempIndex < 1 || tempIndex > NBR)
			std::cout << "Please choose a valid entry" << std::endl;
	}
	std::cout << this->contact[tempIndex - 1].getFirstName() << std::endl;
	std::cout << this->contact[tempIndex - 1].getLastName() << std::endl;
	std::cout << this->contact[tempIndex - 1].getPhoneNumber() << std::endl;
	std::cout << this->contact[tempIndex - 1].getNickName() << std::endl;
	std::cout << this->contact[tempIndex - 1].getDarkestSecret() << std::endl;
}
