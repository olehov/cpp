/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:46:12 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/23 17:19:53 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <limits>

static bool isInt(const std::string& s)
{
	char	*end = NULL;
	errno = 0;
	long	value = std::strtol(s.c_str(), &end, 10);

	return *end == '\0' && errno == 0 && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string& s)
{
	char	*end;
	errno = 0;
	if (s == "-inff" || s == "+inff" || s == "nanf")
	{
		return true;
	}

	std::strtof(s.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0' && errno == 0);
}

static bool isDouble(const std::string& s)
{
	char* end;
	errno = 0;
	if (s == "-inf" || s == "+inf" || s == "nan")
	{
		return true;
	}

	std::strtod(s.c_str(), &end);
	return *end == '\0' && errno == 0;
}

ScalarConverter::ScalarConverter()
{
	// constructor
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	// copy constructor
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other) {
		// copy assignment
	}
	return *this;
}

char ScalarConverter::toChar(int val)
{
	if (val >= std::numeric_limits<char>::min() && val <= std::numeric_limits<char>::max())
	{
		return static_cast<char>(val);
	}
	throw TypeOverflowException("Char overflow occurred");
}

int ScalarConverter::toInt(const std::string &val)
{
	if (isInt(val))
	{
		char	*end;
		return static_cast<int>(std::strtol(val.c_str(), &end, 10));
	}
	throw std::invalid_argument("Invalid or unsupported Integer literal");
}

int ScalarConverter::toInt(char val)
{
	return static_cast<int>(val);
}

int ScalarConverter::toInt(double val)
{
	if (std::isnan(val))
	{
		throw TypeOverflowException("Cannot convert from NaN to int");
	}
	if (std::isinf(val))
	{
		throw TypeOverflowException("Cannot convert from infinity to int");
	}
	if (val >= static_cast<double>(std::numeric_limits<int>::min())
		&& val <= static_cast<double>(std::numeric_limits<int>::max()))
	{
		return static_cast<int>(val);
	}
	throw TypeOverflowException("Integer overflow occurred");
}

int ScalarConverter::toInt(float val)
{
	if (std::isnan(val))
	{
		throw TypeOverflowException("Cannot convert from NaN to int");
	}
	if (std::isinf(val))
	{
		throw TypeOverflowException("Cannot convert from infinity to int");
	}
		if (val >= static_cast<float>(std::numeric_limits<int>::min())
		&& val <= static_cast<float>(std::numeric_limits<int>::max()))
	{
		return static_cast<int>(val);
	}
	throw TypeOverflowException("Integer overflow occurred");
}

float ScalarConverter::toFloat(const std::string &val)
{
	if (isFloat(val))
	{
		char	*end;
		return std::strtof(val.c_str(), &end);
	}
	throw std::invalid_argument("Invalid or unsupported Float literal");
}

float ScalarConverter::toFloat(int val)
{
	return static_cast<float>(val);
}

float ScalarConverter::toFloat(double val)
{
	if (std::isnan(val) || std::isinf(val))
		return static_cast<float>(val);
	if (val >= -static_cast<double>(std::numeric_limits<float>::max())
		&& val <= static_cast<double>(std::numeric_limits<float>::max()))
	{
		return static_cast<float>(val);
	}
	throw TypeOverflowException("Float overflow occurred");
}

double ScalarConverter::toDouble(const std::string &val)
{
	char	*end;
	if (isDouble(val))
	{
		char	*end;
		return std::strtod(val.c_str(), &end);
	}
	throw std::invalid_argument("Invalid or unsupported Double literal");
}

double ScalarConverter::toDouble(int val)
{
	return static_cast<double>(val);
}

double ScalarConverter::toDouble(float val)
{
	return static_cast<double>(val);
}

static bool isCharLiteral(const std::string& s)
{
	size_t sLen = s.length();
	if (sLen == 3 && s[0] == '\'' && s[2] == '\'')
	{
		return true;
	}
	if (sLen == 4 && s[0] == '\'' && s[1] == '\\' && s[3] == '\''
		&& (s[2] == 'a' || s[2] == 'b' || s[2] == 'f' || s[2] == 'n' || s[2] == 'r' || s[2] == 't'
			|| s[2] == 'v' || s[2] == '?' || s[2] == '\\' || (s[2] >= '0' && s[2] <= '7')))
	{
		return true;
	}
	return false;
}

static char parseCharLiteral(const std::string& s)
{
	const size_t literalsCount = 11;
	const char escapes[] = { 'n', 't', 'r', 'b', 'f', 'v', 'a', '\\', '\'', '"', '?' };
	const char values[]  = { '\n','\t','\r','\b','\f','\v','\a','\\', '\'', '\"','\?' };
	if (s.length() == 3)
	{
		return s[1];
	}
	for (size_t i = 0; i < literalsCount; i++)
	{
		if (s[2] == escapes[i])
		{
			return values[i];
		}
	}
	throw std::invalid_argument("Invalid or unsupported Character literal");
}

void ScalarConverter::convert(const std::string &literal)
{
	char	cVal;
	int		iVal;
	float	fVal;
	double	dVal;
	bool	is_char = true, is_int = true, is_float = true, is_double = true;

	if (isCharLiteral(literal))
	{
		cVal = parseCharLiteral(literal);
		iVal = toInt(cVal);
		fVal = toFloat(iVal);
		dVal = toDouble(iVal);
	}
	else if (isInt(literal))
	{
		iVal = toInt(literal);
		try
		{
			cVal = toChar(iVal);
		}
		catch(const std::exception& e)
		{
			is_char = false;
		}
		fVal = toFloat(iVal);
		dVal = toDouble(iVal);
	}
	else if (isFloat(literal))
	{
		fVal = toFloat(literal);
		try
		{
			iVal = toInt(fVal);
		}
		catch(const std::exception& e)
		{
			iVal = std::numeric_limits<int>::max();
			is_int = false;
		}
		try
		{
			cVal = toChar(iVal);
		}
		catch(const std::exception& e)
		{
			is_char = false;
		}
		dVal = toDouble(fVal);
	}
	else if (isDouble(literal))
	{
		dVal = toDouble(literal);
		try
		{
			iVal = toInt(dVal);
		}
		catch(const std::exception& e)
		{
			iVal = std::numeric_limits<int>::max();
			is_int = false;
		}
		try
		{
			cVal = toChar(iVal);
		}
		catch(const std::exception& e)
		{
			is_char = false;
		}
		try
		{
			fVal = toFloat(dVal);
		}
		catch(const std::exception& e)
		{
			is_float = false;
		}
	}
	else
	{
		std::cerr << "Incorrect literal format" << std::endl;
		return ;
	}
}

ScalarConverter::~ScalarConverter()
{
	// destructor
}
