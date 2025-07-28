/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:54:39 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/11 12:04:11 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "";
	std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "[WrongAnimal] Copy constructor called for " << other.type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "[WrongAnimal] Copy assignment operator called for " << other.type << std::endl;
	return (*this);
}

const std::string& WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const 
{
	std::cout << "[WrongAnimal] makes a generic WrongAnimal sound." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}
