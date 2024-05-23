#ifndef CLAP_TRAP_CLASS_HPP
#define	CLAP_TRAP_CLASS_HPP

#include "ClapTrap.hpp"

class ClapTrap {

	private:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& ClapTrap);
		ClapTrap& operator=(const ClapTrap& rhs);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setAttackDamage(unsigned int amount);
		unsigned int getAttackDamage(void);
		unsigned int getEnergyPoints(void);
};

#endif