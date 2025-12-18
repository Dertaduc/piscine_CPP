/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:16:17 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 19:42:14 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap with name constructor called : " << _name << std::endl;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called : " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &to_copy) : ClapTrap(to_copy)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	std::cout << "ScavTrap operator = called\n"; 
	this->_name = assign._name;
	this->_hit_point = assign._hit_point;
	this->_energy_point = assign._energy_point;
	this->_attack_damage = assign._attack_damage;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (_hit_point < 1)
	{
		std::cout << "ScavTrap " << _name << " is died, it can't attack\n";
		return ;
	}
	if (_energy_point < 1)
	{
		std::cout << "ScavTrap " << _name << " doesn't have enough energy points to attack\n";
		return ;
	}
	std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attack_damage << " points of damage !\n"; 
	_energy_point += -1;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap : the ScavTrap " << _name << " is now in Gate keeper mode\n";
}