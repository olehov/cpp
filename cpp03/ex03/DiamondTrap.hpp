/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:14:09 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/02 15:32:10 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP__H__
#define __DIAMONDTRAP__H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);

	DiamondTrap& operator=(const DiamondTrap& other);

	using ScavTrap::attack;
	const std::string &getName() const;
	void whoAmI();

	~DiamondTrap();
};

#endif  //!__DIAMONDTRAP__H__