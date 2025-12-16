/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:30:50 by candre--          #+#    #+#             */
/*   Updated: 2025/12/16 17:41:23 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed(void);
		
		Fixed	&operator=(const Fixed &assign);

		bool	operator>(const Fixed &comp) const ;
		bool	operator<(const Fixed &comp) const ;
		bool	operator>=(const Fixed &comp) const ;
		bool	operator<=(const Fixed &comp) const ;
		bool	operator!=(const Fixed &comp) const ;
		bool	operator==(const Fixed &comp) const ;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float 	toFloat() const;
		int 	toInt() const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private :
		int					_raw_value;
		static const int 	_fractionnal_bit;
};

std::ostream &operator<<(std::ostream &ofs, Fixed const &fixed_inst);
#endif