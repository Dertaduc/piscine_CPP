/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:18:49 by candre--          #+#    #+#             */
/*   Updated: 2025/12/05 17:00:37 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "contact.hpp"

class phonebook
{
	public:
		phonebook(void);
		~phonebook(void);
		void	add_contact(void);
		void	print_search(void);
		int		get_nb_contact(void) const;
	private:
		contact _contact[8];
		int	_it_contact;
		int	_nb_contact;
};
#endif
