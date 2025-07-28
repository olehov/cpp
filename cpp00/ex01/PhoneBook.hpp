/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:48:23 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/09 14:24:25 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	const static int	maxContactsSize = 8;
	int	index;
	int	contactsCount;
	Contact	contacts[maxContactsSize];

public:
	PhoneBook();
	void	printAllContacts();
	Contact	getContactById(int id);
	void	addContact(Contact contact);
	~PhoneBook();

private:
	void	printSingleContact(Contact contact);
};