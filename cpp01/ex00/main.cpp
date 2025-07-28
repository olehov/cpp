/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:17:53 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 11:19:29 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*newZombie1;

	newZombie1 = newZombie("New Zombie");
	newZombie1->announce();
	randomChump("Random Zombie");
	delete newZombie1;
	return (0);
}