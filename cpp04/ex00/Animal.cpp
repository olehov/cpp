/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:54:39 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 12:06:59 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "";
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "[Animal] Copy constructor called for " << other.type << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	this->type = other.type;
	std::cout << "[Animal] Copy assignment operator called for " << other.type << std::endl;
	return (*this);
}

const std::string& Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const 
{
	std::cout << "[Animal] makes a generic animal sound." << std::endl;
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called" << std::endl;
}
