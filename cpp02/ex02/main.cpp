/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:32:22 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/19 15:33:30 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}

// int main()
// {
// 	std::cout << "=== Constructors ===" << std::endl;
// 	Fixed a;
// 	Fixed b(5);
// 	Fixed c(2.5f);
// 	Fixed d = b;

// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << "c: " << c << std::endl;
// 	std::cout << "d (copy of b): " << d << std::endl;

// 	std::cout << "\n=== Arithmetic ===" << std::endl;
// 	std::cout << "b + c = " << (b + c) << std::endl;
// 	std::cout << "b - c = " << (b - c) << std::endl;
// 	std::cout << "b * c = " << (b * c) << std::endl;
// 	std::cout << "b / c = " << (b / c) << std::endl;

// 	std::cout << "\n=== Comparisons ===" << std::endl;
// 	std::cout << "b > c? " << (b > c) << std::endl;
// 	std::cout << "b < c? " << (b < c) << std::endl;
// 	std::cout << "b == d? " << (b == d) << std::endl;
// 	std::cout << "b != c? " << (b != c) << std::endl;

// 	std::cout << "\n=== Increments ===" << std::endl;
// 	Fixed e;
// 	std::cout << "e: " << e << std::endl;
// 	std::cout << "++e: " << ++e << std::endl;
// 	std::cout << "e: " << e << std::endl;
// 	std::cout << "e++: " << e++ << std::endl;
// 	std::cout << "e: " << e << std::endl;

// 	std::cout << "\n=== Decrements ===" << std::endl;
// 	std::cout << "--e: " << --e << std::endl;
// 	std::cout << "e--: " << e-- << std::endl;
// 	std::cout << "e: " << e << std::endl;

// 	std::cout << "\n=== Min/Max ===" << std::endl;
// 	Fixed x(10);
// 	Fixed y(42.42f);
// 	std::cout << "min(x, y): " << Fixed::min(x, y) << std::endl;
// 	std::cout << "max(x, y): " << Fixed::max(x, y) << std::endl;

// 	const Fixed cx(0.1f);
// 	const Fixed cy(0.2f);
// 	std::cout << "min(const): " << Fixed::min(cx, cy) << std::endl;
// 	std::cout << "max(const): " << Fixed::max(cx, cy) << std::endl;

// 	return (0);
// }
