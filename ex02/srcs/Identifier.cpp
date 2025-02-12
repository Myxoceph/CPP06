/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:28 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/12 16:21:26 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	int i = rand() % 3;

	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << WHITE"A"RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << WHITE"B"RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << WHITE"C"RESET << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << WHITE"A"RESET << std::endl;
	}
	catch(...)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << WHITE"B"RESET << std::endl;
	}
	catch(...)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << WHITE"C"RESET << std::endl;
	}
	catch(...)
	{
	}
}
