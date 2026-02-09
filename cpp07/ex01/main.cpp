/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:41:32 by candre--          #+#    #+#             */
/*   Updated: 2026/02/09 16:47:24 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	srand(static_cast<unsigned int>(std::time(NULL)));
	int arr_int[10] = {0,1,2,3,4,5,6,7,8,9};
	std::string arr_str[3] = {"Hello", "world", "!"};

	iter(arr_int, 10, printTemplate);
	iter(arr_str, 3, printTemplate);
	
	iter(arr_int, 10, shuffle_array);
	iter(arr_int, 10, printTemplate);	
}