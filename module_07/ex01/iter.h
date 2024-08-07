/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:06:46 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 20:27:11 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>
#include <string>

#define println(x) std::cout << x << DFT << std::endl;
#define errorln(x) std::cerr << RED << x << DFT << std::endl;

#define BLUE_GREEN	"\033[32;44m"
#define MAG_YE		"\033[33;45m"
#define RED     	"\033[1;31m"
#define GREEN   	"\033[1;32m"
#define YELLOW 		"\033[1;33m"
#define BLUE    	"\033[1;34m"
#define MAGENTA    	"\033[1;35m"
#define CYAN    	"\033[1;36m"
#define WHITE    	"\033[1;37m"
#define ORANGE		"\033[0;38;5;166m"
#define GREY		"\033[38;5;244m"
#define DFT   		"\033[0m"

template<typename T>
void squaring(T& a) {
	println(GREEN << a << "^2 = " << a*a);
}

template<typename TARR>
void iter(TARR* arr, int size, void(*fptr)(const TARR& data)) {
	if (!arr || size <= 0){
		errorln("Invalid parameters.");
		return ;
	}
	for(int i = 0; i < size; i++){
		fptr(arr[i]);
	}
}

template<typename TARR>
void iter(TARR* arr, int size, void(*fptr)(TARR& data)) {
	if (!arr || size <= 0){
		errorln("Invalid parameters.");
		return ;
	}
	for(int i = 0; i < size; i++){
		fptr(arr[i]);
	}
}

#endif