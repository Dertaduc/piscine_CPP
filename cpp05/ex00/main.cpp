/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:17:36 by candre--          #+#    #+#             */
/*   Updated: 2026/01/14 15:31:08 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{

	std::cout << "__________Try instanciation__________\n";
	std::cout << "\nWith a valid grade (100): \n";
	try 
	{
		Bureaucrat a("test", 100);
		std::cout << a;
		std::cout << "Instanciation bureaucrat graded 100 successfull\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "\nWith a too high grade (0):\n";
	try 
	{
		Bureaucrat a("test", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "\nWith a too small grade (151):\n";
	try 
	{
		Bureaucrat a("test", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	std::cout << "\n\n\n__________Copy tests__________\n";
	Bureaucrat a("Name1", 42);
	Bureaucrat b(a);
	Bureaucrat c;
	std::cout << a;
	std::cout << b;
	std::cout << c;
	c = a;
	std::cout << c;
	
	std::cout << "\n\n\n__________Try to modify grade__________\n";
	try
	{
		Bureaucrat d("Peter", 2);
		std::cout << d;
		d.incrementGrade();
		std::cout << d;
		d.incrementGrade();
		std::cout << d;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat d("Max", 149);
		std::cout << d;
		d.decrementGrade();
		std::cout << d;
		d.decrementGrade();
		std::cout << d;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	// Bureaucrat z("asdasd", -10);
	return (0);
}
