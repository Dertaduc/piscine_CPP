/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:17:41 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 18:06:32 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat(void) : _name("default name"), _grade(10) {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : _name(to_copy._name), _grade(to_copy._grade){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &to_assign)
{
	if (this != &to_assign)
	{
		this->_grade = to_assign._grade;
	}
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}
Bureaucrat::~Bureaucrat(void) {}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += 1;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

std::ostream &operator<<(std::ostream &ofs, Bureaucrat const &to_print)
{
	ofs << to_print.getName() << ", bureaucrat grade " << to_print.getGrade() << ".\n";
	return (ofs);
}
