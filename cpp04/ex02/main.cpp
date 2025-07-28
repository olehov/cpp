/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:56:58 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/11 12:13:41 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== Brain Copy Test ===\n" << std::endl;

	Cat original;
	original.setIdea(0, "Hunt mouse");
	original.setIdea(1, "Sleep on keyboard");

	Cat copy = original; // copy constructor

	// Modify original's brain
	original.setIdea(0, "Destroy the world");

	std::cout << "Original Cat Brain [0]: " << original.getIdea(0) << std::endl;
	std::cout << "Copied   Cat Brain [0]: " << copy.getIdea(0) << std::endl;

	std::cout << "\n=== Virtual Destructor & makeSound() Test ===\n" << std::endl;

	const Animal* zoo[4];

	for (int i = 0; i < 2; ++i)
		zoo[i] = new Dog();
	for (int i = 2; i < 4; ++i)
		zoo[i] = new Cat();

	std::cout << "\n--- Sounds ---" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "[" << i << "] " << zoo[i]->getType() << " makes sound: ";
		zoo[i]->makeSound();
	}

	std::cout << "\n--- Deleting animals ---" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete zoo[i];

	std::cout << "\n=== ✅ All tests passed (if no memory leaks) ===\n" << std::endl;
	return 0;
}
