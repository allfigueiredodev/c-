#ifndef FIXED_HPP
# define FIXED_HPP

# include "Fixed.h"

class Fixed
{
  public:
	Fixed(void);
	Fixed(const Fixed &Fixed);
	Fixed(const int i);
	Fixed(const float i);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed&	operator=(const Fixed &Fixed);
	Fixed	operator+(const Fixed &Fixed) const;
	Fixed	operator-(const Fixed &Fixed) const;
	Fixed	operator*(const Fixed &Fixed) const;
	Fixed	operator/(const Fixed &Fixed) const;
	bool	operator>(const Fixed &Fixed) const;
	bool	operator<(const Fixed &Fixed) const;
	bool	operator==(const Fixed &Fixed) const;
	bool	operator!=(const Fixed &Fixed) const;
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);
	static	Fixed& min(Fixed& a, Fixed& b);
	static	const Fixed& min(const Fixed& a, const Fixed& b);
	static	Fixed& max(Fixed& a, Fixed& b);
	static	const Fixed& max(const Fixed& a, const Fixed& b);

  private:
	int _rawBits;
	static const int _fracBits;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif