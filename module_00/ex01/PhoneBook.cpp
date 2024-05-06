/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:50:20 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/06 19:49:40 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	ft_parseup(const std::string str1, const std::string str2)
{
	if (str1.length() != str2.length())
		return (false);
	else
	{
		for (size_t i = 0; i < str1.length(); i++)
		{
			if (std::toupper(str1[i]) != std::toupper(str2[i]))
				return (false);
		}
	}
	return (true);
}

int main (void)
{
	PhoneBook 	phoneBook;
	std::string command;
	
	while (!ft_parseup(command, "EXIT"))
	{
		std::cout << "Please type one of the following commands:" << std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, command);
		if (ft_parseup(command, "ADD"))
		{
			phoneBook.setContact();
			command.clear();
		}
		else if (ft_parseup(command, "SEARCH"))
		{
			phoneBook.searchContact();
			command.clear();
		}
	}
	std::cout << "EXIT" << std::endl;
}
	