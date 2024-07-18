/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:02:32 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/18 16:38:23 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes/PmergeMe/PmergeMe.hpp"

int main(int argc, char** argv) {

	if (argc == 1) {
		errorln("Not enough arguments");
		return (0);
	}
	PmergeMe fJ;
	

	fJ.FJSort(argc, argv);
	return (0);
}
