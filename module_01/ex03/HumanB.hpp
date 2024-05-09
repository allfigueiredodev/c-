/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:28:01 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/09 20:49:07 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB {

	public:
		
		void setWeapon(Weapon &weapon);
		void attack(void);
	

		HumanB(std::string name);
		~HumanB(void);
	
	private:

		std::string _name;
		Weapon		*_weapon;	
		
};

#endif