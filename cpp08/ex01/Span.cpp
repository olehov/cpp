/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:32:22 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/30 16:39:50 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

Span::Span(unsigned int N)
{
	_numbers = new int[N];
	_size = N;
	_len = 0;
}

Span::Span(const Span& other)
{
	_numbers = new int[other._size];
	_size = other._size;
	_len = other._len;
	for (unsigned int i = 0; i < other._len; i++)
	{
		_numbers[i] = other._numbers[i];
	}
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		delete[] _numbers;
		_numbers = new int[other._size];
		_size = other._size;
		_len = other._len;
		for (unsigned int i = 0; i < other._len; i++)
		{
			_numbers[i] = other._numbers[i];
		}
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_len >= _size)
	{
		throw std::out_of_range("Not enough space to add element");
	}
	_numbers[_len] = number;
	_len++;
}

int Span::shortestSpan()
{
	if (_len < 2)
	{
		throw std::logic_error("Not enough elements to find a span");
	}

	std::vector<int> vec(_numbers, _numbers + _len);

	std::sort(vec.begin(), vec.end());
	int shortest_span = vec[1] - vec[0];
	for (size_t i = 1; i < vec.size() - 1; i++)
	{
		int span = vec[i + 1] - vec[i];
		if (span < shortest_span)
		{
			shortest_span = span;
		}
	}
	return shortest_span;
}

int Span::longestSpan()
{
	if (_len < 2)
	{
		throw std::logic_error("Not enough elements to find a span");
	}

	int minVal = _numbers[0];
	int maxVal =_numbers[0];

	for (unsigned int i = 0; i < _len; i++)
	{
		if (minVal > _numbers[i])
		{
			minVal = _numbers[i];
		}
		if (maxVal < _numbers[i])
		{
			maxVal = _numbers[i];
		}
	}
	
	return maxVal - minVal;
}

Span::~Span()
{
	delete[] _numbers;
}
