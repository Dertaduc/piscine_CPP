/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:18:32 by candre--          #+#    #+#             */
/*   Updated: 2026/01/03 20:03:37 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &to_copy);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(const WrongAnimal &assign);
		void makeSound(void) const;
		std::string getType(void) const;
	protected :
		std::string type;
};

#endif