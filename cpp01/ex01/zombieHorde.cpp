/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:41:58 by candre--          #+#    #+#             */
/*   Updated: 2025/12/08 15:42:10 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*zomb_tab;
	int		i;

	zomb_tab = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zomb_tab[i].init_zomb(name);
		i++;
	}	
	return (zomb_tab);
}