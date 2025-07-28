/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/07/02 14:59:07 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n🎮 Initializing battlefield...\n" << std::endl;

	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");
	ClapTrap omega("Omega");

	std::cout << "\n🔫 Round 1: Alpha opens fire on Beta!\n" << std::endl;
	alpha.attack(beta.getName());
	beta.takeDamage(alpha.getDamage());

	std::cout << "\n🩹 Beta quickly patches up wounds...\n" << std::endl;
	beta.beRepaired(3);

	std::cout << "\n🔥 Round 2: Beta retaliates, Omega steps in!\n" << std::endl;
	beta.attack(omega.getName());
	omega.takeDamage(beta.getDamage());

	std::cout << "\n⚡ Omega strikes back!\n" << std::endl;
	omega.attack(alpha.getName());
	alpha.takeDamage(omega.getDamage());

	std::cout << "\n💉 Omega regenerates before next round...\n" << std::endl;
	omega.beRepaired(5);

	std::cout << "\n🚪 Reinforcements have arrived! ScavTrap Delta joins the fight!\n" << std::endl;
	ScavTrap delta("Delta");

	std::cout << "\n💥 Delta ambushes Alpha with full power!\n" << std::endl;
	delta.attack(alpha.getName());
	alpha.takeDamage(delta.getDamage());

	std::cout << "\n🛡️ Delta enters defensive stance: Gate Keeper Mode activated.\n" << std::endl;
	delta.guardGate();

	std::cout << "\n📦 A clone of Delta is deployed!\n" << std::endl;
	ScavTrap clone = delta;

	std::cout << "\n🤖 Clone turns on its creator! Chaos unfolds!\n" << std::endl;
	clone.attack(delta.getName());
	delta.takeDamage(clone.getDamage());

	std::cout << "\n🚨 [EXTRACTION INCOMING] Ending simulation...\n" << std::endl;

	return 0;
}
