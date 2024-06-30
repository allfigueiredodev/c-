#ifndef WHATEVER_H
#define WHATEVER_H

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

template<typename TSWAP>
void swap(TSWAP& a, TSWAP& b){
TSWAP temp = a;
	a = b;
	b = temp;
}

template<typename TMIN>
const TMIN& min(const TMIN& a, const TMIN& b) {
	return((b <= a? b : a));
}

template<typename TMAX>
const TMAX& max(const TMAX& a, const TMAX& b) {
	return((b >= a? b : a));
}

#endif