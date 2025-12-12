/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:15:56 by candre--          #+#    #+#             */
/*   Updated: 2025/12/12 13:20:37 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

// void Harl::complain(std::string level)
// {
// 	int 		i;
// 	std::string (compare_tab[4]) = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	void		(Harl::*functionREF)(void);
// 	void		(Harl::*method[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

// 	functionREF = NULL;
// 	for (i = 0; i < 4; i++)
// 	{
// 		if (level == compare_tab[i])
// 		{
// 			functionREF = method[i];
// 			break ;
// 		}
// 	}
// 	if (!functionREF)
// 	{
// 		std::cout << "Harl has his mouth full; we can't understand what he's trying to say." << std::endl;
// 		return ;
// 	}
// 	std::cout << "Harl want's to share a " << level << " message : ";
// 	(this->*functionREF)();
// }

void Harl::complain(std::string level)
{
	int			i;
	int			level_int;
	std::string (compare_tab[4]) = {"DEBUG", "INFO", "WARNING", "ERROR"};

	level_int = -1;	
	for (i = 0; i < 4; i++)
	{
		if (level == compare_tab[i])
			level_int = i;
	}
	
	switch (level_int) {
		case 0 :
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout << "Harl has his mouth full; we can't understand what he's trying to say." << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{	
	std::cout << "[ ERROR ]\n";	
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void){}
Harl::~Harl(void){}
