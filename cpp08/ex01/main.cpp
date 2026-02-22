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
#include <exception>
#include <climits>

int main(void)
{
	try
	{
		std::cout << "_______Test addnumber in row______\n" ;
		Span sp(5);
		
		sp.showSpanInfo();
		for (int i = 0; i < 5; i++)
		{
			sp.addNumber(i);
		}
		sp.showSpanInfo();
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span =  " << sp.longestSpan() << std::endl;
		
		std::cout << "try to add a number in a full _vector ? : ";
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	
	try
	{
		std::cout << "\n\n________Test overflow________\n";
		Span sp(2);

		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		sp.showSpanInfo();
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span =  " << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	
	
	try
	{
		std::cout << "\n\n________Test add multiple number________\n";
		Span sp(5);
		int arr[] = {1,2,3, 10, 43};
		std::vector<int> insert_v(arr, arr + 5);

		sp.addMultipleNumber(insert_v.begin(), insert_v.end());
		sp.showSpanInfo();
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span =  " << sp.longestSpan() << std::endl;
		std::cout << "try to add multiple number in a full vector  ? : ";
		sp.addMultipleNumber(insert_v.begin(),insert_v.begin() + 1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	
	try
	{
		std::cout << "\n\n________Test add multiple number : with invalid iterators________\n";
		Span sp(5);
		int arr[] = {1,2,3, 10, 43};
		std::vector<int> insert_v(arr, arr + 5);

		sp.addMultipleNumber(insert_v.begin() + 4, insert_v.begin());;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// try
	// {
	// 	int arr[] = {1,2,3, 10, 43};
	// 	std::vector<int> insert_v(arr, arr + 5);
	// 	Span sp = Span(7);
		
	// 	sp.addNumber(6);
	// 	sp.addNumber(3);
	// 	sp.addMultipleNumber(insert_v.begin(), insert_v.end());
	// 	// sp.addNumber(17);
	// 	// sp.addNumber(9);
	// 	// sp.addNumber(11);
	// 	sp.showSpanInfo();
	// 	std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
	// 	std::cout << "Longest span =  " << sp.longestSpan() << std::endl;
	// }
	// catch(std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
}