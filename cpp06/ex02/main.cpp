/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:47:25 by candre--          #+#    #+#             */
/*   Updated: 2026/02/08 23:01:52 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    int random;

   	random = rand() % 3;
    switch(random)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (NULL);
}

void identify(Base *p)
{
    if (!p)
        throw std::invalid_argument("NULL pointer passed to identify(*p)");
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "identify by pointer : A";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "identify by pointer : B";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "identify by pointer : C";
    else
        throw std::logic_error("Dynamic cast failed\n");
    std::cout << std::endl;
}

void identify(Base &ref)
{
    try
    {
       A  &a = dynamic_cast<A&>(ref);
       std::cout << "identify by ref :     A\n";
       static_cast<void>(a);
       return ;
    }
    catch (std::exception){}
    try
    {
       B  &b = dynamic_cast<B&>(ref);
       std::cout << "identify by ref :     B\n";
       static_cast<void>(b);
       return ;
    }
    catch (std::exception){}
    try
    {
       C  &c = dynamic_cast<C&>(ref);
       std::cout << "identify by ref :     C\n";
       static_cast<void>(c);
       return ;
    }
    catch (std::exception){}
    throw std::logic_error("Dynamic cast failed\n");   
}
int main(void)
{
    Base *random_base;
    random_base = NULL;
	srand(static_cast<unsigned int>(std::time(NULL)));
    try 
    {
        random_base = generate();
        identify(random_base);
        identify(*random_base);
    }
    catch (std::exception &e)
    {
        std::cout << "An error occured because : " << e.what() << std::endl;
    }
    if (random_base)
        delete (random_base);
}
