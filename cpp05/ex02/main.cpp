/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:17:36 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 20:36:55 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>

int main(void)
{
	srand(time(NULL));
	RobotomyRequestForm a("coucou");
	Bureaucrat b("test", 30);
	Bureaucrat c("test2", 90);

	// try {
	// 	b.signForm(a);
	// 	a.execute(b);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	b.executeForm(a);
	b.signForm(a);
	c.executeForm(a);
	b.executeForm(a);
	return (0);
}