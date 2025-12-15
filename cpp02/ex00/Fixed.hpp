/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:30:50 by candre--          #+#    #+#             */
/*   Updated: 2025/12/15 18:49:35 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public :
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &assign);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private :
		int					_raw_value;
		static const int 	_fractionnal_bit;
};

#endif