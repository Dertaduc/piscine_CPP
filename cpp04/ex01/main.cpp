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
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define NB_ANIMALS 5

void	delete_tab(Animal **tab)
{
	for (int i = 0; i < NB_ANIMALS; i++)
	{
		delete tab[i];
		tab[i] = NULL;
	}
}

bool init_tab(Animal **tab)
{
	int i;

	i = 0;

	try
	{
		for (; i < (NB_ANIMALS / 2); i++)
			tab[i] = new Dog;
		for (; i < (NB_ANIMALS); i++)
			tab[i] = new Cat;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		delete_tab(tab);
		return (false);
	}
	return (true);
}

void makesound(Animal **tab)
{
	for (int i = 0; i < NB_ANIMALS; i++)
	{
		tab[i]->makeSound();
		std::cout << std::endl;
	}	
}

void show_brain_state(Animal **tab)
{
	for (int i = 0; i < NB_ANIMALS; i++)
	{
		std::cout << i << " " << tab[i]->getType() << " :\n";
		tab[i]->getAllIdeas();
	}
}


int	main(void)
{
	Animal *tab[NB_ANIMALS] = {NULL};
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	srand(time(NULL));

	if (init_tab(tab) == false)
		return (1);
	makesound(tab);
	// show_brain_state(tab);
	delete_tab(tab);
	
	delete j;
	delete i;


	std::cout << "\n\n\n------------TEST of copy class : Cat----------\n";
	const Cat c;
	Cat d;
	// Cat d(c);

	// d = c;
	for (int i= 0; i < 100; i++)
	{
		std::cout << i;
		if (c.getIndexed_idea(i) == d.getIndexed_idea(i))
			std::cout<< " True : ";
		else
			std::cout << " False : ";
		std::cout << c.getIndexed_idea(i) << " ||| " << d.getIndexed_idea(i) << std::endl;
	}

	std::cout << "\n\n\n------------TEST of copy class : Dog----------\n";
	const Dog e;
	Dog f;
	// Dog f(e);

	f = e;
	for (int i= 0; i < 100; i++)
	{
		std::cout << i;
		if (e.getIndexed_idea(i) == f.getIndexed_idea(i))
			std::cout<< " True : ";
		else
			std::cout << " False : ";
		std::cout << e.getIndexed_idea(i) << " ||| " << f.getIndexed_idea(i) << std::endl;
	}
}
