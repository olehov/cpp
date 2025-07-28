/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:14:45 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/14 14:18:59 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Valid Bureaucrat Creation ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;

		std::cout << "\nIncrementing grade..." << std::endl;
		bob.incrementGrade();
		std::cout << "New grade: " << bob.getGrade() << std::endl;

		std::cout << "\nDecrementing grade..." << std::endl;
		bob.decrementGrade();
		std::cout << "New grade: " << bob.getGrade() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Invalid Bureaucrat Creation (Too High) ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 0); // too high
	}
	catch (std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Invalid Bureaucrat Creation (Too Low) ===" << std::endl;
	try {
		Bureaucrat eve("Eve", 200); // too low
	}
	catch (std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Increment Beyond Limit ===" << std::endl;
	try {
		Bureaucrat top("TopGuy", 1);
		top.incrementGrade(); // goes out of range
	}
	catch (std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Decrement Beyond Limit ===" << std::endl;
	try {
		Bureaucrat low("Intern", 150);
		low.decrementGrade(); // goes out of range
	}
	catch (std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
}
