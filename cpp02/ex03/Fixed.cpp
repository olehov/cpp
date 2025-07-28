/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:34:56 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/20 17:14:12 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->_rawBits = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	this->_rawBits = other._rawBits;
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->_rawBits = value << _fractionalBits;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->_rawBits = roundf(value * (1 << this-> _fractionalBits));
	// std::cout << "Float constructor called" << std::endl;
}

/*operators*/

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_rawBits = other._rawBits;
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

/*Overloading comparison operators*/

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawBits != other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_rawBits == other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawBits <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawBits >= other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_rawBits < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_rawBits > other.getRawBits());
}

/*Overloading arithmetic operators*/

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	int64_t mult = (int64_t)this->_rawBits * (int64_t)other._rawBits;
	int rawResult = static_cast<int>(mult >> _fractionalBits);
	return Fixed::fromRawBits(rawResult);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other._rawBits == 0)
		throw std::runtime_error("Division by zero");

	int64_t numerator = ((int64_t)this->_rawBits) << _fractionalBits;
	int rawResult = static_cast<int>(numerator / other._rawBits);
	return Fixed::fromRawBits(rawResult);
}

/*Overloading increment/decrement operators*/

Fixed& Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_rawBits--;
	return temp;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_rawBits++;
	return temp;
}

Fixed& Fixed::operator++()
{
	this->_rawBits++;
	return *this;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> _fractionalBits);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 <= fixed2)
	{
		return (fixed1);
	}
	return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 <= fixed2)
	{
		return (fixed1);
	}
	return (fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 >= fixed2)
	{
		return (fixed1);
	}
	return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 >= fixed2)
	{
		return (fixed1);
	}
	return (fixed2);
}

Fixed Fixed::fromRawBits(int raw)
{
	Fixed result;
	result._rawBits = raw;
	return result;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
