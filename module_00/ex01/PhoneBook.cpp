/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:50:20 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/02 13:40:59 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main (void)
{
	PhoneBook 	phoneBook;
	std::string command;
	
	while (command != "EXIT")
	{
		std::cout << "Please type one of the following commands:" << std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			phoneBook.setContact();
			command.clear();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
			command.clear();
		}
	}
	std::cout << "EXIT" << std::endl;
}
	