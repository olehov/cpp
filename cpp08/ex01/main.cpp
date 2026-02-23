/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:41:05 by ogrativ           #+#    #+#             */
/*   Updated: 2026/02/20 16:14:07 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void basicTest()
{
	std::cout << "=== BASIC TEST ===" << std::endl;

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void overflowTest()
{
	std::cout << "=== OVERFLOW TEST ===" << std::endl;

	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3); // має кинути exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void notEnoughElementsTest()
{
	std::cout << "=== NOT ENOUGH ELEMENTS TEST ===" << std::endl;

	try
	{
		Span sp(5);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl; // має кинути exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void largeTest()
{
	std::cout << "=== LARGE TEST (10000 numbers) ===" << std::endl;

	Span sp(10000);

	for (int i = 0; i < 10000; i++)
		sp.addNumber(std::rand());

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void rangeTest()
{
	std::cout << "=== RANGE TEST ===" << std::endl;

	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)
		vec.push_back(i * 10);

	Span sp(5);
	sp.addRange(vec.begin(), vec.end());

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	basicTest();
	overflowTest();
	notEnoughElementsTest();
	largeTest();
	rangeTest();

	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }