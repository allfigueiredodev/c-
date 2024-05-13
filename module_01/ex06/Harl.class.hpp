#ifndef HARL_CLASS_HPP
#define	HARL_CLASS_HPP

#include "Harl.hpp"

class Harl {
	
	public:

		void complain( std::string level );

		Harl(void);
		~Harl(void);

	private:

		typedef		struct s_complain {
			std::string				key;
			void	(Harl::*fptr)(void);
		}					t_complain;

		t_complain	_complain[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};


#endif