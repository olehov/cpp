/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:07:33 by ogrativ           #+#    #+#             */
/*   Updated: 2025/05/13 14:11:35 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	replaceAll(std::string line, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos); // part before match
		result += s2;                            // replace
		pos = found + s1.length();               // part after match
	}
	result += line.substr(pos); // everything else
	return (result);
}


int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return (1);
	}

	std::ifstream inFile(filename.c_str());
	if (!inFile)
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return (1);
	}

	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "Error: Cannot create output file." << std::endl;
		inFile.close();
		return (1);
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		outFile << replaceAll(line, s1, s2) << std::endl;
	}

	inFile.close();
	outFile.close();
	return (0);
}
