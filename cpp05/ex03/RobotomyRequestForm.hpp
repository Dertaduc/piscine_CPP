/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:17:03 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 20:06:23 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		virtual void	execute(const Bureaucrat &executor) const;
		virtual void	printAsciiArt(void) const;

	private :
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &to_copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &to_assign);
};

#endif
