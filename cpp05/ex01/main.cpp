/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:14:45 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/14 17:25:02 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== Testing Form creation with valid grades ===\n";
	try {
		Form f1("Employment Form", 50, 20);
		std::cout << f1 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Form creation with invalid grades ===\n";
	try {
		Form f2("Invalid High", 0, 20); // too high
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f3("Invalid Low", 50, 151); // too low
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Bureaucrat signing a form (success case) ===\n";
	try {
		Bureaucrat bob("Bob", 30);
		Form taxForm("TaxForm", 50, 20);

		std::cout << taxForm << std::endl;
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Bureaucrat signing a form (failure case) ===\n";
	try {
		Bureaucrat tim("Tim", 120);
		Form secret("SecretForm", 50, 20);

		std::cout << secret << std::endl;
		tim.signForm(secret);
		std::cout << secret << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Testing multiple signatures (should not re-sign) ===\n";
	try {
		Bureaucrat alice("Alice", 10);
		Form f("VisaApplication", 20, 10);

		alice.signForm(f);  // should sign
		alice.signForm(f);  // should say it's already signed
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== All tests finished ===\n";

	return 0;
}
