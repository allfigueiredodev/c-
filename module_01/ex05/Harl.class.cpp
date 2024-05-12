#include "Harl.hpp"

int Harl::_i = -1;

Harl::Harl(void) {
	Harl::_complain[0].key = "DEBUG";
	Harl::_complain[0].fptr = &Harl::debug;
	Harl::_complain[1].key = "INFO";
	Harl::_complain[1].fptr = &Harl::info;
	Harl::_complain[2].key = "WARNING";
	Harl::_complain[2].fptr = &Harl::warning;
	Harl::_complain[3].key = "ERROR";
	Harl::_complain[3].fptr = &Harl::error;
};

Harl::~Harl(void) {};

void Harl::complain( std::string level ){
	Harl::_i++;
	level.compare(Harl::_complain[Harl::_i].key) == 0 ? (this->*_complain[Harl::_i].fptr)() : complain(level);
	return ;
}

void Harl::debug( void ){
	std::cout << CYAN << "[DEBUG]" << DFT << std::endl;
	std::cout <<  "I love having extra bacon for my ";
	std::cout <<  "7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout <<  "I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << GREEN << "[INFO]" << DFT << std::endl;
	std::cout <<  "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout <<  "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout <<  "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << YELLOW << "[WARNING]" << DFT << std::endl;
	std::cout <<  "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout <<  "I’ve been coming for years whereas you started ";
	std::cout <<  "working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << RED << "[WARNING]" << DFT << std::endl;
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}