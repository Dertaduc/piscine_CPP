/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:50:13 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 19:01:24 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP 
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
	public :
		Cat(void);
		~Cat(void);
		virtual void makeSound(void) const;
		void		getAllIdeas(void) const;
	private :
		Cat(const Cat &to_copy);
		Cat &operator=(const Cat &assign);
		Brain *brain;
};

#endif