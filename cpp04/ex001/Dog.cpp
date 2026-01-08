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
	brain = new Brain();
	std::cout << "Constructor : Dog (default constructor)" << std::endl;
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
	std::cout << "Constructor : Dog (copy constructor)" << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Destructor : Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &assign)
{
	this->type = assign.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Waf Waf";
}

void Dog::getAllIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		std::cout << brain->getIdea(i) << std::endl;
}