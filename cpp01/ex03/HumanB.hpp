/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:03:49 by candre--          #+#    #+#             */
/*   Updated: 2025/12/09 15:27:57 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	public:
		HumanB(const char *name);
		~HumanB(void);
		void attack(void) const;
		void setWeapon(Weapon &weapon);
	private:
		const std::string	_name; 
		const Weapon*		_weapon;
};


#endif