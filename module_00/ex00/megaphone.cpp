/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:33:32 by aperis-p          #+#    #+#             */
/*   Updated: 2024/04/30 13:33:35 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

std::string ft_upper(const std::string str)
{
	int i = 0;
	std::string	up;

	while(str[i])
	{
		up += std::toupper(str[i]);
		i++;
	}
	return (up);
}

int main (int argc, char **argv)
{
	std::string	concatenated;
	int			i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc == 2)
	{
		concatenated += ft_upper(argv[1]);
		std::cout << concatenated << std::endl;
	}
	else
	{
		while(argc != 1)
		{
			if (argc == 2)
				concatenated += ft_upper(argv[i]);
			else
			{
				concatenated += ft_upper(argv[i]);
				concatenated += " ";
			}
			i++;
			argc--;
		}
		std::cout << concatenated << std::endl;
	}
}
