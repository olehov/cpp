/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:12:18 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 12:07:04 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("robot", 72, 45)
{
	// std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name): AForm(name, 72, 45)
{
	// std::cout << "[RobotomyRequestForm] Constructor with parameters called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
	// std::cout << "[RobotomyRequestForm] Copy constructor: called for " << other.getName() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		// std::cout << "[RobotomyRequestForm] Copy assignment operator: called for " << other.getName() << std::endl;
	}
	else
	{
		// std::cout << "[RobotomyRequestForm] Copy assignment operator: self-assignment ignored for " << other.getName() << std::endl;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}

	std::srand(std::time(0));
	if (std::rand() % 50)
	{
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		throw RobotomyExecuteException();
	}
}

const char* RobotomyRequestForm::RobotomyExecuteException::what() const throw()
{
	return "faild to execute";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "[RobotomyRequestForm] Destructor called for: " << getName() << std::endl;
}

