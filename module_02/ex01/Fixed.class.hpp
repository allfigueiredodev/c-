#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include "Fixed.hpp"

class	Fixed {

	public:

		Fixed(void);
		Fixed(const Fixed& Fixed);
		Fixed(const int i);
		Fixed(const float i);
		Fixed& operator=(const Fixed& Fixed);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void );
		int toInt( void ) const;

	private:

		int					_rawBits;
		static const int	_fracBits;
};

#endif