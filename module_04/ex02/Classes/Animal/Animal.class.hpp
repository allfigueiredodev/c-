/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:34:04 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/31 07:53:06 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_HPP
#define AANIMAL_CLASS_HPP

#include "Polymorphism.h"

class AAnimal {
	
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(const AAnimal& AAnimal);
		AAnimal& operator=(const AAnimal& rhs);
		virtual void makeSound(void) const = 0;
		virtual std::string getType(void) const;
		void setType(std::string type);
	
	protected:
		std::string type;
		
};

#endif