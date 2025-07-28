/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:33:00 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/16 14:27:48 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AForm__H__
#define __AForm__H__

#include <iostream>
#include <string>

class Bureaucrat;	//forward declaration

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);

	AForm& operator=(const AForm& other);

	const std::string& getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	class DoubleSignException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	virtual ~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif  //!__AForm__H__