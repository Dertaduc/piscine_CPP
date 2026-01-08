/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:58:40 by candre--          #+#    #+#             */
/*   Updated: 2026/01/05 15:02:52 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	int random;

	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		random = rand() % 10;
		switch (random){
			case 0 :
				ideas[i] = "I want to eat";
				break;
			case 1 :
				ideas[i] = "I'm still hungry";
				break;
			case 2 :
				ideas[i] = "What if i ate again";
				break;
			case 3 :
				ideas[i] = "Go outside";
				break;
			case 4 :
				ideas[i] = "Open the door";
				break;
			case 5 :
				ideas[i] = "Why is the door closed";
				break;
			case 6 :
				ideas[i] = "Annoy my owner";
				break;
			case 7 :
				ideas[i] = "Stare at my owner until they give in";
				break;
			case 8 :
				ideas[i] = "Steal food";
				break;
			case 9 :
				ideas[i] = "That's mine";
				break;
			case 10 :
				ideas[i] = "Everything is mine";
				break;
		}
	}
	
}


Brain &Brain::operator=(const Brain &assign)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = assign.getIdea(i);
	return (*this);
}

const std::string &Brain::getIdea(int index) const
{
	return (ideas[index]);
}

Brain::Brain(const Brain &to_copy)
{
	*this = to_copy;
}

Brain::~Brain(void) {}


