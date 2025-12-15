/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:41:18 by candre--          #+#    #+#             */
/*   Updated: 2025/12/15 21:20:26 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionnal_bit = 8;

Fixed::Fixed(void) : _raw_value(0)
{
	std::cout << "Constructor by default called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int n)
{
	_raw_value = n << 8;
	std::cout << "Constructor called for int\n";
}

Fixed::Fixed(const float f)
{
	_raw_value = roundf(f * (1 << _fractionnal_bit));
	std::cout << "Constructor called for float\n";	
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	return (_raw_value);
}

void Fixed::setRawBits(int const raw)
{
	_raw_value = raw;
}

float Fixed::toFloat() const
{
	float result;

	result = (float)_raw_value / ((1 << _fractionnal_bit));
	return (result);
}

int Fixed::toInt() const
{
	int result;
	
	result = _raw_value >> _fractionnal_bit;
	return (result);
}

Fixed &Fixed::operator=(const Fixed &assign)
{
	if (this != &assign)
		this->_raw_value = assign.getRawBits();

	std::cout << "Constructor operator called\n";
	return (*this);
}

std::ostream &operator<<(std::ostream &ofs, Fixed const &fixed_inst)
{
	ofs << fixed_inst.toFloat();
	return (ofs);
}