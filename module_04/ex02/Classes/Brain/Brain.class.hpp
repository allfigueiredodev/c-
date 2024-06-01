/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:59:06 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/30 20:38:36 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
#define BRAIN_CLASS_HPP

#include "Polymorphism.h"

class Brain {
	
	public:
		Brain(void);
		Brain(const Brain& Brain);
		Brain& operator=(const Brain& Brain);
		~Brain(void);
	
	private:
		std::string _ideas[100];
	
};

#endif
