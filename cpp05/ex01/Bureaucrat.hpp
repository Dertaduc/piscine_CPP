/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:10:16 by candre--          #+#    #+#             */
/*   Updated: 2026/01/14 13:38:29 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>
# include <iostream>
# include <stdexcept>

class Form;

class Bureaucrat
{
	public :
		Bureaucrat(void);
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(const Bureaucrat &to_copy);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &to_assign);
		const std::string	getName(void) const;
		unsigned int		getGrade(void)const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form &form);
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
	private :
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream &operator<<(std::ostream &ofs, Bureaucrat const &to_print);

#endif