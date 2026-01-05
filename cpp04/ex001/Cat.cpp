/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:01:57 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 18:26:15 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
	std::cout << "Constructor : Cat (default constructor)" << std::endl;
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
	std::cout << "Constructor : Cat (copy constructor)" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Destructor : Cat" << std::endl;
}
Cat &Cat::operator=(const Cat &assign)
{
	this->type = assign.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "MIAOU";
}