/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:28:59 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 20:35:36 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm(target,
		72,
		45) {}

RobotomyRequestForm::~RobotomyRequestForm(void){}

const char *RobotomyRequestForm::UnsignedDocumentException::what() const throw()
{
	return ("Unsigned document");
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    int random;

	if (this->getSignedStatus() == false)
        throw RobotomyRequestForm::UnsignedDocumentException();
    if (executor.getGrade() > this->getGradeExec())
        throw RobotomyRequestForm::GradeTooLowException();
    else
    {
    	random = rand() % 2;
        switch (random)
        {
            case 0 :
                printAsciiArt();
                std::cout << getName() << " : has been robotomized. Drilling in progress...\n";
             break;
        case 1 :
            std::cout << getName() << " : robotics failed. Please try again.\n";
    }
    }
}

void RobotomyRequestForm::printAsciiArt(void) const
{
    std::cout << "               _________" << std::endl;
    std::cout << "              /~~~~~~~~~\\" << std::endl;
    std::cout << "             (===========) ______________" << std::endl;
    std::cout << "             |  ||  ||   ||~~~~~~~~~~~~~~|" << std::endl;
    std::cout << "             |  ||  ||   ||        (@)   |" << std::endl;
    std::cout << "             |  ||  ||   ||        //    |" << std::endl;
    std::cout << "             |  ||  ||   ||       //     |" << std::endl;
    std::cout << "             |  ||  ||   ||(@)===(o)     |" << std::endl;
    std::cout << "             |  ||  ||   ||        \\\\    |" << std::endl;
    std::cout << "             |           ||         \\\\   |" << std::endl;
    std::cout << "             |~~~~~~~~~~~||         (@)  |" << std::endl;
    std::cout << "             |___________||              |" << std::endl;
    std::cout << "             (___________)|              |" << std::endl;
    std::cout << "              (_________) |    @--(o)    |" << std::endl;
    std::cout << "                |     |   (              (" << std::endl;
    std::cout << "                |     |    \\\\      (o)     \\\\" << std::endl;
    std::cout << "                |     |     \\\\     /        \\\\" << std::endl;
    std::cout << "                |     |      \\\\   @          \\\\" << std::endl;
    std::cout << "                |_____|       \\\\              \\\\" << std::endl;
    std::cout << "                |_____|        \\\\              \\\\" << std::endl;
    std::cout << "                \\_____/         \\\\              \\\\" << std::endl;
    std::cout << "                  |/|            \\\\              \\\\" << std::endl;
    std::cout << "               )  |/|             \\\\              \\\\" << std::endl;
    std::cout << "              (  ,|/|  / '         \\\\              \\\\" << std::endl;
    std::cout << "               )  |/| ( '           \\\\              \\\\" << std::endl;
    std::cout << "         _____  ) |/|' )         _   \\\\              \\\\" << std::endl;
    std::cout << "   |    |     |___|/|___________| |   \\\\              \\\\" << std::endl;
    std::cout << "   |====|     |_________________| |    \\\\              \\\\" << std::endl;
    std::cout << "  =|   _|      |_______________|  |     \\\\              \\\\" << std::endl;
    std::cout << "      |                           |      \\\\              \\\\" << std::endl;
    std::cout << " _____|___________________________|_______)______________)" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|                                                        |" << std::endl;
    std::cout << "|________________________________________________________|" << std::endl;
}