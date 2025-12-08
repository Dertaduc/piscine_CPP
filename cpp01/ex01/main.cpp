/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:04:47 by candre--          #+#    #+#             */
/*   Updated: 2025/12/08 15:44:31 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *zomb_tab;
	int		N;

	N = 10;
	zomb_tab = zombieHorde(N, "Horde");
	for (int i = 0; i < N; i++)
		zomb_tab[i].announce();
	delete[] zomb_tab;
}