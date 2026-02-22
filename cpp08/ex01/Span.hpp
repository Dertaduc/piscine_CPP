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
		Span(const Span &to_copy);

		~Span();

		void 				addNumber(int nbr);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
		void				addMultipleNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void				showSpanInfo(void) const;
	private :
		std::vector<int>	_vector;
		const unsigned int	_size_max;
		Span &operator=(const Span &to_assign);
};

#endif
