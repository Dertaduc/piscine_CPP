/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:27:04 by candre--          #+#    #+#             */
/*   Updated: 2026/02/06 22:01:58 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

bool is_nan_inf(std::string &input) // check si pas des comparaison superflues
{
	if (input.compare("+inf") == 0 ||
			input.compare("-inf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0 || input.compare("nan") == 0)
		return(true);
	return (false); 
}

bool is_number(std::string &input)
{
	char *last_str;

	std::strtod(input.c_str(), &last_str);

	if (last_str == input.c_str()) // voir si bonne protection avec funcheck
	{
		std::cout << "Error\n";
		return (false);
	}
	if (*last_str == '\0')
		return (true);
	if (*last_str == 'f' && last_str[1] =='\0')
		return (true);
	return (false);
}

bool is_char(std::string &input)
{
	if (std::isalpha(static_cast<unsigned char>(input[0])) == true && input.length() == 1)
		return (true);
	return (false);
}

void convertchar(double input)
{
	if (input >= 32 && input <= 126)
		std::cout << "char : '" << static_cast<char>(input) << "'\n";
	else if  (input >= 0 && input <= 127)
		std::cout << "char : non displayable\n";
	else
		std::cout << "char : impossible (out of ascii bounds)\n";
}

void convertint(double result)
{
	if (result < INT_MIN || result > INT_MAX)
	{
		std::cout << "int : impossible (out of bounds int min/max)\n";
		return ;
	}
	std::cout << "int : " << static_cast<int>(result) << "\n";
	return ;
}

void convertfloat(double result)
{
	if (result == 1.0 / 0.0)
		std::cout << "float : +inff\n";
	else if (result == -1.0 / 0.0)
		std::cout << "float : -inff\n";
	else if (result != result)
		std::cout << "float : nanf\n";
	else
	{
		std::cout << "float : " << static_cast<float>(result);
		if (static_cast<float>(result) ==  static_cast<int>(result))
			std::cout << ".0";
		std::cout << "f\n";
	}	
}

void convertdouble(double result)
{
	if (result == 1.0 / 0.0)
		std::cout << "double : +inf\n";
	else if (result == -1.0 / 0.0)
		std::cout << "double : -inf\n";
	else if (result != result)
		std::cout << "double : nan\n";
	else
	{
		std::cout << "double : " << result;
		if (result ==  static_cast<int>(result))
			std::cout << ".0";
		std::cout << "\n";
	}	
}

void ScalarConverter::convert(std::string input)
{
	double result;

	if (is_nan_inf(input) == true || is_number(input) == true)
		result = std::strtod(input.c_str(), NULL);
	else if (is_char(input))
		result = static_cast<double>(input[0]);
	else
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : impossible\n";
		std::cout << "double : impossible\n";
		return;
	}
	convertchar(result);
	convertint(result);
	convertfloat(result);
	convertdouble(result);
}