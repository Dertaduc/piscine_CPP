/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:41:23 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 18:54:15 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	public :
		Animal(void);
		Animal(const Animal &to_copy);
		virtual ~Animal(void);
		Animal &operator=(const Animal &assign);
		virtual void makeSound(void) const;
		std::string getType(void) const;
	protected :
		std::string type;
};

#endif