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
	return (_type);
}

void Weapon::setType(std::string weapon)
{ 
	_type = weapon;
}

Weapon::Weapon(std::string weapon) : _type(weapon){}
Weapon::~Weapon(void){}
