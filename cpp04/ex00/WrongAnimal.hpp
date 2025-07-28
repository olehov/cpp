/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:54:59 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/11 12:08:45 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WrongAnimal__H__
#define __WrongAnimal__H__

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);

	WrongAnimal& operator=(const WrongAnimal& other);

	const std::string& getType() const;

	void makeSound() const;

	~WrongAnimal();
};

#endif  //!__WrongAnimal__H__