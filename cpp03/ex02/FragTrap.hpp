/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:36 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/02 15:26:58 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP__H__
#define __FRAGTRAP__H__

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);

	FragTrap& operator=(const FragTrap& other);

	void highFivesGuys(void);

	~FragTrap();
};

#endif  //!__FRAGTRAP__H__