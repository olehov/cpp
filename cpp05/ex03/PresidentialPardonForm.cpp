/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:11:50 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 15:34:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("presidental_default", 25, 5)
{
	// std::cout << "[PresidentialPardonForm] Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name): AForm(name, 25, 5)
{
	// std::cout << "[PresidentialPardonForm] Constructor with parameters called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
	// std::cout << "[PresidentialPardonForm] Copy constructor: called for " << other.getName() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		// std::cout << "[PresidentialPardonForm] Copy assignment operator: called for " << other.getName() << std::endl;
	}
	else
	{
		// std::cout << "[PresidentialPardonForm] Copy assignment operator: self-assignment ignored for " << other.getName() << std::endl;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "[PresidentialPardonForm] Destructor called for: " << getName() << std::endl;
}
