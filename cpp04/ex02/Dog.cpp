/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:18 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 14:41:51 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
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

void Dog::makeSound() const
{
	std::cout << "WOOF!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Dog::setIdea(int index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
	delete (this->_brain);
}
