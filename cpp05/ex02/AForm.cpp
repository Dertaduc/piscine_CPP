/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:13:13 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 18:13:16 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Standard AForm name"), _signed(false), _grade_sign(100), _grade_exec(100) {}

AForm::AForm(const std::string name, const int grade_sign, const int grade_exec) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw AForm::GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &to_copy) : _name(to_copy._name), _signed(to_copy._signed), _grade_sign(to_copy._grade_sign), _grade_exec(to_copy._grade_exec) {}

AForm::~AForm(void){}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::UnsignedDocumentException::what() const throw()
{
	return ("Unsigned document");
}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSignedStatus(void) const
{
	return (_signed);
}

int AForm::getGradeSign(void) const
{
	return (_grade_sign);
}

int AForm::getGradeExec(void) const
{
	return (_grade_exec);
}

void AForm::beSigned(const Bureaucrat &employee)
{
	if (employee.getGrade() <= _grade_sign)
		_signed = true;
	else
	 	throw AForm::GradeTooLowException();
}



std::ostream &operator<<(std::ostream &ofs, AForm const &to_print)
{
	ofs << "__________AForm information__________\n";
	ofs << "_name : " << to_print.getName() << std::endl;
	ofs << "_signed status : " << to_print.getSignedStatus() << std::endl;
	ofs << "_grade_sign : " << to_print.getGradeSign() << std::endl;
	ofs << "_grade_exec : " << to_print.getGradeExec() << std::endl;
	ofs << "------------------------------------\n";
	return (ofs);
}
