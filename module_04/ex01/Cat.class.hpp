/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:20:55 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/29 21:19:48 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "Polymorphism.h"
#include "Brain.class.hpp"

class Cat : public Animal {

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