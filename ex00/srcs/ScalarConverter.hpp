/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:22:23 by abakirca          #+#    #+#             */
/*   Updated: 2025/03/07 23:02:34 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

#define CHAR "\033[1;32mChar	: \033[1;37m"
#define INT "\033[1;33mInt	: \033[1;37m"
#define FLOAT "\033[1;36mFloat	: \033[1;37m"
#define DOUBLE "\033[1;34mDouble	: \033[1;37m"

#define VAL_CHAR 1
#define VAL_INT 2
#define VAL_FLOAT 3
#define VAL_DOUBLE 4

class ScalarConverter
{
	private:
			ScalarConverter();
			ScalarConverter(ScalarConverter const &copy);
			ScalarConverter &operator=(ScalarConverter const &copy);
			~ScalarConverter();
	public:
			static void convert(std::string input);
};


#endif
