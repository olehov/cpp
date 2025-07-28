/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:14:45 by ogrativ           #+#    #+#             */
/*   Updated: 2025/07/17 15:31:55 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static const size_t forms_count = 3;
static const size_t bureaucraft_count = 10;

void clearForms(AForm** forms);

void clearBureau(Bureaucrat** bureau);

void printBureau(Bureaucrat** bureau);

void printForms(AForm** forms);

AForm** creationFormsTest();

Bureaucrat **createBureau();

void signFormsTest(AForm** forms, Bureaucrat** bureau);

void executeFormsTest(AForm** forms, Bureaucrat** bureau);

int main()
{
	AForm **forms;
	Bureaucrat **bureau;

	std::srand(std::time(0));
	std::cout << "\n=== Testing Form creation ===\n";
	forms = creationFormsTest();
	std::cout << "\n=== Testing Bureaucraft creations with random valid grades ===\n";
	bureau = createBureau();
	if (forms && bureau)
	{
		std::cout << "\n=== Testing sign forms ===\n";
		signFormsTest(forms, bureau);
		std::cout << "\n=== Testing execute forms ===\n";
		executeFormsTest(forms, bureau);
	}
	clearForms(forms);
	clearBureau(bureau);
	return 0;
}

void clearForms(AForm** forms)
{
	if (forms == NULL)
		return ;
	for (size_t i = 0; i < forms_count; i++)
	{
		delete forms[i];
	}
	delete[] forms;
}

void clearBureau(Bureaucrat** bureau)
{
	if (bureau == NULL)
		return ;
	for (size_t i = 0; i < bureaucraft_count; i++)
	{
		delete bureau[i];
	}
	delete[] bureau;
}

void printBureau(Bureaucrat** bureau)
{
	for (size_t i = 0; i < bureaucraft_count; i++)
	{
		std::cout << *bureau[i] << std::endl << std::endl;
	}
}

void printForms(AForm** forms)
{
	for (size_t i = 0; i < forms_count; i++)
	{
		std::cout << *forms[i] << std::endl << std::endl;
	}
}

AForm** creationFormsTest()
{
	AForm** forms = new AForm*[forms_count];
	for (size_t i = 0; i < forms_count; i++)
	{
		forms[i] = NULL;
	}
	try
	{
		forms[0] = new PresidentialPardonForm("Presidental");
		forms[1] = new RobotomyRequestForm("Bender");
		forms[2] = new ShrubberyCreationForm("garden");
		printForms(forms);
		return (forms);
	}
	catch (const std::exception& e)
	{
		clearForms(forms);
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

Bureaucrat **createBureau()
{
	Bureaucrat **bureau = new Bureaucrat*[bureaucraft_count];

	for (size_t i = 0; i < bureaucraft_count; i++)
	{
		bureau[i] = NULL;
	}
	try
	{
		for (size_t i = 0; i < bureaucraft_count; i++)
		{
			std::string name = "bureaucraft_";
			name.push_back(i + '0');
			int grade = (rand() % 150) + 1;
			bureau[i] = new Bureaucrat(name, grade);
		}
		printBureau(bureau);
		return (bureau);
	}
	catch(const std::exception& e)
	{
		clearBureau(bureau);
		std::cerr << e.what() << '\n';
	}
	return (NULL);
}

void signFormsTest(AForm** forms, Bureaucrat** bureau)
{	
	for (size_t i = 0; i < forms_count; i++)
	{
		bureau[std::rand() % bureaucraft_count]->signForm(*forms[i]);
		std::cout << std::endl;
	}
	printForms(forms);
}

void executeFormsTest(AForm** forms, Bureaucrat** bureau)
{	
	for (size_t i = 0; i < forms_count; i++)
	{
		bureau[std::rand() % bureaucraft_count]->executeForm(*forms[i]);
		std::cout << std::endl;
	}
}
