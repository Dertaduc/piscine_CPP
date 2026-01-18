/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:34:46 by candre--          #+#    #+#             */
/*   Updated: 2026/01/14 15:34:47 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Standard form name"), _signed(false), _grade_sign(100), _grade_exec(100) {}

Form::Form(const std::string name, const unsigned int grade_sign, const int grade_exec) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &to_copy) : _name(to_copy._name), _signed(to_copy._signed), _grade_sign(to_copy._grade_sign), _grade_exec(to_copy._grade_exec) {}

Form::~Form(void){}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

const std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSignedStatus(void) const
{
	return (_signed);
}

unsigned int Form::getGradeSign(void) const
{
	return (_grade_sign);
}

int Form::getGradeExec(void) const
{
	return (_grade_exec);
}

void Form::beSigned(const Bureaucrat &employee)
{
	if (employee.getGrade() <= _grade_sign)
		_signed = true;
	else
	 	throw Form::GradeTooLowException();
}



std::ostream &operator<<(std::ostream &ofs, Form const &to_print)
{
	ofs << "__________Form information__________\n";
	ofs << "_name : " << to_print.getName() << std::endl;
	ofs << "_signed status : " << to_print.getSignedStatus() << std::endl;
	ofs << "_grade_sign : " << to_print.getGradeSign() << std::endl;
	ofs << "_grade_exec : " << to_print.getGradeExec() << std::endl;
	ofs << "------------------------------------\n";
	return (ofs);
}
