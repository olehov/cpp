/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:48:48 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/20 18:02:16 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

float sqrtNewton(float value)
{
	if (value < 0)
		return (-1);

	float x = value;
	float approx = value / 2.0f;

	for (int i = 0; i < 10; ++i)
	{
		approx = 0.5f * (approx + x / approx);
	}
	return (approx);
}

bool	checkVertex(Point const a, Point const b, Point const c, Point const point)
{
	if (a == point || b == point || c == point)
	{
		return (true);
	}
	return (false);
}


float fabsf_custom(float x) {
	return (x < 0 ? -x : x);
}

float area(Point const& p1, Point const& p2, Point const& p3)
{
	float x1 = p1.getX().toFloat();
	float y1 = p1.getY().toFloat();
	float x2 = p2.getX().toFloat();
	float y2 = p2.getY().toFloat();
	float x3 = p3.getX().toFloat();
	float y3 = p3.getY().toFloat();

	return fabsf_custom(
		(x1 * (y2 - y3) +
		 x2 * (y3 - y1) +
		 x3 * (y1 - y2)) / 2.0f);
}

// /*
// 	a = len between pA and pB
// 	b = len between pB and pC
// 	c = len between pC and pA
// */
// float area(Point const& pA, Point const& pB, Point const& pC)
// {
// 	float	s, p, a, b, c;

// 	a = pA.distanceTo(pB);
// 	b = pB.distanceTo(pC);
// 	c = pC.distanceTo(pA);
// 	p = (a + b + c) / 2;
// 	s = sqrtNewton(p * (p - a) * (p - b) * (p - c));
// 	return (s);
// }

bool	isTriangle(Point const a, Point const b, Point const c)
{
	return (a != b && b != c && c != a && area(a, b, c) > 0.00001f);
}

bool	isInside(Point const a, Point const b, Point const c, Point const point)
{
	float areaABC = area(a, b, c);
	float areaPAB = area(point, a, b);
	float areaPBC = area(point, b, c);
	float areaPCA = area(point, c, a);

	if (checkVertex(a, b, c, point)
	|| areaPAB <= 0 || areaPBC <= 0 || areaPCA <= 0)
	{
		return (false);
	}
	if (areaPAB > 0 && areaPBC > 0 && areaPCA > 0 &&
		(areaABC - (areaPAB + areaPBC + areaPCA) >= -0.01f))
	{
		return (true);
	}	
	return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isTriangle(a, b, c) && isInside(a, b, c, point))
	{
		return (true);
	}
	return (false);
}