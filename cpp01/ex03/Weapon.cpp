/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:15:24 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 12:45:01 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	this->_type = "";
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string Weapon::getType() const
{
	return (this->_type);
}

Weapon::~Weapon()
{
	std::cout << "weapot type <" << this->_type << "> destroyed" << std::endl;
}
