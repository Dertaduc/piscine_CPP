/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:55:39 by candre--          #+#    #+#             */
/*   Updated: 2025/12/16 20:06:17 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a(10.0f); 
	Fixed b(42.42f);

	const Fixed const_a(10); 
	const Fixed const_b(42.42f);

	std::cout << "Initial value for a : " << a << std::endl;
	std::cout << "Initial value for b : " << b << std::endl;
	std::cout << "Initial value for const_a : " << const_a << std::endl;
	std::cout << "Initial value for const_b : " << const_b << std::endl;
	


	std::cout << "\n\nCOMPARISON OPERATOR TEST\n";
	std:: cout << "> : ";
	if (a > b)
		std::cout << "a is bigger than b\n";
	else
		std::cout << "b is bigger than a\n";
	std:: cout << "< : ";
	if (a < b)
		std::cout << "b is bigger than a\n";
	else
		std::cout << "a is bigger than b\n";
	std:: cout << "<= : ";
	if (a <= b)
		std::cout << "b is bigger or equal than a\n";
	else
		std::cout << "a is bigger or equal than b\n";
	std:: cout << ">= : ";
	if (a >= b)
		std::cout << "a is bigger or equal than b\n";
	else
		std::cout << "b is bigger or equal than a\n";
	
	std:: cout << "== : ";
	if (a == b)
		std::cout << "a is EQUAL than b\n";
	else
		std::cout << "a is DIFFERENT than b\n";
	std:: cout << "!= : ";
	if (a != b)
		std::cout << "a is DIFFERENT than b\n";
	else
		std::cout << "a is EQUAL than b\n";



	std::cout << "\n\nARITHMETIC OPERATOR TEST\n";
	std::cout << "Initial value for a : " << a << std::endl;
	std::cout << "a + 10.21f : " << a + 10.21f << std::endl;
	std::cout << "a - 5 : " << a - 5 << std::endl;
	std::cout << "a * 2 : " << a * 2 << std::endl;
	std::cout << "a / 3 : " << a / 3 << std::endl;
	
	std::cout << "\n\nINCREMENT OPERATOR TEST\n";
	std::cout << "Initial value for a : " << a.toFloat() << std::endl;
	std::cout << "Previous a : " << a << " and ++a : " << ++a << std::endl;
	std::cout << "Previous a : " << a << " and a++ : " << a++ << " final a : " << a << std::endl;
	std::cout << "Previous a : " << a << " and --a : " << --a << std::endl;
	std::cout << "Previous a : " << a << " and a-- : " << a-- << " final a : " << a << std::endl;

	std::cout << "\n\nMEMBER FUNCTION MIN MAX TEST\n";
	std::cout << "Min between a=" << a << " and b=" << b << " is : " << Fixed::min(a, b) << std::endl;
	std::cout << "Min between const_a=" << const_a << " and const_b=" << const_b << " is : " << Fixed::min(a, b) << std::endl;
	std::cout << "Max between a=" << a << " and b=" << b << " is : " << Fixed::max(a, b) << std::endl;
	std::cout << "Max between const_a=" << const_a << " and const_b=" << const_b << " is : " << Fixed::max(a, b) << std::endl;
}