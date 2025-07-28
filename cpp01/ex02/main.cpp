/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:57:57 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 11:59:07 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	/*print addresses*/
	std::cout << "Address of str:       " << &str << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in stringREF: " << &stringREF << std::endl;

	/*print values*/
	std::cout << "Value of str:         " << str << std::endl;
	std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
	std::cout << "Value via REF:        " << stringREF << std::endl;

	return (0);
}
