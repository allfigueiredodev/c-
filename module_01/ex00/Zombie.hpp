#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class	Zombie {

	public:

		void 	announce( void );

		Zombie(std::string name);
		~Zombie(void);

	private:

		std::string	_name;

};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif