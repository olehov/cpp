/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:41:12 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 16:43:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
		<< "I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	
}

void Harl::complain(std::string level)
{
	int	i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while(i < 4)
	{
		if (!level.compare(levels[i]))
		{
			break;
		}
		i++;
	}
	switch (i)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
		std::cout << std::endl << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl << "[ ERROR ]" << std::endl;
		error();
		break;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl << "[ ERROR ]" << std::endl;
		error();
		break;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl << "[ ERROR ]" << std::endl;
		error();
		break;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

Harl::~Harl()
{
	
}
