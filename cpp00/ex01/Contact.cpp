/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:30:55 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/12 12:15:07 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->darkestSecret = "";
	this->phoneNumber = "";
}

Contact::Contact(const Contact& other)
{
	this->firstName = other.firstName;
	this->lastName = other.lastName;
	this->nickname = other.nickname;
	this->darkestSecret = other.darkestSecret;
	this->phoneNumber = other.phoneNumber;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
		std::string darkestSecret, std::string phoneNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->darkestSecret = darkestSecret;
	this->phoneNumber = phoneNumber;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		this->firstName = other.firstName;
		this->lastName = other.lastName;
		this->nickname = other.nickname;
		this->darkestSecret = other.darkestSecret;
		this->phoneNumber = other.phoneNumber;
	}
	return *this;
}

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getNickname() const
{
	return this->nickname;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}

std::string Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

void Contact::printContact()
{
	if (this->firstName.empty())
	{
		std::cout << "404 contact not found" << std::endl;
		return;
	}
	std::cout << "First name: " << this->firstName << std::endl
		<< "Last name: " << this->lastName << std::endl
		<< "Nickname: " << this->nickname << std::endl
		<< "Phone number: " << this->phoneNumber << std::endl
		<< "Darkest secret: " << this->darkestSecret << std::endl;
}

Contact::~Contact()
{
}
