/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:41:18 by candre--          #+#    #+#             */
/*   Updated: 2025/12/15 19:01:02 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionnal_bit = 8;

int Fixed::getRawBits(void) const
{
	return (_raw_value);
}

void Fixed::setRawBits(int const raw)
{
	_raw_value = raw;
}

Fixed::Fixed(void) : _raw_value(0)
{
	std::cout << "Constructor by default called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &assign)
{
	if (this != &assign)
		this->_raw_value = assign.getRawBits();

	std::cout << "Constructor operator called\n";
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}
