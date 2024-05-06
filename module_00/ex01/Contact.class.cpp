/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:44 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/06 20:01:31 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void){
	std::cout << "Constructor called" << std::endl;
	return ;
};

Contact::~Contact(void){
	std::cout << "Destructor called" << std::endl;
	return ;
};

int Contact::getIndex(void) const{
	return (this->_index);
}

void Contact::setIndex(int i){
	this->_index = i;
}

std::string Contact::getFirstName(void) const{
	return (this->_firstName);
}

void Contact::setFirstName(std::string str){
	this->_firstName = str;
}

std::string Contact::getLastName(void) const{
	return (this->_lastName);
}

void Contact::setLastName(std::string str){
	this->_lastName = str;
}

std::string Contact::getPhoneNumber(void) const{
	return (this->_phoneNumber);
}

void Contact::setPhoneNumber(std::string str){
	this->_phoneNumber = str;
}

std::string Contact::getNickName(void) const{
	return (this->_nickName);
}

void Contact::setNickName(std::string str){
	this->_nickName = str;
}

std::string Contact::getDarkestSecret(void) const{
	return (this->_darkestSecret);
}

void Contact::setDarkestSecret(std::string str){
	this->_darkestSecret = str;
}
