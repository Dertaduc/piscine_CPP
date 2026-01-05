/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:31:38 by candre--          #+#    #+#             */
/*   Updated: 2026/01/05 14:32:05 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public :
		Brain(void);
		Brain(const Brain &to_copy);
		~Brain(void);
		Brain &operator=(const Brain &assign);
		const std::string &getIdea(int index) const;
	private :
		std::string ideas[100];
};

#endif