/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:11:40 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 14:44:33 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "Empty thought";
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		std::cout << "[Brain] Copy assignment operator called" << std::endl;
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	else
	{
		std::cout << "[Cat] Copy assignment operator: self-assignment ignored" << std::endl;
	}
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index >= this->_ideas_len || index < 0)
	{
		std::cerr << "Error: [Brain] getIdea: index out of range" << std::endl;
		return "";
	}
	return (this->_ideas[index]);
}

int Brain::getIdeasLen() const
{
	return this->_ideas_len;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= this->_ideas_len || index < 0)
	{
		std::cerr << "Error: [Brain] setIdea: index out of range" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor called" << std::endl;
}
