/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:41:25 by candre--          #+#    #+#             */
/*   Updated: 2026/02/10 16:26:39 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::cout << "__________Test for int array__________\n";
    try
    {
        Array<int> a;
        Array<int> b(3);
      
        std::cout << "_show array content_\n";
        for (unsigned int i = 0; i <  3; i++)
        {
            std::cout << b[i] << std::endl;
        }
        for (unsigned int i = 0; i < 3; i++)
        {
            b[i] = rand() % 42;
        }

        std::cout << "_show array content_\n";
        for (unsigned int i = 0; i <  3; i++)
        {
            std::cout << b[i] << std::endl;
        }
        
        Array<int> c(b);
        std::cout << "All constructions worked\n";

        for (unsigned int i = 0; i < 3; i++)
        {
            if (c[i] != b[i])// access by operator[]
                std::cout << "Array c and b are diverging in this index : " << i << std::endl;
            else
                std::cout << "C and B are equals in this index : " << i << std::endl;
        }

        std::cout << "_____ acces [i] out of array scope_______\n";
        std::cout << "array size == " << c.size() << std::endl;

        std::cout << "try an access at size() + 1\n";
        std::cout << c[c.size() + 1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl; 
    }




    std::cout << "\n\n\n__________Test for std::string array__________\n";
    try
    {
        Array<std::string> a;
        Array<std::string> b(3);

        b[0] = "Hello";
        b[1] = "world";
        b[2] = "!";

        std::cout << "_show array content_\n";
        for (unsigned int i = 0; i <  3; i++)
        {
            std::cout << b[i] << std::endl;
        }
        Array<std::string> c(b);
        std::cout << "All constructions worked\n";
        for (unsigned int i = 0; i < 3; i++)
        {
            if (c[i] != b[i])// access by operator[]
                std::cout << "Array c and b are diverging in this index : " << i << std::endl;
            else
                std::cout << "C and B are equals in this index : " << i << std::endl;
        }

        std::cout << "_____ acces [i] out of array scope_______\n";
        std::cout << "array size == " << c.size() << std::endl;

        std::cout << "try an access at size() + 1\n";
        std::cout << c[c.size() + 1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl; 
    }
}

#define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
// 	srand(static_cast<unsigned int>(std::time(NULL)));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }