/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:34:49 by candre--          #+#    #+#             */
/*   Updated: 2026/01/14 15:34:50 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form
{
	public :
		Form(void);
		Form(const std::string name, const int grade_sign, const int grade_exec);
		Form(const Form &to_copy);
		~Form(void);
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
		const std::string	getName(void) const;
		bool				getSignedStatus(void) const;
		int 				getGradeSign(void) const;
		int 				getGradeExec(void) const;
		void				beSigned(const Bureaucrat &employee);

	private :
		const std::string	_name;
		bool 				_signed;
		const int 			_grade_sign;
		const int			_grade_exec;
		Form &operator=(const Form &to_assign);
};

std::ostream &operator<<(std::ostream &ofs, Form const &to_print);

#endif