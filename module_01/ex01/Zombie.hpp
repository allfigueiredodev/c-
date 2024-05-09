#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class	Zombie {

	public:

		void 	announce( void );
		void	setZombieName(std::string name);
		Zombie(void);
		~Zombie(void);

	private:

		std::string	_name;

};

Zombie* zombieHorde( int N, std::string name );

#endif