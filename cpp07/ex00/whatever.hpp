/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:00:14 by candre--          #+#    #+#             */
/*   Updated: 2026/02/09 15:11:03 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &A, T &B)
{
	T tmp = A;
	A = B;
	B = tmp;
	return ; 
}

template<typename T> T min(T &A, T &B)
{
	if (A < B)
		return (A);
	else
		return (B); 
}

template<typename T> T max(T &A, T &B)
{
	if (A > B)
		return (A);
	else
		return (B); 
}
#endif