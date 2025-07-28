/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:56:30 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/07 12:27:17 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	megaphone(char* str)
{
	if (str == NULL)
	{
		return;
	}
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		std::cout << (char)toupper((unsigned char)str[i]);
	}
}

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			megaphone(argv[i]);
		}
		std::cout << std::endl;
	}
	return (0);
}
