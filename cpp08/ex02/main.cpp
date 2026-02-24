/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candre-- <candre--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:08 by candre--          #+#    #+#             */
/*   Updated: 2026/02/25 00:22:02 by candre--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

void subjectMain(void)
{
	std::cout << "_________Subject test_______\n";
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}


void testMutantStack(void)
{
	std::cout << "\n_________MutantStack Test_________\n";
	MutantStack<int> 		mstack;
	const MutantStack<int>& const_stack =	mstack;	
	
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);
	mstack.push(40);	
	
	std::cout << "== non-const iterator ==" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;	
	
	std::cout << "== const iterator ==" << std::endl;
	for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;	
	
	std::cout << "== reverse iterator ==" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;	
	
	std::cout << "== const reverse iterator ==" << std::endl;
	for (MutantStack<int>::const_reverse_iterator rit = const_stack.rbegin(); rit != const_stack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	std::cout << "____ Shos std::stack features are preserved____==" << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "After pop, top element: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;		
}

void compareList(void)
{
	std::cout << "\n_________std::list Test_________\n";
	std::list<int> 		mstack;
	const std::list<int>& const_stack =	mstack;	
	
	mstack.push_back(10);
	mstack.push_back(20);
	mstack.push_back(30);
	mstack.push_back(40);	
	
	std::cout << "== non-const iterator ==" << std::endl;
	for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;	
	
	std::cout << "== const iterator ==" << std::endl;
	for (std::list<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;	
	
	std::cout << "== reverse iterator ==" << std::endl;
	for (std::list<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;	
	
	std::cout << "== const reverse iterator ==" << std::endl;
	for (std::list<int>::const_reverse_iterator rit = const_stack.rbegin(); rit != const_stack.rend(); ++rit)
	{
		std::cout << *rit << " ";
	}	
}

int main()
{
	subjectMain();
	testMutantStack();
	compareList();
	return (0);
}