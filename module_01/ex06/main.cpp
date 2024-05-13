#include "Harl.hpp"

int main (int argc, char **argv)
{
	if (argc > 2){
		std::cerr << "Too much problems to deal with..." << std::endl;
		return (1);
	}
	else if (argc == 1){
		std::cerr << "I got 99 problems but a Harl ain't one" << std::endl;
		return (1);
	}
	Harl	harl;

	harl.complain(argv[1]);
}