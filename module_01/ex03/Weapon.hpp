/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:35:11 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/09 20:21:29 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	
	public:
	
		const		std::string  &getType(void);
		void		setType(std::string type);
		
		Weapon(void);
		Weapon(std::string w_type);
		~Weapon(void);
	
	private:

		std::string _type;
		
};

#endif