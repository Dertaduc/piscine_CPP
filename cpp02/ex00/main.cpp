/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:55:39 by candre--          #+#    #+#             */
/*   Updated: 2025/12/15 19:24:48 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	std::cout << "Test :\n";
	std::cout << "instance a : " << a.getRawBits() << std::endl;
	std::cout << "instance b : "<< b.getRawBits() << std::endl;
	std::cout << "instance c : "<< c.getRawBits() << std::endl;

	c.setRawBits(42);
	std::cout << "Test :\n";
	std::cout << "instance a : " << a.getRawBits() << std::endl;
	std::cout << "instance b : "<< b.getRawBits() << std::endl;
	std::cout << "instance c : "<< c.getRawBits() << std::endl;

	b = c;
	std::cout << "Test :\n";
	std::cout << "instance a : " << a.getRawBits() << std::endl;
	std::cout << "instance b : "<< b.getRawBits() << std::endl;
	std::cout << "instance c : "<< c.getRawBits() << std::endl;

	a.setRawBits(21);
	std::cout << "Test :\n";
	std::cout << "instance a : " << a.getRawBits() << std::endl;
	std::cout << "instance b : "<< b.getRawBits() << std::endl;
	std::cout << "instance c : "<< c.getRawBits() << std::endl;	
}