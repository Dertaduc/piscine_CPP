/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:36:48 by candre--          #+#    #+#             */
/*   Updated: 2025/12/08 17:13:36 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str;
	std::string 	*stringPTR;
	std::string		&stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;

	std::cout << "SUBJECT FIRST PART" << std::endl;
	std::cout << "str adress is :  " << &str << std::endl;
	std::cout << "str pointer is : " << stringPTR << std::endl;
	std::cout << "str ref is :     " << &stringREF << std::endl;

	std::cout << std::endl <<  "SUBJECT SECOND PART" << std::endl;
	std::cout << "str value is :     " << str <<  std::endl;
	std::cout << "str ptr value is : " << *stringPTR << std::endl;
	std::cout << "strREF value is :  " << stringREF <<  std::endl;
}