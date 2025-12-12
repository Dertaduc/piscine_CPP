/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:15:56 by candre--          #+#    #+#             */
/*   Updated: 2025/12/11 18:40:14 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string level)
{
	int 		i;
	std::string (compare_tab[4]) = {"debug", "info", "warning", "error"};
	void		(Harl::*functionREF)(void);
	void		(Harl::*method[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	functionREF = NULL;
	for (i = 0; i < 4; i++)
	{
		if (level == compare_tab[i])
		{
			functionREF = method[i];
			break ;
		}
	}
	if (!functionREF)
	{
		std::cout << "Harl has his mouth full; we can't understand what he's trying to say." << std::endl;
		return ;
	}
	std::cout << "Harl want's to share a " << level << " message : ";
	(this->*functionREF)();
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void){}
Harl::~Harl(void){}
