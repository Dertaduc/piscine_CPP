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
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat(); 
	const WrongAnimal *w = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();

	std::cout << "Type : " << j->getType() << " (associate sound : ";
	j->makeSound();
	std::cout  << ")" <<std::endl;

	std::cout << "Type : " << i->getType() << " (associate sound : ";
	i->makeSound();
	std::cout  << ")" <<std::endl;

	std::cout << "Type : " << meta->getType() << " (associate sound : ";
	meta->makeSound();
	std::cout  << ")" <<std::endl;

	std::cout << "Type : " << w->getType() << " (associate sound : ";
	w->makeSound();
	std::cout  << ")" <<std::endl;

	std::cout << "Type : " << wc->getType() << " (associate sound : ";
	wc->makeSound();
	std::cout  << ")" <<std::endl;

	delete (meta);
	delete (j);
	delete (i);
	delete (w);
}