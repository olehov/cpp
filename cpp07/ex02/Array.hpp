/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:39:19 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/30 13:53:42 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T	*_arr;
	size_t _size;
public:
	Array()
	{
		_arr = NULL;
		_size = 0;
	}

	Array(size_t size)
	{
		_arr = new T[size];
		_size = size;
	}
	
	Array(const Array& other)
	{
		_arr = new T[other._size];
		_size = other._size;

		for (size_t i = 0; i < _size; i++)
		{
			_arr[i] = other._arr[i];
		}
	}
	
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] _arr;
			_arr = new T[other._size];
			_size = other._size;

			for (size_t i = 0; i < _size; i++)
			{
				_arr[i] = other._arr[i];
			}
		}
		return *this;		
	}
	
	size_t size() const
	{
		return _size;
	}

	// Subscript operator (read/write)
    T& operator[](size_t index)
	{
		if (index >= _size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return _arr[index];
	}

	// Subscript operator (read-only)
    const T& operator[](size_t index) const
	{
		if (index >= _size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return _arr[index];
	}

	~Array()
	{
		if (_arr != NULL)
		{
			delete[] _arr;
		}
	}
};

#endif  //!ARRAY_HPP