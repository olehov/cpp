/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:12:32 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/16 16:51:45 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM__H__
#define __ROBOTOMYREQUESTFORM__H__

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& name);
	RobotomyRequestForm(const RobotomyRequestForm& other);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void execute(Bureaucrat const & executor) const;

	class RobotomyExecuteException: public std::exception
	{
		const char* what() const throw();
	};

	~RobotomyRequestForm();
};

#endif  //!__ROBOTOMYREQUESTFORM__H__