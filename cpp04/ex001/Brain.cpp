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

Brain::Brain(void) {}

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


