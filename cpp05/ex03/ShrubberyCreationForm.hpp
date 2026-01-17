/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:56:45 by candre--          #+#    #+#             */
/*   Updated: 2026/01/17 17:27:59 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include <exception>

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		virtual void	execute(const Bureaucrat &executor) const;
		virtual void	printAsciiArt(void) const;
        class OpenFileError : public std::exception
        {
            public :
                virtual const char *what(void) const throw();   
        };
	private :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &to_copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &to_assign);
};

#endif