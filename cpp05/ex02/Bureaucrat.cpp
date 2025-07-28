/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:18:41 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 12:10:17 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
	_name = "";
	_grade = 150;
	// std::cout << "[Bureaucrat] Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
	// std::cout << "[Bureaucrat] Constructor with parameters called" << std::endl;
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
	_name = name;
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	_name = other._name;
	_grade = other._grade;
	// std::cout << "[Bureaucrat] Copy constructor: called for " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
		// std::cout << "[Bureaucrat] Copy assignment operator: called for " << _name << std::endl;
	}
	else
	{
		// std::cout << "[Bureaucrat] Copy assignment operator: self-assignment ignored for " << _name << std::endl;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const AForm::DoubleSignException& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because: " << "Grade too low: grade must be: " << form.getGradeToSign() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const AForm::FormNotSignedException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because: " << "Grade too low: grade must be: " << form.getGradeToSign() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high: grade must be >= 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low: grade must be <= 150";
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "[Bureaucrat] Destructor called for: " << _name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
