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

WrongAnimal::WrongAnimal(void){}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy)
{
	type = to_copy.type;
}

WrongAnimal::~WrongAnimal(void){}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "ouhhhhhhhhhhhh" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}