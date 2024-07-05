/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:42:12 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 13:42:15 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.h"
#include "Classes/ScalarConverter/ScalarConverter.hpp"

int main (int argc, char **argv){
	if (argc != 2) {
		errorln("Bad arguments");
		println(CYAN << "Try this way: ./convert <data to be converted>");
		return (1);
	}
	ScalarConverter::convert(argv[1]);
};