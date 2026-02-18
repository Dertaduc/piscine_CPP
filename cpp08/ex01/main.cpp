/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:00:42 by candre--          #+#    #+#             */
/*   Updated: 2026/02/18 19:32:54 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <vector>
#include <ctime>

void printSpan(Span &span)
{
	std::vector<int> a = span.getvector();
	
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[static_cast<size_t>(i)] << std::endl;
	}
}

int main(void)
{
	Span a(12);
	srand(static_cast<unsigned int>(std::time(NULL)));

	try
	{
		for (int i = 0; i < 12; i++)
			a.addNumber(rand() % 42);
		printSpan(a);
				
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}