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

int main(void)
{
	srand(static_cast<unsigned int>(std::time(NULL)));
	Bureaucrat Boss("Boss", 1);
	Bureaucrat Manager("Manager", 45);
	Bureaucrat UnderServant("UnderServant", 150);

	ShrubberyCreationForm tree("forest");
	RobotomyRequestForm robot("Rob");
	PresidentialPardonForm prisonner("Boby");

	std::cout << "__________FORMS INFORMATIONS__________" << std::endl;
	std::cout << tree;
	std::cout << robot;
	std::cout << prisonner;

	std::cout << "\n__________try to exec form without signed__________" << std::endl;
	Boss.executeForm(tree);
	Boss.executeForm(robot);
	Boss.executeForm(prisonner);
	
	Manager.executeForm(tree);
	Manager.executeForm(robot);
	Manager.executeForm(prisonner);

	UnderServant.executeForm(tree);
	UnderServant.executeForm(robot);
	UnderServant.executeForm(prisonner);

	std::cout << "\n__________Try to Sign all forms__________" << std::endl;
	Boss.signForm(tree);
	Boss.signForm(robot);
	Boss.signForm(prisonner);

	Manager.signForm(tree);
	Manager.signForm(robot);
	Manager.signForm(prisonner);
	
	UnderServant.signForm(tree);
	UnderServant.signForm(robot);
	UnderServant.signForm(prisonner);
	
	std::cout << "\n___________Try to exec all forms__________" << std::endl;
	Boss.executeForm(tree);
	Boss.executeForm(robot);
	Boss.executeForm(prisonner);
	
	Manager.executeForm(tree);
	Manager.executeForm(robot);
	Manager.executeForm(prisonner);

	UnderServant.executeForm(tree);
	UnderServant.executeForm(robot);
	UnderServant.executeForm(prisonner);
}
