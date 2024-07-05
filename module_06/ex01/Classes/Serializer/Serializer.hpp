/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:43:13 by aperis-p          #+#    #+#             */
/*   Updated: 2024/07/04 13:43:15 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Serializer.h"
#include "Data.h"

class Serializer {

    private:
        Serializer(void);
        Serializer(const Serializer& Serializer);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer(void);
    
    public:
    	static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif

