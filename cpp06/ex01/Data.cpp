/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:56:58 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/28 15:58:55 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void printData(const Data& data)
{
	std::cout << "Name: " << data.name << std::endl
				<< "phone: " << data.phone << std::endl
				<< "age: " << data.age << std::endl;
}
