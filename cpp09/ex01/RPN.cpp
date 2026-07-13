/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:00:53 by candre--          #+#    #+#             */
/*   Updated: 2026/07/13 20:43:34 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN(const std::string &str)
{
	read_input(str);
}
RPN::~RPN(){}

void RPN::read_input(const std::string &str)
{
	std::stringstream ss(str);
	std::string token;

	while (ss >> token)
	{
		if (token.size() == 1 && isdigit(token[0]))
			_calculator.push(token[0] - '0');
		else if (token.size() == 1 && (token.find_first_of("/*+-") != token.npos))
		{
			if (_calculator.size() < 2)
				throw (std::runtime_error("Error"));
			process_operation(token[0]);
		}
		else
			throw (std::runtime_error("Error"));
	}
	if (_calculator.size() != 1)
		throw(std::runtime_error("Error"));
}

void RPN::process_operation(char opp)
{
	int a;
	int b;
	int result;

	a = _calculator.top();
	_calculator.pop();
	b = _calculator.top();
	_calculator.pop();

	switch (opp)
	{
		case '*':
			result = a * b;
			break;
		case '+':
			result = a + b;
			break;
		case '-':
			result = b - a;
			break;
		case '/':
			if (a == 0)
				throw (std::runtime_error("Error"));
			result = b / a;
			break;
		default:
			throw (std::runtime_error("Error"));
	}
	_calculator.push(result);
}

int RPN::get_top_elem(void)
{
	return (_calculator.top());
}