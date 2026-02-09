/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:30:39 by candre--          #+#    #+#             */
/*   Updated: 2026/02/09 16:01:27 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T> void printTemplate(T const &content)
{
	std::cout << content << std::endl;
}

template<typename T> void shuffle_array(T &content)
{
	content = rand() % 10;
}

template<typename T> void iter(T *array, const unsigned int lenght, void (*function)(T &))
{
	unsigned int i;

	i = 0;
	while (i < lenght)
	{
		function(array[i]);
		i++;
	}
}

template<typename T> void iter(const T *array, const unsigned int lenght, void (*function)(const T &))
{ 
	unsigned int i;

	i = 0;
	while (i < lenght)
	{
		function(array[i]);
		i++;
	}
}