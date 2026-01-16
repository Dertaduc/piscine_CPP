/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:17:36 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 18:08:12 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

int main(void)
{
	std::cout << "_______Try to create some form_______" <<std::endl;
	std::cout << "\nWith a valid grade (100): \n";
	try
	{
		AForm a("test", 100, 100);
		std::cout << "Instanciation form graded 100 and 100 successfull\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "\nWith a too high grade (0): \n";
	try
	{
		AForm a("test", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
		std::cout << "\nWith a too small grade (151):\n";
	try 
	{
		AForm a("test", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	std::cout << "\n\n__________Try to sign forms_________\n";
	
	Bureaucrat a("employe1", 1);
	Bureaucrat b("employe42", 42);
	Bureaucrat c("employe150", 150);
	AForm 	d("form1", 1, 110);
	AForm 	e("form42", 42, 42);
	AForm 	f("form150", 150, 110);

	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	
	std::cout << "\n---abilities to employe1 to sign---\n";
	a.signForm(d);
	a.signForm(e);
	a.signForm(f);
	std::cout <<"------------------------------------\n";

	std::cout << "\n---abilities to employe42 to sign---\n";
	b.signForm(d);
	b.signForm(e);
	b.signForm(f);
	std::cout <<"------------------------------------\n";

	std::cout << "\n---abilities to employe150 to sign---\n";
	c.signForm(d);
	c.signForm(e);
	c.signForm(f);
	std::cout <<"------------------------------------\n";
	return (0);
}
