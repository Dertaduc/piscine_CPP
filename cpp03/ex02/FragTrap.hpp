/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:45:58 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 20:49:51 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap(std::string name);
		FragTrap(const FragTrap &to_copy);
		~FragTrap(void);
		FragTrap &operator=(const FragTrap &assign);
		void highFivesGuys(void);
	private:
		FragTrap(void);
};

#endif