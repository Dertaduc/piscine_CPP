/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:38:51 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 19:24:04 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default_name"), _hit_point(10),  _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap : default constructor called\n";
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap with name constructor called : " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	std::cout << "ClapTrap copy constructor called\n"; 
	_name = to_copy._name;
	_hit_point = to_copy._hit_point;
	_energy_point = to_copy._energy_point;
	_attack_damage = to_copy._attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	std::cout << "ClapTrap operator = called\n"; 
	this->_name = assign._name;
	this->_hit_point = assign._hit_point;
	this->_energy_point = assign._energy_point;
	this->_attack_damage = assign._attack_damage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (_hit_point < 1)
	{
		std::cout << "ClapTrap " << _name << " is died, it can't attack\n";
		return ;
	}
	if (_energy_point < 1)
	{
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to attack\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attack_damage << " points of damage !\n"; 
	_energy_point += -1;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout << "ClapTrap " << _name << " must repair itself with positive number\n";
		return ;
	}
	if (_hit_point < 1)
	{
		std::cout << "ClapTrap " << _name << " is died, it can't repair itself\n";
		return ;
	}
	if (_energy_point < 1)
	{
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to repair itself\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << " is reparing itself... It went from " << _hit_point << " hit points to ";
	_hit_point += amount;
	std::cout << _hit_point << " hit points." << std::endl;
	_energy_point += -1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't take damage, is already dead\n";
		return;
	}
	if (_hit_point <= amount)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage points and is now dead\n";
		_hit_point = 0;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage points ! " << _hit_point - amount << " hit points remains\n";
		_hit_point -= amount;
	}
}

ClapTrap::~ClapTrap(void){std::cout << "ClapTrap destructor called : " << _name << std::endl;}
