/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:54:20 by candre--          #+#    #+#             */
/*   Updated: 2025/12/08 14:50:14 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie *zomb_ptr;
	
	zomb_ptr = newZombie("heap_zomb");
	if (!zomb_ptr)
		return (1);
	randomChump("stack_zomb");
	zomb_ptr->announce();
	delete (zomb_ptr);
	return (0);
}