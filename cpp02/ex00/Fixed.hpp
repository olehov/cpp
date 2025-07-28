/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:27:03 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/19 11:40:48 by ogrativ          ###   ########.fr       */
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
	Fixed(const Fixed &fixed);

	Fixed& operator=(const Fixed& other);
	
	int getRawBits(void) const;

	void setRawBits(int const raw);

	~Fixed();
};

#endif  //!__FIXED__H__