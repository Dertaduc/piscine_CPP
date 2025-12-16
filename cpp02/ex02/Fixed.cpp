/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:41:18 by candre--          #+#    #+#             */
/*   Updated: 2025/12/16 17:33:12 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionnal_bit = 8;

Fixed::Fixed(void) : _raw_value(0){}

Fixed::Fixed(const Fixed &copy) {this->_raw_value = copy._raw_value;}

Fixed::Fixed(const int n){_raw_value = n << 8;}

Fixed::Fixed(const float f){_raw_value = roundf(f * (1 << _fractionnal_bit));}

Fixed::~Fixed(void){}

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

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::operator=(const Fixed &assign)
{
	if (this != &assign)
		this->_raw_value = assign.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &comp) const
{
	return (_raw_value > comp._raw_value);
}

bool Fixed::operator<(const Fixed &comp) const
{
	return (_raw_value < comp._raw_value);
}

bool Fixed::operator<=(const Fixed &comp) const
{
	return (_raw_value <= comp._raw_value);
}

bool Fixed::operator>=(const Fixed &comp) const
{
	return (_raw_value >= comp._raw_value);
}

bool Fixed::operator!=(const Fixed &comp) const
{
	return (_raw_value != comp._raw_value);
}

bool Fixed::operator==(const Fixed &comp) const
{
	return (_raw_value == comp._raw_value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	float	result;

	result = this->toFloat() + other.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	float	result;

	result = this->toFloat() - other.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	float	result;

	result = this->toFloat() * other.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	float	result;

	result = this->toFloat() / other.toFloat();
	return (Fixed(result));
}

Fixed &Fixed::operator++()
{
	_raw_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp_class(*this);
	
	_raw_value++;
	return (tmp_class);
}

Fixed &Fixed::operator--()
{
	_raw_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp_class(*this);
	
	_raw_value--;
	return (tmp_class);
}


std::ostream &operator<<(std::ostream &ofs, Fixed const &fixed_inst)
{
	ofs << fixed_inst.toFloat();
	return (ofs);
}