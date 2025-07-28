/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:31 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/02 14:52:33 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_damage = 20;
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_damage = 20;
	std::cout << "[ScavTrap] Constructor with name called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "[ScavTrap] Copy constructor called for " << other._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "[ScavTrap] Copy assignment operator called for " << other._name << std::endl;
	}
	else
	{
		std::cout << "[ScavTrap] Copy assignment operator: self-assignment ignored for " << this->_name << std::endl;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " failed to attack!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode." << std::endl;
}


ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor called for " << this->_name << std::endl;
}
