/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/07/02 15:49:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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

	std::cout << "\n🚪 Reinforcements arriving: ScavTrap 'Delta' enters the arena!\n" << std::endl;
	ScavTrap delta("Delta");

	std::cout << "\n💥 Delta launches surprise attack on Alpha!\n" << std::endl;
	delta.attack(alpha.getName());
	alpha.takeDamage(delta.getDamage());

	std::cout << "\n🛡️ Delta activates Gate Keeper Mode!\n" << std::endl;
	delta.guardGate();

	std::cout << "\n📦 Clone unit spawned: Delta's copy deployed!\n" << std::endl;
	ScavTrap clone = delta;

	std::cout << "\n🤖 Clone turns against original Delta!\n" << std::endl;
	clone.attack(delta.getName());
	delta.takeDamage(clone.getDamage());

	std::cout << "\n✨ Special unit detected: FragTrap 'Frodo' drops into battle!\n" << std::endl;
	FragTrap frodo("Frodo");

	std::cout << "\n🙌 Frodo cheers: requesting high fives from all units!\n" << std::endl;
	frodo.highFivesGuys();

	std::cout << "\n💣 Frodo charges in with full firepower against Omega!\n" << std::endl;
	frodo.attack(omega.getName());
	omega.takeDamage(frodo.getDamage());

	// 🆕 DiamondTrap
	std::cout << "\n💎 Ultra elite unit deployed: DiamondTrap 'Diamond' enters combat zone!\n" << std::endl;
	DiamondTrap diamond("Diamond");

	std::cout << "\n🧠 Diamond evaluates the battlefield...\n" << std::endl;
	diamond.whoAmI();

	std::cout << "\n💎 Diamond targets Frodo with a precision strike!\n" << std::endl;
	diamond.attack(frodo.getName());
	frodo.takeDamage(diamond.getDamage());

	std::cout << "\n🛠️ Diamond self-repairs and prepares for final push...\n" << std::endl;
	diamond.beRepaired(20);

	std::cout << "\n🚨 [EXTRACTION INCOMING] Ending simulation...\n" << std::endl;

	return 0;
}
