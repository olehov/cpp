/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/07/02 15:00:22 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n🎮 [ARENA LOADED] Deploying basic ClapTraps...\n" << std::endl;

	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");

	std::cout << "\n🧬 A new unit is formed from Alpha's data...\n" << std::endl;
	ClapTrap clone;
	clone = alpha;

	std::cout << "\n🔫 Alpha spots Beta and takes the first shot!\n" << std::endl;
	alpha.attack(beta.getName());
	beta.takeDamage(alpha.getDamage());

	std::cout << "\n🩹 Beta applies quick medkit to recover...\n" << std::endl;
	beta.beRepaired(3);

	std::cout << "\n🔥 Beta retaliates with controlled burst at the clone!\n" << std::endl;
	beta.attack(clone.getName());
	clone.takeDamage(beta.getDamage());

	std::cout << "\n⚡ Clone locks onto Alpha and returns fire!\n" << std::endl;
	clone.attack(alpha.getName());

	std::cout << "\n💉 Clone injects itself with nanobots for quick repair...\n" << std::endl;
	clone.beRepaired(5);

	std::cout << "\n🏁 [SIMULATION COMPLETE] All units entering standby mode.\n" << std::endl;

	return 0;
}
