/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:03:42 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/02 15:46:24 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "";
	this->_damage = 0;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_damage = 0;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	std::cout << "[ClapTrap] Constructor with name called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_damage = other._damage;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	std::cout << "[ClapTrap] Copy constructor called for " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_damage = other._damage;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		std::cout << "[ClapTrap] Copy assignment operator called for " << other._name << std::endl;
	}
	else
	{
		std::cout << "[ClapTrap] Copy assignment operator: self-assignment ignored for " << this->_name << std::endl;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " failed to attack!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " took ";
	if (amount > this->_hitPoints)
	{
		std::cout << this->_hitPoints << " points of damage!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " failed to heal!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " repairs itself and regains " << amount << " of hit points" << std::endl;
}

const std::string& ClapTrap::getName() const
{
	return (this->_name);
}

const int& ClapTrap::getDamage() const
{
	return (this->_damage);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Destructor called for " << this->_name << std::endl;
}