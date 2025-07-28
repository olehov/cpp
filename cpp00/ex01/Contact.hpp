/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:13:12 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/09 15:50:05 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	darkestSecret;
	std::string	phoneNumber;

public:
	Contact();
	Contact(const Contact& other);
	Contact(std::string	firstName, std::string lastName, std::string nickname,
		std::string darkestSecret, std::string phoneNumber);

	Contact& operator=(const Contact& other);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getDarkestSecret() const;
	std::string	getPhoneNumber() const;

	void	printContact();

	~Contact();
};
