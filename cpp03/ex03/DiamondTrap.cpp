/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:13:54 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/02 15:53:49 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_damage = FragTrap::_damage;
	std::cout << "[DiamondTrap] Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_damage = FragTrap::_damage;
	std::cout << "[DiamondTrap] Constructor with name called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	std::cout << "[DiamondTrap] Copy constructor called for " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		std::cout << "[DiamondTrap] Copy assignment operator called for " << other._name << std::endl;
	}
	else
	{
		std::cout << "[DiamondTrap] Copy assignment operator: self-assignment ignored for " << this->_name << std::endl;
	}
	return (*this);
}

const std::string& DiamondTrap::getName() const
{
	return (this->_name);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << ", and my ClapTrap name is " << ClapTrap::_name << "!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] Destructor called for " << this->_name << std::endl;
}
