/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:57:37 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 19:40:28 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &to_copy);
		~ScavTrap(void);
		ScavTrap &operator=(const ScavTrap &assign);
		void	attack(const std::string &target);
		void 	guardGate(void);
		private:
		ScavTrap(void);
};

#endif