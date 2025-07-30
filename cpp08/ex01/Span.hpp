/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:24:31 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/30 16:13:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
private:
	unsigned int	_size;
	unsigned int	_len;
	int*	_numbers;

	Span();
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);

	void addNumber(int number);

	int shortestSpan();
	int longestSpan();

	~Span();
};

#endif  //!SPAN_HPP