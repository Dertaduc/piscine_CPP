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
	ScavTrap Bourdieu("Pierre Bourdieu");
	ScavTrap Maffesoli("Michel Maffesoli");
	ScavTrap Durkheim("Emile Durkheim");

	ScavTrap Pouet ("pouet");

	Pouet = Durkheim;

	Pouet.attack("cammenbert");
	//try repair
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10);
	Durkheim.beRepaired(10); // last energy point
	Durkheim.beRepaired(10);
	
	//Try attack
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli");
	Bourdieu.attack("Maffesoli"); // last attack available
	Bourdieu.attack("Maffesoli");

	//test take damage
	Maffesoli.takeDamage(1);
	Maffesoli.takeDamage(10);
	Maffesoli.beRepaired(42);
	Maffesoli.takeDamage(1);

	Maffesoli.guardGate();
	return (0);
}