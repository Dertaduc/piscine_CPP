/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:46:05 by candre--          #+#    #+#             */
/*   Updated: 2025/12/05 17:26:01 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>
#include <stdlib.h>

static std::string get_input(const char *input_field)
{
	std::string input;

	while (true)
	{
		std::cout << "Enter a " << input_field << " : ";
		if (!getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(EXIT_SUCCESS);
		}
		if (!input.empty())
			break ;
		std::cout << "The field : " << input_field << " cannot be empty\n";
	}
	return (input);
}

void contact::display_contact_information(void) const
{
	std::cout << "first name is : " << _first_name << std::endl;
	std::cout << "last name is : " << _last_name << std::endl;
	std::cout << "nick name is : " << _nick_name << std::endl;
	std::cout << "phone number is : " << _phone_number << std::endl;
	std::cout << "darkest secret is : " << _darkest_secret << std::endl;
	return ;
}

const std::string contact::get_firstname(void)
{
	return (_first_name);
}
const std::string contact::get_lastname(void)
{
	return (_last_name);
}

const std::string contact::get_nickname(void)
{
	return (_nick_name);
}

void contact::set_contact(void)
{
	_first_name = get_input("first name");
	_last_name = get_input("last name");
	_nick_name = get_input("nickname");
	_phone_number = get_input("phone number");
	_darkest_secret = get_input("darkest secret");
	
}
contact::contact(void) {}
contact::~contact(void) {}
