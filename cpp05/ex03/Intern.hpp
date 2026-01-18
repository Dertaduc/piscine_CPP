/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:07:02 by candre--          #+#    #+#             */
/*   Updated: 2026/01/18 11:21:22 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS
# define INTERN_CLASS

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public :
        Intern(void);
        ~Intern(void);
        AForm *makeForm(std::string formName, std::string target);
    private :
        Intern(const Intern &to_copy);
        Intern &operator=(const Intern &to_assign);
};

#endif