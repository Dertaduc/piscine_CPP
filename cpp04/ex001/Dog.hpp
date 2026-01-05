/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:42:41 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 18:43:53 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP 
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	public :
		Dog(void);
		~Dog(void);
		virtual void makeSound(void) const;
	private :
		Dog(const Dog &to_copy);
		Dog &operator=(const Dog &assign);
		
};

#endif