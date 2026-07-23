/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:44:46 by candre--          #+#    #+#             */
/*   Updated: 2026/07/13 20:44:08 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <list>
#include <sstream>
#include <climits>

class RPN
{
	public :
		RPN(const std::string &str);
		~RPN(void);

		void	process_operation(char opp);
		int		get_top_elem(void);
		
	private :
		void	read_input(const std::string &str);
		std::stack<int, std::list<int> > _calculator;
		RPN(void);
		RPN &operator=(const RPN &to_assign);
		RPN(const RPN& to_copy);
	
};

#endif