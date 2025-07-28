/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:01:22 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 11:38:46 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie(std::string name);

	void	announce();
	void	setName(std::string name);

	~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP