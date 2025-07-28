/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:22:02 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/16 14:29:24 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM__H__
#define __SHRUBBERYCREATIONFORM__H__

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& name);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	void execute(const Bureaucrat& executor) const;

	~ShrubberyCreationForm();
};

#endif  //!__SHRUBBERYCREATIONFORM__H__