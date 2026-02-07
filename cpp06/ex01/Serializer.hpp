/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:38:23 by candre--          #+#    #+#             */
/*   Updated: 2026/02/07 21:45:46 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

// #include <cstdint>
#include <stdint.h>
#include <string>

typedef struct s_data
{
    std::string str;
    int         nbr;
} Data;


class Serializer
{
    public :
        static uintptr_t   serialize(Data *ptr);
        static Data        *deserialize(uintptr_t raw);
    private :
		Serializer(void);
		Serializer(const Serializer &to_copy);
		~Serializer(void);
		Serializer &operator=(const Serializer &to_assign);
};

#endif