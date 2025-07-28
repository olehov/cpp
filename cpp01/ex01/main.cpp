/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:36:12 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 11:36:51 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int		count = 5;
	Zombie*	horde = zombieHorde(count, "Zed");

	if (horde)
	{
		for (int i = 0; i < count; ++i)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
	return (0);
}
