/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:44:36 by candre--          #+#    #+#             */
/*   Updated: 2025/12/18 21:09:52 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	int		i;
	std::cout << "INIT CONSTRUCTOR\n";
	FragTrap Bourdieu("Pierre Bourdieu");
	ScavTrap Maffesoli("Michel Maffesoli");
	ClapTrap Durkheim("Emile Durkheim");

	std::cout << "\n\nTEST ABILITIES\n";
	Maffesoli.guardGate();
	Bourdieu.highFivesGuys();

	std::cout << "\n\nREPAIR LOOP\n";
	for(i = 0; i < 11; i++)
		Durkheim.beRepaired(10);
	
	std::cout << "\n\nTRY ATTACK\n";
	for(i = 0; i < 51; i++)
		Maffesoli.attack("Maffesoli");

	std::cout << "\n\nTRY DAMMAGE\n";
	Bourdieu.takeDamage(1);
	Bourdieu.takeDamage(84);
	Bourdieu.beRepaired(42);
	Bourdieu.takeDamage(90);
	Bourdieu.takeDamage(42);

	std::cout << "\n\nCOPY CONSTRUCTOR\n";
	FragTrap B(Bourdieu);
	ScavTrap M(Maffesoli);
	ClapTrap D(Durkheim);

	std::cout << "\n\n ASSIGNATION OPERATOR=\n";
	Bourdieu = B;
	Maffesoli = M;
	Durkheim = D;
	std::cout << "\n\nDESTRUCTOR CALL\n";
	return (0);
}