/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:55:00 by candre--          #+#    #+#             */
/*   Updated: 2026/01/17 15:19:02 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		virtual void	execute(const Bureaucrat &executor) const;
		virtual void	printAsciiArt(void) const;

	private :
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &to_copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &to_assign);
};

#endif