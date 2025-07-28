/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:33 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 14:39:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT__H__
#define __CAT__H__

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain* _brain;
public:
	Cat();
	Cat(const Cat& other);

	Cat& operator=(const Cat& other);

	virtual void makeSound() const;
	std::string getIdea(int index) const;
	void setIdea(int index, const std::string& idea);

	~Cat();
};

#endif  //!__CAT__H__