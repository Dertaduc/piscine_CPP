/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:57:17 by candre--          #+#    #+#             */
/*   Updated: 2026/02/18 18:14:59 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <stdexcept>

Span::Span(unsigned int n) : _vector(), _size_max(n) {}

Span::~Span(){}

void Span::addNumber(int nbr)
{
	if (_vector.size() >= _size_max)
		throw std::out_of_range("Cannot add number to vector");
	_vector.push_back(nbr);
}

std::vector<int> Span::getvector(void)
{
	return (_vector);
}