/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:12:40 by candre--          #+#    #+#             */
/*   Updated: 2025/12/11 17:22:51 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
	public :
		Harl();
		~Harl(void);
		void complain(std::string level);
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif