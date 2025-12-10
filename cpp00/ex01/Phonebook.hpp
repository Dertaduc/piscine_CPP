/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:18:49 by candre--          #+#    #+#             */
/*   Updated: 2025/12/09 15:43:11 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
		bool	add_contact(void);
		bool	print_search(void);
		int		get_nb_contact(void) const;
	private:
		Contact _contact[8];
		int	_it_contact;
		int	_nb_contact;
};
#endif
