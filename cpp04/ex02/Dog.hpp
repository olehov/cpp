/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:33 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/07 14:41:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Dog__H__
#define __Dog__H__

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog& other);

	Dog& operator=(const Dog& other);

	virtual void makeSound() const;
	std::string getIdea(int index) const;
	void setIdea(int index, const std::string& idea);

	~Dog();
};

#endif  //!__Dog__H__