/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:09:46 by candre--          #+#    #+#             */
/*   Updated: 2025/12/09 15:27:52 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	public:
		HumanA(const char *name, Weapon& club);
		~HumanA(void);
		void attack(void) const;
	private:
		const std::string	_name; 
		const Weapon&		_weapon;
};

#endif