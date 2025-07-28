/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:54:59 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 12:07:01 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL__H__
#define __ANIMAL__H__

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& other);

	Animal& operator=(const Animal& other);

	const std::string& getType() const;

	virtual void makeSound() const;

	virtual ~Animal();
};

#endif  //!__ANIMAL__H__