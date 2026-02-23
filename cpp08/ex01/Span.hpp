/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:24:31 by ogrativ           #+#    #+#             */
/*   Updated: 2026/02/20 16:08:51 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>

class Span
{
private:
	unsigned int _size;
	unsigned int _len;
	int *_numbers;

	Span();

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);

	void addNumber(int number);

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		unsigned int distance = std::distance(begin, end);
		if (_len + distance > _size)
			throw std::out_of_range("Range too big");

		while (begin != end)
			_numbers[_len++] = *begin++;
	}

	int shortestSpan();
	int longestSpan();

	~Span();
};

#endif //! SPAN_HPP