/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:33:26 by candre--          #+#    #+#             */
/*   Updated: 2025/12/09 12:12:46 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

const std::string& Weapon::getType(void) const
{
	return (_weapon);
}

void Weapon::setType(std::string weapon)
{ 
	_weapon = weapon;
}

Weapon::Weapon(std::string weapon) : _weapon(weapon){}
Weapon::~Weapon(void){}
