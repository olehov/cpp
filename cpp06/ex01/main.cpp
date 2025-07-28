/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:30:47 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/28 16:39:44 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* original = new Data;
	original->name = "Alice";
	original->phone = 123456789;
	original->age = 30;

	std::cout << "Original data:\n";
	printData(*original);
	std::cout << "Address of original: " << original << std::endl;

	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "\nDeserialized data:\n";
	printData(*deserialized);
	std::cout << "Address of deserialized: " << deserialized << std::endl;

	if (original == deserialized)
		std::cout << "\n Success: Pointers match!" << std::endl;
	else
		std::cout << "\n Error: Pointers do not match!" << std::endl;

	delete original;
	return 0;
}