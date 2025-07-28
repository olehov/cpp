/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:25:11 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/12 12:15:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->contactsCount = 0;
}

void PhoneBook::printAllContacts()
{
	std::string	indx;

	std::cout << "┌─────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│    Index│First Name│ Last Name│  Nickname│" << std::endl;
	for (int i = 0; i < contactsCount; i++)
	{
		std::cout << "├─────────┼──────────┼──────────┼──────────┤" << std::endl;
		std::cout << "│        " << i;
		printSingleContact(contacts[i]);
		std::cout << std::endl;
	}
	std::cout << "└─────────┴──────────┴──────────┴──────────┘" << std::endl;
}

Contact PhoneBook::getContactById(int id)
{
	if (id >= 0 && id < contactsCount)
	{
		return contacts[id];
	}
	return Contact();
}

void PhoneBook::addContact(Contact contact)
{
	if (index < maxContactsSize)
	{
		contacts[index] = contact;
		index++;
		if (contactsCount != 8)
		{
			contactsCount++;
		}
	}
	if (index == maxContactsSize)
	{
		index = 0;
	}
}

PhoneBook::~PhoneBook()
{
}

void	printStr(std::string str)
{
	size_t	i = 0;
	size_t	size = str.size();

	if (size > 10)
	{
		while (i < 9)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << ".";
	} else
	{
		while (i + size != 10)
		{
			std::cout << " ";
			i++;
		}
		i = 0;
		while (i < size)
		{
			std::cout << str[i];
			i++;
		}
	}
}

void PhoneBook::printSingleContact(Contact contact)
{
	std::cout << "│";
	printStr(contact.getFirstName());
	std::cout << "│";
	printStr(contact.getLastName());
	std::cout << "│";
	printStr(contact.getNickname());
	std::cout << "│";
}
