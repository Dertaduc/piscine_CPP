/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:05:51 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 20:11:15 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP 
# define WRONGCAT_HPP

# include "Animal.hpp"
# include <iostream>

class WrongCat : public Animal
{
	public :
		WrongCat(void);
		~WrongCat(void);
		void makeSound(void) const;
	private :
		WrongCat(const WrongCat &to_copy);
		WrongCat &operator=(const WrongCat &assign);		
};

#endif