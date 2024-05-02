/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:51:40 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/02 20:52:57 by aperis-p         ###   ########.fr       */
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
	return ;
};

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
};

void	PhoneBook::setContact(void)
{
	std::string temp;
	
	if (this->i <= NBR - 1)
	{
		this->contact[this->i].index = this->i + 1;
		std::cout << "Please inform the contact first name" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while(this->contact[this->i].firstName.empty())
		{
			std::getline(std::cin, temp);
			if (temp.empty())
				std::cout << "This field can't be empty" << std::endl;
			else
				this->contact[this->i].firstName = temp;
		}
		std::cout << "Please inform the contact last name" << std::endl;
		while(this->contact[this->i].lastName.empty())
		{
			std::getline(std::cin, temp);
			if (temp.empty())
				std::cout << "This field can't be empty" << std::endl;
			else
				this->contact[this->i].lastName = temp;
		}
		std::cout << "Please inform the contact phone number" << std::endl;
		while(this->contact[this->i].phoneNumber.empty())
		{
			std::getline(std::cin, temp);
			if (temp.empty())
				std::cout << "This field can't be empty" << std::endl;
			else
				this->contact[this->i].phoneNumber = temp;
		}
		std::cout << "Please inform the contact nick name" << std::endl;
		while(this->contact[this->i].nickName.empty())
		{
			std::getline(std::cin, temp);
			if (temp.empty())
				std::cout << "This field can't be empty" << std::endl;
			else
				this->contact[this->i].nickName = temp;
		}
		std::cout << "Please inform the contact darkest secret" << std::endl;
		while(this->contact[this->i].darkestSecret.empty())
		{
			std::getline(std::cin, temp);
			if (temp.empty())
				std::cout << "This field can't be empty" << std::endl;
			else
				this->contact[this->i].darkestSecret = temp;			
		}
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
	
	std::cout << "     index|first name| last name|  nick name" << std::endl;
	while (i <= NBR - 1)
	{
		std::cout << "         " << this->contact[i].index << "| ";
		std::cout << this->contact[i].firstName << "| ";
		std::cout << this->contact[i].lastName << "| ";
		std::cout << this->contact[i].nickName << std::endl;
		i++;
	}
	std::cout << "Please select an entry" << std::endl;
	while (tempIndex < 1 || tempIndex > NBR)
	{
		std::cin >> tempIndex;
		if (tempIndex < 1 || tempIndex > NBR)
			std::cout << "Please choose a valid entry" << std::endl;
	}
	std::cout << this->contact[tempIndex - 1].firstName << std::endl;
	std::cout << this->contact[tempIndex - 1].lastName << std::endl;
	std::cout << this->contact[tempIndex - 1].phoneNumber << std::endl;
	std::cout << this->contact[tempIndex - 1].nickName << std::endl;
	std::cout << this->contact[tempIndex - 1].darkestSecret << std::endl;
}
