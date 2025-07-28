/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:33:43 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 12:54:44 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB__H__
#define __HUMANB__H__

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;
public:
	HumanB(std::string name);
	
	void	attack();
	void	setWeapon(Weapon& weapon);
	
	~HumanB();
};

#endif  //!__HUMANA__H__