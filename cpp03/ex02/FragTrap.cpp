/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:48:46 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/02 14:53:46 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_damage = 30;
	std::cout << "[FragTrap] Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_damage = 30;
	std::cout << "[FragTrap] Constructor with name called for " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "[FragTrap] Copy constructor called for " << other._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "[FragTrap] Copy assignment operator called for " << other._name << std::endl;
	}
	else
	{
		std::cout << "[FragTrap] Copy assignment operator: self-assignment ignored for " << this->_name << std::endl;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is requesting a high five!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] Destructor called for " << this->_name << std::endl;
}
