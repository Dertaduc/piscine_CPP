/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:46:27 by candre--          #+#    #+#             */
/*   Updated: 2026/02/16 22:28:51 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <stdexcept>
template<typename T>
typename T::iterator easyfind(T &container, const int to_find)
{
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), to_find);
	if (iter != container.end())
		return (iter);
	else
		throw std::invalid_argument("param <to_find> not found in container");
}

// template<typename T>
// typename T::const_iterator easyfind(const T &container, const int to_find)
// {
// 	typename T::const_iterator iter;
// 	iter = std::find(container.begin(), container.end(), to_find);
// 	if (iter != container.end())
// 		return (iter);
// 	else
// 		throw std::exception();
// }

#endif