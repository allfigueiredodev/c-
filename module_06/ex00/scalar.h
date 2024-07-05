/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:42:44 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 13:42:47 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_H
#define SCALAR_H

#include <iostream>
#include <string>
#include <string.h>
#include <limits.h>
#include <limits>
#include <float.h>
#include <cmath>
#include <stdlib.h>
#include <unistd.h>
#include <ostream>
#include <sstream>

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

typedef enum TYPES {
	CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INF,
    NOTAN,
	TOTAL_TYPES,
} TYPES;

#endif