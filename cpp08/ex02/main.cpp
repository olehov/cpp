/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:03:57 by ogrativ           #+#    #+#             */
/*   Updated: 2026/02/20 16:15:33 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	mstack.pop();
// 	std::cout << "size:" << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

int main()
{
	std::cout << "=== SUBJECT TEST ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\nIterating MutantStack:" << std::endl;

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\nReverse iteration:" << std::endl;

	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\nCompare with std::list:" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}