/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:50:26 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/02 16:00:58 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP__H__
#define __CLAPTRAP__H__

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	int				_energyPoints;
	int				_damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);

	ClapTrap& operator=(const ClapTrap& other);
	
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	const std::string &getName() const;
	const int	&getDamage() const;

	virtual ~ClapTrap();
};

#endif  //!__CLAPTRAP__H__