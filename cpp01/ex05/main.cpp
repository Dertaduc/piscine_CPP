/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:12:32 by candre--          #+#    #+#             */
/*   Updated: 2025/12/11 18:36:20 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main (void)
{
	Harl		instance;
	std::string	input;

	while (true)
	{
		std::cout << "Awaiting a complaint from Harl... : " << std::endl; 
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return (0);
		}
		instance.complain(input);
	}
	return (0);
}