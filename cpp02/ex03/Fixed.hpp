/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:27:03 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/20 17:16:01 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__H__
#define __FIXED__H__

#include <iostream>

class Fixed
{
private:
	int	_rawBits;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);

	/*Overloading copy assignment */
	Fixed& operator=(const Fixed& other);

	/*Overloading comparison operators*/
	bool operator!=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	
	/*Overloading arithmetic operators*/
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	/*Overloading increment/decrement operators*/
	Fixed&	operator++();		// ++x
	Fixed	operator++(int);	// x++
	Fixed&	operator--();		// --x
	Fixed	operator--(int);	// x--

	int getRawBits(void) const;

	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
		
	static Fixed fromRawBits(int raw);
	
	~Fixed();
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif  //!__FIXED__H__