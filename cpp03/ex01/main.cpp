/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:44:36 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 19:44:28 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	int		i;
	std::cout << "INIT CONSTRUCTOR\n";
	ScavTrap Bourdieu("Pierre Bourdieu");
	ScavTrap Maffesoli("Michel Maffesoli");
	ScavTrap Durkheim("Emile Durkheim");

	std::cout << "\n\nTEST ABILITIES\n";
	Maffesoli.guardGate();

	std::cout << "\n\nREPAIR LOOP\n";
	for(i = 0; i < 51; i++)
		Durkheim.beRepaired(10);
	
	std::cout << "\n\nTRY ATTACK\n";
	for(i = 0; i < 51; i++)
		Bourdieu.attack("Maffesoli");

	std::cout << "\n\nTRY DAMMAGE\n";
	Maffesoli.takeDamage(1);
	Maffesoli.takeDamage(84);
	Maffesoli.beRepaired(42);
	Maffesoli.takeDamage(90);
	Maffesoli.takeDamage(42);

	std::cout << "\n\nDESTRUCTOR CALL\n";
	return (0);
}