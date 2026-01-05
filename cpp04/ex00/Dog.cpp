/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:44:04 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 18:44:45 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy){}

Dog::~Dog(void) {}

Dog &Dog::operator=(const Dog &assign)
{
	this->type = assign.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Waf Waf";
}