/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:43:02 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 18:25:59 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Constructor : Animal (default constructor)" << std::endl;
}

Animal::Animal(const Animal &to_copy)
{
	type = to_copy.type;
	std::cout << "Constructor : Animal (copy constructor)" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Destructor : Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &assign)
{
	this->type = assign.type;
	return (*this);
}

void Animal::makeSound(void) const
{}

std::string Animal::getType(void) const
{
	return (type);
}