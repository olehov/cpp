/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:18 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 12:04:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->type = "Dog";
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	this->type = other.type;
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "[Cat] Copy assignment operator called" << std::endl;
	}
	else
	{
		std::cout << "[Cat] Copy assignment operator: self-assignment ignored" << std::endl;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;	
}
