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
# include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(const Dog &to_copy);
		~Dog(void);
		Dog &operator=(const Dog &assign);
		virtual void makeSound(void) const;
		void		getAllIdeas(void) const;
		std::string getIndexed_idea(int i) const;
	private :
		Brain *brain;
};

#endif