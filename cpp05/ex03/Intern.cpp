/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:07:05 by candre--          #+#    #+#             */
/*   Updated: 2026/01/18 11:02:23 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void){}
Intern::~Intern(void){}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    int switch_int;

    std::string(compare_tab[3]) = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    
    switch_int = -1;
    for (int i = 0; i < 3; i++)
    {
        if (formName == compare_tab[i])
        {
            switch_int = i;
            std::cout << "Intern creates " << compare_tab[i] << " : " << target << std::endl;
            break;
        }
    }
    switch (switch_int){
        case (0) : return (new ShrubberyCreationForm(target));
        case (1) : return (new RobotomyRequestForm(target));
        case (2) : return (new PresidentialPardonForm(target));
    }
    std::cout << "The intern is unable to do his job properly....." << std::endl;
    std::cout << "He cannot creat form : " << formName << std::endl;
    std::cout << "Supported format are only : ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm\n";
    return NULL;
}

