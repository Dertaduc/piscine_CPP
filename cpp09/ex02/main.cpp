/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:41:32 by candre--          #+#    #+#             */
/*   Updated: 2026/07/22 23:50:54 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (0);
	}
	try
	{
		PmergeMe instance(&argv[1]);
		std::cout << YELLOW << "Max Ford Johnson comparison: " << instance.FJ_calculator() << RESET << std::endl;
		std::cout << GREY << "Before sorting: " << instance.get_vector() << RESET << std::endl;

		size_t time_vector = instance.sort_vector();
		size_t time_deque = instance.sort_deque();

		if (time_vector == time_deque)
			std::cout << "std::vector and std::deque took the same time" << std::endl;
		else if (time_vector < time_deque)
		{
			double ratio = static_cast<double>(time_deque - time_vector) / time_deque * 100.0;
			std::cout << "std::vector is faster than std::deque by " << ratio << "%" << std::endl;
		}
		else
		{
			double ratio = static_cast<double>(time_vector - time_deque) / time_vector * 100.0;
			std::cout << "std::deque is faster than std::vector by " << ratio << "%" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}