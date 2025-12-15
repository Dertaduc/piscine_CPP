/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:30:50 by candre--          #+#    #+#             */
/*   Updated: 2025/12/15 20:51:37 by candre--         ###   ########.fr       */
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
		~Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int n);
		Fixed(const float f);
		Fixed &operator=(const Fixed &assign);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
	private :
		int					_raw_value;
		static const int 	_fractionnal_bit;
};

std::ostream &operator<<(std::ostream &ofs, Fixed const &fixed_inst);
#endif