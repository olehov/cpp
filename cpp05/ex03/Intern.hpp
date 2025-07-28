/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:26:47 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 16:42:10 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN__H__
#define __INTERN__H__

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
private:
	static AForm* createShrubbery(const std::string& target);
	static AForm* createRobotomy(const std::string& target);
	static AForm* createPresidential(const std::string& target);
public:
	Intern();
	Intern(const Intern& other);

	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& name, const std::string& target);

	class FormCreateException :public std::exception
	{
		private:
			std::string _message;
		public:
			FormCreateException(const std::string& message);
			const char* what() const throw();
			~FormCreateException() throw();
	};
	

	~Intern();
};

#endif  //!__INTERN__H__