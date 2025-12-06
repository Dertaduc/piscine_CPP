/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:10:39 by candre--          #+#    #+#             */
/*   Updated: 2025/12/06 13:23:52 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>


int	phonebook::get_nb_contact(void)const
{
	return (this->_nb_contact);
}

const std::string truncate(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0,9) + ".");
	return (field);
}

void phonebook::print_search(void)
{
	int nb_contact;
	int	i;
	int	select_contact;
	std::string input;

	nb_contact = get_nb_contact();
	if (nb_contact < 1)
	{
		std::cout << "No contact saved, you must ADD a contact before SEARCH" << std::endl;
		return ;
	}
	std::cout << std::setw(46) << std::setfill('=') << "\n" << std::setfill(' ');
	std::cout << "|" << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "firstname" << "|";
	std::cout << std::setw(10) << "lastname" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << std::setw(46) << std::setfill('=') << "\n" << std::setfill(' ');

	i = 0;
	while (i < nb_contact)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncate(_contact[i].get_firstname()) << "|";
		std::cout << std::setw(10) << truncate(_contact[i].get_lastname()) << "|";				
		std::cout << std::setw(10) << truncate(_contact[i].get_nickname()) << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << "Choose contact index to show all contact information : ";
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		exit(EXIT_SUCCESS);
	}
	select_contact = std::atoi(input.c_str());
	if (input.length() > 2 || select_contact <= 0 || select_contact > nb_contact)
	{
		std::cout << "Invalid index, please try a new search\n";
		return ;
	}
	_contact[select_contact - 1].display_contact_information();
}

void phonebook::add_contact(void)
{
	_it_contact = (_it_contact + 1) % 8;
	if (_nb_contact < 8)
		++_nb_contact;
	std::cout << std::endl <<  "Adding contact number : " << _it_contact + 1 << std::endl;
	_contact[_it_contact].set_contact();
	std::cout << std::endl << "Contact " << _it_contact + 1 << " succesfully added" << std::endl;
}

phonebook::phonebook(void)
{
	_it_contact = 7;
	_nb_contact = 0;
}

phonebook::~phonebook(void){}
