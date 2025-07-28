/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:09:39 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 11:26:51 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT__H__
#define __BUREAUCRAT__H__

#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat
{
private:
	std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);

	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string& getName() const;
	int getGrade() const;

	// Grade modifiers
	void incrementGrade(); // _grade--
	void decrementGrade(); // _grade++

	void signForm(Form& form);

	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif  //!__BUREAUCRAT__H__