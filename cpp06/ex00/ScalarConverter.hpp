/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:34:11 by candre--          #+#    #+#             */
/*   Updated: 2026/02/06 19:51:09 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
	public :
		static void convert(std::string input);
	private :
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &to_copy);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &to_assign);
};
#endif