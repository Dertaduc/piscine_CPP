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
#include <algorithm>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int n) : _vector(), _size_max(n) {}

Span::Span(const Span &to_copy) : _vector(to_copy._vector), _size_max(to_copy._size_max) {}

Span::~Span(){}

void Span::addNumber(int nbr)
{
	if (_vector.size() >= _size_max)
		throw std::out_of_range("Cannot add number to vector");
	_vector.push_back(nbr);
}

unsigned int Span::longestSpan(void)
{
	std::vector<int>::const_iterator min;
	std::vector<int>::const_iterator max;

	if (_vector.size() < 2)
		throw std::out_of_range("Too few integers in the vector to calculate the longest span");
    min = std::min_element(_vector.begin(), _vector.end());
    max = std::max_element(_vector.begin(), _vector.end());

    return (static_cast<unsigned int>(*max - *min));
}

unsigned int Span::shortestSpan(void)
{
	if (_vector.size() < 2)
		throw std::out_of_range("Too few integers in the vector to calculate the shortest span");
	
	unsigned int diff;
	unsigned int tmp_diff;
	std::vector<int> copy_vector(_vector);

	std::sort(copy_vector.begin(), copy_vector.end());
	diff = static_cast<unsigned int>(copy_vector[1] - copy_vector[0]);
	for (unsigned int i = 1; i < copy_vector.size() - 1; i++)
	{
		tmp_diff = static_cast<unsigned int>(copy_vector[i + 1] - copy_vector[i]);
		if (tmp_diff < diff)
			diff = tmp_diff;
	}
	return (diff);
}

void Span::addMultipleNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::vector<int>::difference_type diff = std::distance(start, end);

	if (diff < 0)
		throw std::runtime_error("Invalid iterator range");

	if (_vector.size() + static_cast<size_t>(diff) > _size_max)
		throw std::out_of_range("Not enough space left in vector");
	_vector.insert(_vector.end(), start, end);
}

void Span::showSpanInfo(void) const
{
	std::cout << "--- SPAN INFORMATIONS---\n";
	std::cout << "_size_max = " << _size_max << std::endl;
	std::cout << "vector content :" << std::endl;
	
	for (unsigned long i = 0; i < _vector.size(); i++)
	{
		if (i < _vector.size() -1)
			std::cout << _vector[i] << ", ";
		else
			std::cout << _vector[i] << std::endl;
	}
	std::cout << "------------------------\n";
}