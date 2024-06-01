/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:20:55 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/31 07:54:23 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "Polymorphism.h"

class Cat : public AAnimal {

	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat& Cat);
		Cat& operator=(const Cat& rhs);
		std::string getType(void) const;
		void makeSound(void) const;
	
	private:
		std::string type;
		Brain* _catBrain;
		
};

#endif