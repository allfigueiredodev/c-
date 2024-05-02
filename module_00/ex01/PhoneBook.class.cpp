/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:51:40 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/02 14:05:33 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.class.hpp"

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
	if (this->i <= 7)
	{
		this->contact[this->i].index = this->i + 1;
		std::cout << "Please inform the contact first name" << std::endl;
		while(this->contact[this->i].firstName.empty())
		{
			std::getline(std::cin, this->contact[this->i].firstName);
			if (this->contact[this->i].firstName.empty())
				std::cout << "This field can't be empty" << std::endl;
		}
		std::cout << "Please inform the contact phone number" << std::endl;
		while(!this->contact[this->i].phoneNumber)
			std::cin >> this->contact[this->i].phoneNumber;
		std::cout << "Please inform the contact nick name" << std::endl;
		while(this->contact[this->i].nickName.empty())
		{
			std::getline(std::cin, this->contact[this->i].nickName);
			if (this->contact[this->i].nickName.empty())
				std::cout << "This field can't be empty" << std::endl;
		}
		std::cout << "Please inform the contact darkest secret" << std::endl;
		while(this->contact[this->i].darkestSecret.empty())
		{
			std::getline(std::cin, this->contact[this->i].darkestSecret);		 
			if (this->contact[this->i].darkestSecret.empty())
				std::cout << "This field can't be empty" << std::endl;
		}
	}
	this->i++;
	if (this->i == 8)
		this->i = 0;
	std::cout << "Contact added to phonebook" << std::endl;
}

void	PhoneBook::searchContact(void)
{
	int i = 0;
	
	std::cout << "     index|first name| last name|  nick name" << std::endl;
	while (i < this->i)
	{
		std::cout << this->contact[this->i].index << std::endl;
		std::cout << this->contact[this->i].firstName << std::endl;
		std::cout << this->contact[this->i].lastName << std::endl;
		std::cout << this->contact[this->i].nickName << std::endl;
		i++;
	}
}
