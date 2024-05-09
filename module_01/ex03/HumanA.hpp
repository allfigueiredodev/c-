/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:28:01 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/09 20:48:52 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA {

	public:
	
		void attack(void);

		
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
	
	private:
	
		std::string _name;
		Weapon 		&_weapon;
};

#endif