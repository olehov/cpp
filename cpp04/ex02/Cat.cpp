/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:18 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 14:40:43 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "[Cat] Copy assignment operator called" << std::endl;
		if (this->_brain)
			delete (this->_brain);
		this->_brain = new Brain(*other._brain);
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

std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Cat::setIdea(int index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;
	delete (this->_brain);
}
