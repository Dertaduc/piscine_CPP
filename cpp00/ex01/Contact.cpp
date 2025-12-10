/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:46:05 by candre--          #+#    #+#             */
/*   Updated: 2025/12/09 15:41:43 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <stdlib.h>

static bool get_input(const char *input_field, std::string& input)
{
	// std::string input;

	while (true)
	{
		std::cout << "Enter a " << input_field << " : ";
		if (!getline(std::cin, input))
		{
			std::cout << std::endl;
			// exit(EXIT_SUCCESS);
			return (false);
		}
		if (!input.empty())
			break ;
		std::cout << "The field : " << input_field << " cannot be empty\n";
	}
	return (true);
	// return (input);
}

void Contact::display_contact_information(void) const
{
	std::cout << "first name is : " << _first_name << std::endl;
	std::cout << "last name is : " << _last_name << std::endl;
	std::cout << "nick name is : " << _nick_name << std::endl;
	std::cout << "phone number is : " << _phone_number << std::endl;
	std::cout << "darkest secret is : " << _darkest_secret << std::endl;
	return ;
}

const std::string Contact::get_firstname(void)
{
	return (_first_name);
}
const std::string Contact::get_lastname(void)
{
	return (_last_name);
}

const std::string Contact::get_nickname(void)
{
	return (_nick_name);
}

bool Contact::set_contact(void)
{
	if (get_input("first name", _first_name) == false)
		return (false);
	if (get_input("last name", _last_name) == false)
		return (false);
	if (get_input("nickname", _nick_name) == false)
		return (false);
	if (get_input("phone number", _phone_number) == false)
		return (false);
	if (get_input("darkest secret", _darkest_secret) == false)
		return (false);
	return (true);
}
Contact::Contact(void) {}
Contact::~Contact(void) {}
