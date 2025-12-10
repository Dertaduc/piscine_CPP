/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:41:13 by candre--          #+#    #+#             */
/*   Updated: 2025/12/09 15:42:06 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		bool set_contact(void);
		void display_contact_information(void) const;
		const std::string get_firstname(void);
		const std::string get_lastname(void);
		const std::string get_nickname(void);
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
};
#endif