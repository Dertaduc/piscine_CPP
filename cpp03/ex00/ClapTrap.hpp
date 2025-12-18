/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:29:28 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 16:40:31 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public :
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &to_copy);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &assign);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private :
		ClapTrap(void);
		std::string	_name;
		unsigned int	_hit_point;
		int				_energy_point;
		int				_attack_damage;
};

#endif