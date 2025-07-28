/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:32:46 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 12:17:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _gradeToSign(1), _gradeToExecute(1)
{
	_isSigned = false;
	// std::cout << "[AForm] Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "[AForm] Constructor with parameters called" << std::endl;
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

AForm::AForm(const AForm& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	_isSigned = other._isSigned;
	std::cout << "[AForm] Copy constructor: called for " << _name << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		std::cout << "[AForm] Copy assignment operator: called for " << _name << std::endl;
	}
	else
	{
		// std::cout << "[AForm] Copy assignment operator: self-assignment ignored for " << _name << std::endl;
	}
	return *this;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high: grade must be >= 1";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low: grade must be <= 150";
}

const char* AForm::DoubleSignException::what() const throw()
{
	return "form already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "form not signed";
}

AForm::~AForm()
{
	// std::cout << "[AForm] Destructor called for: " << _name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	std::string status = f.isSigned() ? "signed" : "unsigned";
	os << "Form: " << f.getName() << "\n\tsign status: " << status << "\n\tmin grade to sign: " << f.getGradeToSign() << "\n\tmin grade to execute: " << f.getGradeToExecute();
	return os;
}
