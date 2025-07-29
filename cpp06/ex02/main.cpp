/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:13:37 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/29 11:36:08 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int	a = rand() % 3;

	switch (a)
	{
	case 0:
		std::cout << "generated: A" << std::endl;
		return new A();
	case 1:
		std::cout << "generated: B" << std::endl;
		return new B();
	case 2:
		std::cout << "generated: C" << std::endl;
		return new C();
	default:
		break;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}

int main()
{
	srand(static_cast<unsigned int>(std::time(0)));

	for (int i = 0; i < 10; ++i)
	{
		Base* obj = generate();
		std::cout << "Pointer: ";
		identify(obj);
		std::cout << "Reference: ";
		identify(*obj);
		delete obj;
		std::cout << "------------" << std::endl;
	}

	return 0;
}