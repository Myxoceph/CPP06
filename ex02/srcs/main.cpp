/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/12 16:15:35 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

int main()
{
	srand(time(0));
	Base *rand1 = generate();
	Base *rand2 = generate();
	Base *rand3 = generate();
	Base *rand4 = generate();

	std::cout << BLUE"==========================" << RESET << std::endl;
	std::cout << GREEN"Identify by pointer :" << RESET << std::endl;
	std::cout << CYAN"Random Object 1 : " << RESET;
	identify(rand1);
	std::cout << CYAN"Random Object 2 : " << RESET;
	identify(rand2);
	std::cout << CYAN"Random Object 3 : " << RESET;
	identify(rand3);
	std::cout << CYAN"Random Object 4 : " << RESET;
	identify(rand4);
	std::cout << BLUE"==========================" << RESET << std::endl;
	std::cout << GREEN"Identify by reference :" << RESET << std::endl;
	std::cout << CYAN"Random Object 1 : " << RESET;
	identify(*rand1);
	std::cout << CYAN"Random Object 2 : " << RESET;
	identify(*rand2);
	std::cout << CYAN"Random Object 3 : " << RESET;
	identify(*rand3);
	std::cout << CYAN"Random Object 4 : " << RESET;
	identify(*rand4);
	std::cout << BLUE"==========================" << RESET << std::endl;
	delete rand1;
	delete rand2;
	delete rand3;
	delete rand4;

	return 0;
}
