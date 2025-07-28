/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:21:43 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 15:24:45 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default_shrubbery", 145, 137)
{
	// std::cout << "[ShrubberyCreationForm] Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name): AForm(name + "_shrubbery", 145, 137)
{
	// std::cout << "[ShrubberyCreationForm] Constructor with parameters called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	// std::cout << "[ShrubberyCreationForm] Copy constructor: called for " << other.getName() << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		// std::cout << "[ShrubberyCreationForm] Copy assignment operator: called for " << other.getName() << std::endl;
	}
	else
	{
		// std::cout << "[ShrubberyCreationForm] Copy assignment operator: self-assignment ignored for " << other.getName() << std::endl;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	int	tree;

	if (!isSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	std::ofstream file(getName().c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Failed to create shrubbery file with name: " + getName());
	}
	
	std::srand(std::time(0));
	tree = std::rand() % 3;
	switch (tree)
	{
		case 0:
			file << "              v .   ._, |_  .,\n"
				<< "           `-._\\/  .  \\ /    |/_\n"
				<< "               \\  _\\, y | \\//\n"
				<< "         _\\_.___\\, \\/ -.\\||\n"
				<< "           `7-,--.`._||  / / ,\n"
				<< "           /'     `-. `./ / |/_.'\n"
				<< "                     |    |//\n"
				<< "                     |_    /\n"
				<< "                     |-   |\n"
				<< "                     |   =|\n"
				<< "                     |    |\n"
				<< "--------------------/ ,  . \\--------._\n\n";
			break;
		case 1:
			file << "                                                .\n"
        		<< "                                      .         ;  \n"
        		<< "         .              .              ;%     ;;   \n"
        		<< "           ,           ,                :;%  %;   \n"
        		<< "            :         ;                   :;%;'     ., \n"
        		<< "   ,.        %;     %;            ;        %;'    ,;\n"
        		<< "     ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
        		<< "      %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
        		<< "       ;%;      %;        ;%;        % ;%;  ,%;'\n"
        		<< "        `%;.     ;%;     %;'         `;%%;.%;'\n"
        		<< "         `:;%.    ;%%. %@;        %; ;@%;%'\n"
        		<< "            `:%;.  :;bd%;          %;@%;'\n"
        		<< "              `@%:.  :;%.         ;@@%;' \n"
        		<< "                `@%.  `;@%.      ;@@%;   \n"
        		<< "                  `@%%. `@%%    ;@@%;    \n"
        		<< "                    ;@%. :@%%  %@@%;     \n"
        		<< "                      %@bd%%%bd%%:;     \n"
        		<< "                        #@%%%%%:;;\n"
        		<< "                        %@@%%%::;\n"
        		<< "                        %@@@%(o);  . '\n"
        		<< "                        %@@@o%;:(.,'  \n"
        		<< "                    `.. %@@@o%::;     \n"
        		<< "                       `)@@@o%::;     \n"
        		<< "                        %@@(o)::;     \n"
        		<< "                       .%@@@@%::;     \n"
        		<< "                       ;%@@@@%::;.    \n"
        		<< "                      ;%@@@@%%:;;;. \n"
        		<< "                  ...;%@@@@@%%:;;;;,..\n\n";
			break;
		case 2:
			file << "               ,@@@@@@@,\n"
				<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
				<< "    ,&%&&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
				<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
				<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
				<< "   %&&%/ %&&%&&@@\\ V /@@' `88\\8 `/88'\n"
				<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
				<< "       |o|        | |         | |\n"
				<< "       |.|        | |         | |\n"
				<< "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
			break;
		default:
			file << "    oxoxoo    ooxoo\n"
				<< "  ooxoxo oo  oxoxooo\n"
				<< " oooo xxoxoo ooo ooox\n"
				<< " oxo o oxoxo  xoxxoxo\n"
				<< "  oxo xooxoooo o ooo\n"
				<< "    ooo\\oo\\  /o/o\n"
				<< "        \\  \\/ /\n"
				<< "         |   /\n"
				<< "         |  |\n"
				<< "         | D|\n"
				<< "         |  |\n"
				<< "         |  |\n"
				<< "  ______/____\\____\n\n";
			break;
	}
	file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "[ShrubberyCreationForm] Destructor called for: " << getName() << std::endl;
}
