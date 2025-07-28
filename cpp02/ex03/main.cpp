/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:48:59 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/20 18:10:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

#define CHECK(expr) \
	std::cout << (expr ? "✅" : "❌") << " " << #expr << std::endl << std::endl;

void	printInfo(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << " Name(x, y)" << std::endl
		<< "    A(" << a.getX() << ", " << a.getY() << ")" << std::endl
		<< "    B(" << b.getX() << ", " << b.getY() << ")" << std::endl
		<< "    C(" << c.getX() << ", " << c.getY() << ")" << std::endl
		<< "POINT(" << point.getX() << ", " << point.getY() << ")" << std::endl;
}

void testBSP()
{
	std::cout << "Test 1: Point inside the triangle\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(1, 1);
		printInfo(a, b, c, p);
		CHECK(bsp(a, b, c, p)); // ✅
	}

	std::cout << "Test 2: Point outside the triangle\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(5, 5);
		printInfo(a, b, c, p);
		CHECK(!bsp(a, b, c, p)); // ❌
	}

	std::cout << "Test 3: Point on a vertex of the triangle\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(0, 0);
		printInfo(a, b, c, p);
		CHECK(!bsp(a, b, c, p)); // ❌
	}

	std::cout << "Test 4: Point on edge AB\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(2, 0);
		printInfo(a, b, c, p);
		CHECK(!bsp(a, b, c, p)); // ❌
	}

	std::cout << "Test 5: Point on edge AC\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(0, 2);
		printInfo(a, b, c, p);
		CHECK(!bsp(a, b, c, p)); // ❌
	}

	std::cout << "Test 6: Point on edge BC\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(2, 2);
		printInfo(a, b, c, p);
		CHECK(!bsp(a, b, c, p)); // ❌
	}

	std::cout << "Test 7: Point exactly in center of equilateral triangle\n";
	{
		Point a(0, 0), b(4, 0), c(2, 3.464f);
		Point p(2, 1.1547f);
		printInfo(a, b, c, p);
		CHECK(bsp(a, b, c, p)); // ✅
	}

	std::cout << "Test 8: Point just outside near a vertex\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(-0.001f, 0.001f);
		printInfo(a, b, c, p);
		CHECK(!bsp(a, b, c, p)); // ❌
	}

	std::cout << "Test 9: Point just inside, near the edge\n";
	{
		Point a(0, 0), b(4, 0), c(0, 4);
		Point p(0.4f, 0.01f);
		printInfo(a, b, c, p);
		CHECK(bsp(a, b, c, p)); // ✅
	}

	std::cout << "Test 10: Point inside a scalene triangle\n";
	{
		Point a(-7, 4), b(-5, 2), c(-3, 4);
		Point p(-5.999f, 3.003f);
		printInfo(a, b, c, p);
		CHECK(bsp(a, b, c, p)); // ✅
	}

	std::cout << "Test 11: Point on the edge of a scalene triangle\n";
	{
		Point a(-7, 4), b(-5, 2), c(-3, 4);
		Point p(-5, 3);
		printInfo(a, b, c, p);
		CHECK(bsp(a, b, c, p)); // ❌
	}

	std::cout << "Test 12: Point far outside the triangle\n";
	{
		Point a(0, 0), b(1, 0), c(0, 1);
		Point p(100, 100);
		printInfo(a, b, c, p);
		CHECK(!bsp(a, b, c, p)); // ❌
	}
}

int main()
{
	testBSP();
	return 0;
}
