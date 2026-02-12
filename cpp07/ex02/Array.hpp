/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:28:07 by candre--          #+#    #+#             */
/*   Updated: 2026/02/10 15:59:00 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array 
{
    public :
        Array(void) : _len_array(0), _array(NULL)
        {
            std::cout << "Constructor : Array (default constructor)\n";
        };

        Array(unsigned int len)
        {
            _len_array =len;
            _array = new T[len];
            std::cout << "Constructor : Array (len constructor)\n";  
        }

        Array(const Array &to_copy)
        {
            unsigned int i;
            _len_array = to_copy._len_array;
            _array = new T[_len_array];
            i = 0;
            while (i < _len_array)
            {
                _array[i] = to_copy._array[i];
                i++;
            }
        }

        ~Array(void)
        {
            if (_array)
                delete[] _array;
        }

        Array &operator=(const Array &to_assign)
        {
            int i;
            if (this != &to_assign)
                delete [] _array;
            this->_len_array = to_assign._len_array;
            this->_array = new T[_len_array];
            i = 0;
            while (i < this->_len_array)
            {
                _array[i] = to_assign._array[i];
                i++;
            }
            return (*this);
        }

        T &operator[](unsigned int index)
        {
            if (index < 0 || index >= this->_len_array)
            {
                throw std::out_of_range("index out of range : index must be between 0 and size()");
            }
            return (_array[index]);
        }
        unsigned int size(void)
        {
            return _len_array;
        };
    private :
        unsigned int    _len_array;
        T               *_array;
};

#endif