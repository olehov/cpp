/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:32:46 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 12:17:19 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _gradeToSign(1), _gradeToExecute(1)
{
	_isSigned = false;
	// std::cout << "[Form] Default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "[Form] Constructor with parameters called" << std::endl;
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw GradeTooLowException();
	}
	else if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw GradeTooHighException();
	}
	_isSigned = false;
}

Form::Form(const Form& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	_isSigned = other._isSigned;
	// std::cout << "[Form] Copy constructor: called for " << _name << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		// std::cout << "[Form] Copy assignment operator: called for " << _name << std::endl;
	}
	else
	{
		// std::cout << "[Form] Copy assignment operator: self-assignment ignored for " << _name << std::endl;
	}
	return *this;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (_isSigned)
	{
		throw DoubleSignException();
	}
	if (b.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high: grade must be >= 1";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low: grade must be <= 150";
}

const char* Form::DoubleSignException::what() const throw()
{
	return "Form already signed";
}

Form::~Form()
{
	// std::cout << "[Form] Destructor called for: " << _name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	std::string status = f.isSigned() ? "signed" : "unsigned";
	os << "Form: " << f.getName() << "\n\tsign status: " << status << "\n\tmin grade to sign: " << f.getGradeToSign() << "\n\tmin grade to execute: " << f.getGradeToExecute();
	return os;
}
