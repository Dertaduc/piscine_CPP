/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:44:58 by candre--          #+#    #+#             */
/*   Updated: 2025/12/08 15:32:14 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	public:
				Zombie(void);
				~Zombie(void);
		void	init_zomb(std::string name);
		void	announce(void);
	private:
		std::string _name;
};
