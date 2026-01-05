/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:50:56 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 20:10:24 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat(); 
	const WrongAnimal *w = new WrongAnimal();

	std::cout << j->getType() << " ";
	j->makeSound();
	std::cout  << std::endl;
	std::cout << i->getType() << " ";
	i->makeSound();
	std::cout  << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	std::cout << w->getType() << " ";
	w->makeSound();
	std::cout  << std::endl;

	delete (meta);
	delete (j);
	delete (i);
	delete (w);
}