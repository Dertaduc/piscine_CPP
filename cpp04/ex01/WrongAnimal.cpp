/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:20:13 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 20:05:22 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Constructor : WrongAnimal (default constructor)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy)
{
	type = to_copy.type;
	std::cout << "Constructor : WrongAnimal (copy constructor)" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor : WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Default sound from wrong animal class";
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}