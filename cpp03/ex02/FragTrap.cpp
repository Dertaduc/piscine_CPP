/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:50:18 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 20:57:01 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap with name constructor called : " << _name << std::endl;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called : " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &to_copy) : ClapTrap(to_copy)
{
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &assign)
{
	std::cout << "FragTrap operator = called\n"; 
	this->_name = assign._name;
	this->_hit_point = assign._hit_point;
	this->_energy_point = assign._energy_point;
	this->_attack_damage = assign._attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap : " << _name << " ask for an BIG HIGH-FIVES !\n";
}