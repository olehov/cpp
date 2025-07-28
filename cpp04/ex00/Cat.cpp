/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:18 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 12:03:57 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->type = "Cat";
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
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

void Cat::makeSound() const
{
	std::cout << "Meeeooow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;	
}
