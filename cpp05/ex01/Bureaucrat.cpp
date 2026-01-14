/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:17:41 by candre--          #+#    #+#             */
/*   Updated: 2026/01/14 13:44:19 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default name"), _grade(10)
{
	std::cout << "Constructor : Bureaucrat (default constructor)" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Constructor : Bureaucrat (standard constructor)" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : _name(to_copy._name), _grade(to_copy._grade)
{
	std::cout << "Constructor : Bureaucrat (copy constructor)" << std::endl;
}

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
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor : Bureaucrat" << std::endl;
}

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

std::ostream &operator<<(std::ostream &ofs, Bureaucrat const &to_print)
{
	ofs << to_print.getName() << ", bureaucrat grade " << to_print.getGrade() << ".\n";
	return (ofs);
}
