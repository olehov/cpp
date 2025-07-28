/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:12:11 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 11:12:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM__H__
#define __PRESIDENTIALPARDONFORM__H__

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& name);
	PresidentialPardonForm(const PresidentialPardonForm& other);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void execute(const Bureaucrat& executor) const;

	~PresidentialPardonForm();
};

#endif  //!__PRESIDENTIALPARDONFORM__H__