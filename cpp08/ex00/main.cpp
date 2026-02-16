/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:21:23 by candre--          #+#    #+#             */
/*   Updated: 2026/02/16 22:37:33 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>

#include <list>
#include <vector>
#include <deque>
#include <set>

int main(void)
{
	int searched = 9;
	int not_find = 42;
	
	std::cout << "__________Try with std::list<int>__________\n";
	try
	{
		std::list<int>::iterator iter;
		std::list<int> list_container;
		for (int i = 0; i < 10; i++)
			list_container.insert(list_container.end(), i);
		iter = easyfind(list_container, searched);
		std::cout << *iter  << " where found in list container" << std::endl;
		iter = easyfind(list_container, not_find);
		std::cout << *iter  << " where found in list container" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n\n__________Try with std::vector<int>________\n";
	try
	{
		std::vector<int>::iterator iter;
		std::vector<int> vector_container;
		for (int i = 0; i < 10; i++)
			vector_container.insert(vector_container.end(), i);
		iter = easyfind(vector_container, searched);
		std::cout << *iter  << " where found in vector container" << std::endl;
		iter = easyfind(vector_container, not_find);
		std::cout << *iter  << " where found in vector container" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\n__________Try with std::deque<int>_________\n";
	try
	{
		std::deque<int>::iterator iter;
		std::deque<int> deque_container;
		for (int i = 0; i < 10; i++)
			deque_container.insert(deque_container.end(), i);
		iter = easyfind(deque_container, searched);
		std::cout << *iter  << " where found in deque container" << std::endl;
		iter = easyfind(deque_container, not_find);
		std::cout << *iter  << " where found in deque container" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n\n__________Try with std::set<int>___________\n";
	try
	{
		std::set<int>::iterator iter;
		std::set<int> set_container;
		for (int i = 0; i < 10; i++)
			set_container.insert(set_container.end(), i);
		iter = easyfind(set_container, searched);
		std::cout << *iter  << " where found in set container" << std::endl;
		iter = easyfind(set_container, not_find);
		std::cout << *iter  << " where found in set container" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}