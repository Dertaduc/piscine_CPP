/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:06:51 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 20:07:09 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &to_copy) : WrongAnimal(to_copy){}

WrongCat::~WrongCat(void) {}

WrongCat &WrongCat::operator=(const WrongCat &assign)
{
	this->type = assign.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "MIAOU";
}