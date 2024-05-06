/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:44 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/06 09:55:52 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define	CONTACT_H

#define NBR 3

#include <iostream>
#include <string>

class Contact {

public:

	std::string getIndex(void) const;
	void setIndex(int i);
	
	Contact(void);
	~Contact(void);

private:

	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_phoneNumber;
	std::string	_nickName;
	std::string	_darkestSecret;
};
#endif