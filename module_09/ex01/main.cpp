/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:21:31 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/19 22:21:34 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/RPN/RPN.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		errorln("Error: Not enough arguments.");
		println(CYAN << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"");
	}
	else if (argc > 2) {
		errorln("Error: Too many arguments.");
		println(CYAN << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"");
	}
	RPN rpn;

	rpn.calc(argv[1]);

}
