/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:33 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/03 15:47:48 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT__H__
#define __CAT__H__

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& other);

	Cat& operator=(const Cat& other);

	virtual void makeSound() const;

	~Cat();
};

#endif  //!__CAT__H__