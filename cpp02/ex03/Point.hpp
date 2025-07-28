/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:45:50 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/20 15:03:56 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT__H__
#define __POINT__H__

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point& other);

	Point& operator=(const Point& other);

	/*Overloading comparison operators*/
	bool operator!=(const Point& other) const;
	bool operator==(const Point& other) const;
	bool operator<=(const Point& other) const;
	bool operator>=(const Point& other) const;
	bool operator<(const Point& other) const;
	bool operator>(const Point& other) const;

	Fixed	getX(void) const;
	Fixed	getY(void) const;

	float	distanceTo(const Point& other) const;

	~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
float	sqrtNewton(float value);

#endif  //!__POINT__H__