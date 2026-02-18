/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:12:27 by candre--          #+#    #+#             */
/*   Updated: 2026/02/17 20:14:13 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstdlib>
#include <vector>
#include <iostream>

class Span
{
	public : 
		Span(unsigned int n);
		~Span();

		void 				addNumber(int nbr);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
		std::vector<int>	getvector(void);
	private :
		std::vector<int>	_vector;
		const unsigned int	_size_max;
		Span(void);
		Span(const Span &to_copy);
		Span &operator=(const Span $to_assign);
};
#endif
