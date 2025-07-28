/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:57:37 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/12 14:35:10 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

enum Command
{
	ADD,
	SEARCH,
	EXIT,
	DEFAULT
};

bool	checkValidString(std::string str)
{
	size_t	size;
	size_t	i = 0;

	if (str.empty() || str.compare("\"\"") == 0 || str.compare("\0") == 0 || str.compare("\\0") == 0)
	{
		return false;
	}
	size = str.size();
	while (str[i] == ' ')
	{
		i++;
	}
	if (i == size)
	{
		return false;
	}
	return true;
	
}

std::string toUpperCase(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = (char)toupper((unsigned char)str[i]);
	}
	return str;
}

void	addContact(PhoneBook *phonebook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	secret;
	std::string	phoneNumber;
	
	if (phonebook == NULL)
	{
		return;
	}
	try
	{
		std::cout << "Enter first name: ";
		std::cin >> firstName;
		std::cout<< "Enter last name: ";
		std::cin >> lastName;
		std::cout << "Enter nickname: ";
		std::cin >> nickname;
		std::cout << "Enter darkest secret: ";
		std::cin >> secret;
		std::cout << "Enter phone number: ";
		std::cin >> phoneNumber;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << std::endl << "Error: stdin was closed!" << std::endl << e.what();
		return;
	}
	if (!checkValidString(firstName) || !checkValidString(lastName) || !checkValidString(nickname)
	|| !checkValidString(secret) || !checkValidString(phoneNumber))
	{
		std::cout << std::endl << "Field is empty try again!" << std::endl;
		return;
	}
	Contact	contact(firstName, lastName, nickname, secret, phoneNumber);
	phonebook->addContact(contact);
}

Command getCommand(std::string input)
{
	std::string upper = toUpperCase(input);
	if (upper == "ADD")
	{
		return ADD;
	}
	else if (upper == "SEARCH")
	{
		return SEARCH;
	}
	else if (upper == "EXIT")
	{
		return EXIT;
	}	
	return DEFAULT;
}


int	main(void)
{
	Command		command;
	PhoneBook	phoneBook;
	std::string	input;
	int			id = 0;

	std::cin.exceptions(std::ios::failbit);
	while (true)
	{
		std::cout << "Enter command: ";
		try
		{
			std::cin >> input;
		}
		catch(const std::exception& e)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return 0;
		}
		std::cout << std::endl;
		command = getCommand(input);
		switch (command)
		{
		case ADD:
			addContact(&phoneBook);
			break;
		case SEARCH:
			phoneBook.printAllContacts();
			std::cout << std::endl << "Enter id: ";
			try
			{
				std::cin >> id;
			}
			catch (std::ios_base::failure& e)
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Invalid input. Please enter a number." << std::endl;
				continue;
			}
			std::cout << std::endl;
			phoneBook.getContactById(id).printContact();
			std::cout << std::endl;
			break;
		case EXIT:
			return 0;
		default:
			std::cout << "Command not found" << std::endl;
			break;
		}
		input.clear();
	}
	return 0;
}
