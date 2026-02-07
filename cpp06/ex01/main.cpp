/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:24:44 by candre--          #+#    #+#             */
/*   Updated: 2026/02/07 21:46:46 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

void promptDataStruct(Data *data)
{
    std::cout << "data adress : " << data << std::endl;
    std::cout << "str         : " << data->str << std::endl;
    std::cout << "nbr         : " << data->nbr << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    Data        a;
    uintptr_t   raw;
    Data *ptr_a;

    a.str = "Pierre Bourdieu is the best sociologist of all time";
    a.nbr = 42;

    promptDataStruct(&a);
    raw = Serializer::serialize(&a);
    std::cout << "raw ==        " << raw << std::endl << std::endl;
    ptr_a = Serializer::deserialize(raw);
    std::cout << "ptr_a ==      " << ptr_a << std::endl;
    promptDataStruct(ptr_a);
}