/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:26:30 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 16:44:58 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
	// std::cout << "[Intern] Default constructor called" << std::endl;

}

Intern::Intern(const Intern& other)
{
	(void)other;
	// std::cout << "[Intern] Constructor with parameters called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		// std::cout << "[Intern] Copy assignment operator: called"<< std::endl;
	}
	else
	{
		// std::cout << "[Intern] Copy assignment operator: self-assignment ignored" << std::endl;
	}
	return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	typedef AForm* (*FormCreator)(const std::string&);

	struct FormMap
	{
		std::string name;
		FormCreator create;
	};

	static const FormMap formTable[] = {
		{ "shrubbery creation", &createShrubbery },
		{ "robotomy request", &createRobotomy },
		{ "presidential pardon", &createPresidential }
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (formTable[i].name == name)
		{
			return formTable[i].create(target);
		}
	}
	throw FormCreateException("Form: " + name + " doesn't exist");
}

Intern::FormCreateException::FormCreateException(const std::string& message)
{
	_message = message;
}

const char* Intern::FormCreateException::what() const throw()
{
	return _message.c_str();
}

Intern::FormCreateException::~FormCreateException() throw() {}

Intern::~Intern()
{
	// std::cout << "[Intern] Destructor called for: " << getName() << std::endl;
}
