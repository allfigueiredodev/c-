/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:01:00 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/19 22:01:02 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"
#include "Classes/BitcoinExchange/BitcoinExchange.hpp"

int main(int argc, char**argv)
{
	if (argc < 2) {
		errorln("Error: could not open file.");
		return (0);
	}
	else if (argc > 2) {
		errorln("Error: too many arguments.");
		println(CYAN << "Usage: ./btc input.txt");
	}

	BitcoinExchange	exchange;
	
	exchange.runExchange(argv[1]);
	return (0);
}