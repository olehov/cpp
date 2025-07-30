/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:24:17 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/30 11:29:10 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printInt(const int& x)
{
	std::cout << "int: " << x << std::endl;
}

void printFloat(const float& x)
{
	std::cout << "float: " << x << std::endl;
}

void printChar(const char& x)
{
	std::cout << "char: '" << x << "'" << std::endl;
}

void increment(int& x)
{
	x += 1;
}

void toUpper(char& c)
{
	if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
}

struct Person
{
	std::string name;
	int age;
};

void printPerson(const Person& p)
{
	std::cout << "Person: " << p.name << ", " << p.age << " y/o" << std::endl;
}

void growOlder(Person& p)
{
	p.age++;
}

int main()
{
	// ===== INT TEST =====
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array:" << std::endl;
	iter(intArr, 5, printInt);

	std::cout << "Incremented int array:" << std::endl;
	iter(intArr, 5, increment);
	iter(intArr, 5, printInt);

	// ===== FLOAT TEST =====
	float floatArr[] = {1.1f, 2.2f, 3.3f};
	std::cout << "\nFloat array:" << std::endl;
	iter(floatArr, 3, printFloat);

	// ===== CHAR TEST =====
	char charArr[] = {'a', 'b', 'c', 'd'};
	std::cout << "\nOriginal char array:" << std::endl;
	iter(charArr, 4, printChar);

	std::cout << "Uppercase char array:" << std::endl;
	iter(charArr, 4, toUpper);
	iter(charArr, 4, printChar);

	// ===== CONST TEST =====
	const int constArr[] = {10, 20, 30};
	std::cout << "\nConst int array:" << std::endl;
	iter(constArr, 3, printInt);

	// ===== CUSTOM TYPE TEST =====
	Person people[] = {
		{"Alice", 30},
		{"Bob", 25},
		{"Charlie", 40}
	};

	std::cout << "\nOriginal persons:" << std::endl;
	iter(people, 3, printPerson);

	std::cout << "People after aging:" << std::endl;
	iter(people, 3, growOlder);
	iter(people, 3, printPerson);

	return 0;
}
