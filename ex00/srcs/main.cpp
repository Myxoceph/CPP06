/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/10 19:01:48 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		double f = 1.0e+40;
		// std::cerr << RED"Wrong input. Use: ./convert [input]"RESET << std::endl;
		std::cout << static_cast<float>(f) << std::endl;
		return 1;
	}
	else
	{
		ScalarConverter::convert(av[1]);
		return 0;
	}
}
