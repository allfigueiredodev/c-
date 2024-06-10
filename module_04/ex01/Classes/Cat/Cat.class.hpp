/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:20:55 by aperis-p          #+#    #+#             */
/*   Updated: 2024/06/10 16:46:34 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "Polymorphism.h"

class Cat : public Animal {

	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat& Cat);
		Cat& 		operator=(const Cat& rhs);
		std::string getType(void) const;
		void 		makeSound(void) const;
		void 		tellIdeas(void);
		void		printBrainAdress(void);

	private:
		std::string type;
		Brain* _catBrain;
		
};

#endif