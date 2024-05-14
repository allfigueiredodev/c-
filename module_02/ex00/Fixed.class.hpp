#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include "Fixed.hpp"

class	Fixed {

	public:

		Fixed(void);
		Fixed(const Fixed& Fixed);
		Fixed& operator=(const Fixed& Fixed);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:

		int	_i;
		static const int	_fracBits;
};

#endif