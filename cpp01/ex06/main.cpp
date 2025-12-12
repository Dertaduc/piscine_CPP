/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:12:32 by candre--          #+#    #+#             */
/*   Updated: 2025/12/12 10:14:20 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main (int argc, char *argv[])
{
	Harl		instance;

	if (argc != 2)
	{
		std::cout << "Wrong usage : <binary> <\"level_message\">\n"; 	
		return (0);
	}
	instance.complain(argv[1]);
	return (0);
}