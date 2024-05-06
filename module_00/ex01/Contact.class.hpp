/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:44 by aperis-p          #+#    #+#             */
/*   Updated: 2024/05/06 19:51:08 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define	CONTACT_H

#include "PhoneBook.hpp"

class Contact {

public:

	int 		getIndex(void) const;
	void 		setIndex(int i);
	std::string getFirstName(void) const;
	void 		setFirstName(std::string str);
	std::string getLastName(void) const;
	void 		setLastName(std::string str);
	std::string getPhoneNumber(void) const;
	void 		setPhoneNumber(std::string str);
	std::string getNickName(void) const;
	void 		setNickName(std::string str);
	std::string getDarkestSecret(void) const;
	void 		setDarkestSecret(std::string str);
	
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