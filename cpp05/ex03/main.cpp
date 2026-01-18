/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:17:36 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 20:36:55 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <new>

int main(void)
{
	srand(static_cast<unsigned int>(std::time(NULL)));
	Bureaucrat Boss("Boss", 1);
	Intern nobody;
	AForm *test = NULL;

	std::cout << "\n__________Intern do a Presidential Pardon Form_________" << std::endl;
	try 
	{
		test = nobody.makeForm("PresidentialPardonForm","BobyThePrisonner");
		if (test != NULL)
		{
			Boss.signForm(*test);
			delete test;
		}
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what();
	}

	std::cout << "\n__________Intern do a Form Shrubbery Creation Form_________" << std::endl;
	try 
	{
		test = nobody.makeForm("ShrubberyCreationForm","garden");
		if (test != NULL)
		{
			Boss.signForm(*test);
			delete test;
		}
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what();
	}
	
	std::cout << "\n__________Intern do a Form Robotomy Request Form_________" << std::endl;
	try 
	{
		test = nobody.makeForm("RobotomyRequestForm","Wall-e");
		if (test != NULL)
		{
			Boss.signForm(*test);
			delete test;
		}
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what();
	}

	std::cout << "\n__________Intern try to do a non existent form_________" << std::endl;
	try 
	{
	test = nobody.makeForm("not_exist_form","nothing");
		if (test != NULL)
		{
			Boss.signForm(*test);
			Boss.executeForm(*test);
			delete test;
		}
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what();
	}
}
