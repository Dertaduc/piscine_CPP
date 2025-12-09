/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:31:04 by candre--          #+#    #+#             */
/*   Updated: 2025/12/09 13:18:15 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	public :
		Weapon(std::string weapon);
		~Weapon(void);
		const std::string& getType(void) const;
		void setType(std::string weapon);
	private :
		std::string _weapon;
};

#endif