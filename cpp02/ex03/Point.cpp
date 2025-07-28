/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:45:31 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/20 15:33:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y) {}

Point::Point(const Point& other): _x(other.getX()), _y(other.getY()) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

bool Point::operator==(const Point& other) const
{
	return (_x == other.getX() && _y == other.getY());
}

bool Point::operator!=(const Point& other) const
{
	return !(*this == other);
}

bool Point::operator<=(const Point& other) const
{
	return (*this < other || *this == other);
}

bool Point::operator>=(const Point& other) const
{
	return (*this > other || *this == other);
}

bool Point::operator<(const Point& other) const
{
	if (this->_x < other.getX())
	{
		return (true);
	}
	if (this->_x == other.getX() && this->_y < other.getY())
	{
		return (true);
	}
	return (false);
}

bool Point::operator>(const Point& other) const
{
	if (this->_x > other.getX())
	{
		return (true);
	}
	if (this->_x == other.getX() && this->_y > other.getY())
	{
		return (true);
	}
	return (false);
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}

float Point::distanceTo(const Point& other) const
{
	float dx = _x.toFloat() - other.getX().toFloat();
	float dy = _y.toFloat() - other.getY().toFloat();
	return (sqrtNewton(dx * dx + dy * dy));
}

Point::~Point()
{
	
}
