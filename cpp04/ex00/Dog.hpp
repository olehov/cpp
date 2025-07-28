/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:33 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/03 15:44:50 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Dog__H__
#define __Dog__H__

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog& other);

	Dog& operator=(const Dog& other);

	virtual void makeSound() const;

	~Dog();
};

#endif  //!__Dog__H__