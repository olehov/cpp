/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:13:24 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 12:45:03 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON__H__
#define __WEAPON__H__

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon();
	Weapon(std::string type);

	void	setType(std::string type);
	std::string	getType() const;

	~Weapon();
};

#endif  //!__WEAPON__H__