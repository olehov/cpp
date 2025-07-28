/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:58:06 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/23 15:21:45 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);

	ScalarConverter& operator=(const ScalarConverter& other);

	static char toChar(int val);

	static int toInt(const std::string& val);
	static int toInt(char val);
	static int toInt(double val);
	static int toInt(float val);

	static float toFloat(const std::string& val);
	static float toFloat(int val);
	static float toFloat(double val);

	static double toDouble(const std::string& val);
	static double toDouble(int val);
	static double toDouble(float val);

	class TypeOverflowException: public std::exception
	{
	private:
		std::string _message;
	public:
		TypeOverflowException(): _message("Type overflow occurred") {};
		TypeOverflowException(const std::string& message): _message(message) {};

		const char* what() const throw()
		{
			return _message.c_str();
		}

		~TypeOverflowException() throw() {};
	};

	~ScalarConverter();
public:
	static void convert(const std::string& literal);

};

#endif