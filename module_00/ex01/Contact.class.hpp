/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:44 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/02 20:55:14 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define	CONTACT_H

#define NBR 8

#include <iostream>
#include <string>


class Contact {

public:

	int			index;
	std::string	firstName;
	std::string	lastName;
	std::string	phoneNumber;
	std::string	nickName;
	std::string	darkestSecret;
	
	Contact(void);
	~Contact(void);	

};
#endif