/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:51:40 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/05 17:09:52 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.class.hpp"
#include <cstdio>
#include <limits>

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	this->i = 0;
	for (size_t j = 0; j < NBR; j++)
		this->contact[j].index = -1;
	return ;
};

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
};

void	PhoneBook::getFieldInput(std::string& field, const std::string promptMsg)
{
	std::string temp;

	std::cout << promptMsg << std::endl;
	if (!field.empty())
		field.clear();
	while(field.empty())
	{
		std::getline(std::cin, temp);
		// system("clear");
		if (temp.empty())
			std::cout << "This field can't be empty" << std::endl;
		else
			field = temp;
	}
}

std::string	formatCol(const std::string str)
{
	std::string	result;

	result = str;
	if (str.length() > 10){
		result = str.substr(0, 10);
		result[9] = '.';
	}
	else if (str.length() < 10 && str.length() > 0){
	result.clear();
		for (size_t i = 0; i < 10 - str.length(); i++)
			result += ' ';
		result.append(str);	
	}
	return (result);		
}

void	PhoneBook::setContact(void)
{
	std::string temp;
	
	if (this->i <= NBR - 1)
	{
		this->contact[this->i].index = this->i + 1;
		PhoneBook::getFieldInput(this->contact[this->i].firstName, "Please inform the contact first name");
		PhoneBook::getFieldInput(this->contact[this->i].lastName, "Please inform the contact last name");
		PhoneBook::getFieldInput(this->contact[this->i].phoneNumber, "Please inform the contact phone number");
		PhoneBook::getFieldInput(this->contact[this->i].nickName, "Please inform the contact nick name");
		PhoneBook::getFieldInput(this->contact[this->i].darkestSecret, "Please inform the contact darkest secret");
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

void	PhoneBook::searchContact(void)
{
	int i = 0;
	int tempIndex = 0;
	
	if (this->contact[0].index == -1)
	{
		std::cout << "The phonebook is still empty, try to fill it with new contacts using the \"ADD\" option at the main menu" << std::endl;
		return ;
	}
	std::cout << "     Index|First Name| Last Name| Nick Name" << std::endl;
	while (i <= NBR - 1)
	{
		if (this->contact[i].index != -1)
		{
			std::cout << "         " << this->contact[i].index << "|";
			std::cout << formatCol(this->contact[i].firstName) << "|";
			std::cout << formatCol(this->contact[i].lastName) << "|";
			std::cout << formatCol(this->contact[i].nickName) << std::endl;
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
	std::cout << this->contact[tempIndex - 1].firstName << std::endl;
	std::cout << this->contact[tempIndex - 1].lastName << std::endl;
	std::cout << this->contact[tempIndex - 1].phoneNumber << std::endl;
	std::cout << this->contact[tempIndex - 1].nickName << std::endl;
	std::cout << this->contact[tempIndex - 1].darkestSecret << std::endl;
}
