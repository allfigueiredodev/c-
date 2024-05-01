/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:50:20 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/30 18:55:28 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main (void)
{
	PhoneBook 	phoneBook;
	std::string command;
	int	i = 0;
	
	std::cout << "Please type one of the following commands:" << std::endl;
	std::cout << "ADD | SEARCH | EXIT" << std::endl;
	std::cin >> command;
	
	if (command == "ADD")
	{
		
	}
	else if (command == "SEARCH")
	{
		
	}
	else if (command == "EXIT")
	{
		
	}
	std::cout << command << std::endl;
}