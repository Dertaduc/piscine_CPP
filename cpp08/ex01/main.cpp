/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:00:42 by candre--          #+#    #+#             */
/*   Updated: 2026/02/19 18:42:12 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <exception>
#include <ostream>
#include <vector>
#include <ctime>



// int main(void)
// {
// 	Span a(3);
// 	srand(static_cast<unsigned int>(std::time(NULL)));

// 	try
// 	{
// 		// for (int i = 0; i < 5; i++)
// 		a.addNumber(INT_MAX);
// 		a.addNumber(INT_MIN);
// 		// a.addNumber(-1);
// 		printSpan(a.getvector());
// 		unsigned int reslong = a.longestSpan();
// 		std::cout << "longest span == " << reslong << std::endl;
// 		std::cout << "\n\n Show sorted copy\n";
// 		unsigned int resshort = a.shortestSpan();
// 		std::cout << "shortest span == " << resshort << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	return (0);
// }

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}