/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:06:48 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/29 19:06:50 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "Fixed.h"

class	Fixed {

	public:

		Fixed(void);
		Fixed(const Fixed& Fixed);
		Fixed(const int i);
		Fixed(const float i);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed& operator=(const Fixed& Fixed);

	private:

		int					_rawBits;
		static const int	_fracBits;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif