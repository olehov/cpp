/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:27:03 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/19 12:31:31 by ogrativ          ###   ########.fr       */
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

	Fixed& operator=(const Fixed& other);
	
	int getRawBits(void) const;

	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	~Fixed();
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif  //!__FIXED__H__