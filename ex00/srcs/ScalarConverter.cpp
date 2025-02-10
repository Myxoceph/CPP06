/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:24:27 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/10 19:05:46 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if(this != &copy)
	{
		*this = copy;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static int check_psuedo(std::string input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << CHAR << RED"impossible"RESET << std::endl;
		std::cout << INT << RED"impossible"RESET << std::endl;
		std::cout << FLOAT << input << RESET << std::endl;
		std::cout << DOUBLE << input.substr(0, input.size() - 1) << RESET << std::endl;
		return (1);
	}
	else if (input == "nan" || input == "+inf" || input == "-inf")
	{
		std::cout << CHAR << RED"impossible"RESET << std::endl;
		std::cout << INT << RED"impossible"RESET << std::endl;
		std::cout << FLOAT << input << "f" << RESET << std::endl;
		std::cout << DOUBLE << input << RESET << std::endl;
		return (1);
	}
	else
		return (0);
}

static int check_char(std::string input)
{
	if (input.size() == 1 && !isdigit(input[0]))
		return (VAL_CHAR);
}

static int check_int(std::string input)
{
	long	i = 0;
	bool	is_digits = true;
	int		sign = 1;

	if (input[0] == '+' || input[0] == '-')
	{
		if (input[0] == '-')
			sign = -1;
		input = input.substr(1);
	}
	for (char c : input)
	{
		if (!isdigit(c))
		{
			is_digits = false;
			break;
		}
	}
	if (is_digits == false)
		return (0);
	i = std::stol(input);
	i *= sign;
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		return (0);
	return (VAL_INT);
}

static int check_float(std::string input)
{
	long double	i = 0;
	bool		is_digits = true;
	int			sign = 1;
	int			dot = 0;

	if (input[input.size() - 1] != 'f')
		return (0);
	else
		input = input.substr(0, input.size() - 1);
	if (input[0] == '+' || input[0] == '-')
	{
		if (input[0] == '-')
			sign = -1;
		input = input.substr(1);
	}
	for (char c : input)
	{
		if (!isdigit(c) && c != '.')
		{
			is_digits = false;
			break;
		}
		if (c == '.')
			dot++;
	}
	if (is_digits == false || dot != 1)
		return (0);
	i = std::stof(input);
	i *= sign;
	if (i < std::numeric_limits<float>::min() || i > std::numeric_limits<float>::max())
		return (0);
	return (VAL_FLOAT);	
}

static int check_double(std::string input)
{
	long double	i = 0;
	bool		is_digits = true;
	int			sign = 1;
	int			dot = 0;

	if (input[0] == '+' || input[0] == '-')
	{
		if (input[0] == '-')
			sign = -1;
		input = input.substr(1);
	}
	for (char c : input)
	{
		if (!isdigit(c) && c != '.')
		{
			is_digits = false;
			break;
		}
		if (c == '.')
			dot++;
	}
	if (is_digits == false || dot != 1)
		return (0);
	i = std::strtod(input, NULL);
	if (errno == ERANGE)
		return (0);
	i *= sign;
	if (i < std::numeric_limits<double>::min() || i > std::numeric_limits<double>::max())
		return (0);
	return (VAL_DOUBLE);
}

static int check_type(std::string input)
{
	if (check_char(input))
		return (VAL_CHAR);
	else if (check_int(input))
		return (VAL_INT);
	else if (check_float(input))
		return (VAL_FLOAT);
	else if (check_double(input))
		return (VAL_DOUBLE);
	else
		return (0);
}

void ScalarConverter::convert(std::string input)
{
	int	type = 0;
	int	val = 0;

	if (check_psuedo(input))
		return ;
	type = check_type(input);
	switch (type)
	{
	case VAL_CHAR:
		val = std::atoi(input.c_str());
		break;
	case VAL_INT:
		val = std::atoi(input.c_str());
		break;
	case VAL_FLOAT:
		val = std::strtof(input.c_str(), NULL);
		break;
	case VAL_DOUBLE:
		val = std::strtod(input.c_str(), NULL);
		break;
	default:
		break;
	}
}
