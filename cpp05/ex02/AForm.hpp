/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:13:31 by candre--          #+#    #+#             */
/*   Updated: 2026/01/16 18:13:34 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <string>

class Bureaucrat;

class AForm
{
	public :
		AForm(void);
		AForm(const std::string name, const int grade_sign, const int grade_exec);
		AForm(const AForm &to_copy);
		~AForm(void);
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
		class UnsignedDocumentException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();	
		};
		std::string	getName(void) const;
		bool				getSignedStatus(void) const;
		int 				getGradeSign(void) const;
		int 				getGradeExec(void) const;
		void				beSigned(const Bureaucrat &employee);
		virtual void		execute(Bureaucrat const &executor) const = 0;
		virtual void		printAsciiArt(void) const = 0;
	private :
		const std::string	_name;
		bool 				_signed;
		const int 			_grade_sign;
		const int			_grade_exec;
		AForm &operator=(const AForm &to_assign);
};

std::ostream &operator<<(std::ostream &ofs, AForm const &to_print);

#endif