#ifndef FIXED_HPP
#define FIXED_HPP

#include "Fixed.h"

class	Fixed {

	public:

		Fixed(void);
		Fixed(const Fixed& Fixed);
		Fixed& operator=(const Fixed& Fixed);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:

		int					_rawBits;
		static const int	_fracBits;
};

#endif