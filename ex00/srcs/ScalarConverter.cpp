/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:24:27 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/11 17:25:46 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::predot = false;
bool ScalarConverter::postdot = false;
bool ScalarConverter::postzero = false;
bool ScalarConverter::int_overflow = false;

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

int ScalarConverter::check_psuedo(std::string input)
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

int ScalarConverter::check_char(std::string input)
{
	if (input.size() == 1 && !isdigit(input[0]))
		return (VAL_CHAR);
	else
		return (0);
}

int ScalarConverter::check_int(std::string input)
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
	for (int i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]))
		{
			is_digits = false;
			break;
		}
	}
	if (is_digits == false)
		return (0);
	i = strtol(input.c_str(), NULL, 10);
	i *= sign;
	if (input.size() > 11)
		int_overflow = true;
	else if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		int_overflow = true;
	return (VAL_INT);
}

int ScalarConverter::check_float(std::string input)
{
	float		i = 0;
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
	for (int i = 0; i < input[i]; i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
		{
			is_digits = false;
			break;
		}
		if (input[i] == '.')
			dot++;
	}
	if (is_digits == false || dot != 1)
		return (0);
	i = strtof(input.c_str(), NULL);
	i *= sign;
	if (input[0] == '.')
		predot = true;
	else if (input[input.size() - 1] == '.')
		postdot = true;
	if (input[input.size() - 1] == '0')
		postzero = true;
	return (VAL_FLOAT);	
}

int ScalarConverter::check_double(std::string input)
{
	double		i = 0;
	bool		is_digits = true;
	int			sign = 1;
	int			dot = 0;

	if (input[0] == '+' || input[0] == '-')
	{
		if (input[0] == '-')
			sign = -1;
		input = input.substr(1);
	}
	for (int i = 0; i < input[i]; i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
		{
			is_digits = false;
			break;
		}
		if (input[i] == '.')
			dot++;
	}
	if (is_digits == false || dot != 1)
		return (0);
	i = strtod(input.c_str(), NULL);
	i *= sign;
	if (input[0] == '.')
		predot = true;
	else if (input[input.size() - 1] == '.')
		postdot = true;
	if (input[input.size() - 1] == '0')
		postzero = true;
	return (VAL_DOUBLE);
}

int ScalarConverter::check_type(std::string input)
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

void	ScalarConverter::handle_input(char input)
{
	if (input >= 32 && input <= 126)
		std::cout << CHAR << "'" << static_cast<char>(input) << "'" << RESET << std::endl;
	else
		std::cout << CHAR << RED"Non displayable"RESET << std::endl;
	std::cout << INT << static_cast<int>(input) << RESET << std::endl;
	std::cout << FLOAT << static_cast<float>(input) << ".0f" << RESET << std::endl;
	std::cout << DOUBLE << static_cast<double>(input) << ".0" << RESET << std::endl;
}

void	ScalarConverter::handle_input(int input)
{
	if (!int_overflow && (input >= 32 && input <= 126))
		std::cout << CHAR << "'" << static_cast<char>(input) << "'" << RESET << std::endl;
	else
		std::cout << CHAR << RED"Non displayable"RESET << std::endl;
	if (int_overflow)
	{
		std::cout << INT << RED"impossible"RESET << std::endl;
		std::cout << FLOAT << RED"cannot be cast what is overflowed"RESET << std::endl;
		std::cout << DOUBLE << RED"cannot be cast what is overflowed"RESET << std::endl;
		return ;
	}
	else
		std::cout << INT << input << RESET << std::endl;
	std::cout << FLOAT << static_cast<float>(input) << ".0f" << RESET << std::endl;
	std::cout << DOUBLE << static_cast<double>(input) << ".0" << RESET << std::endl;
}

void	ScalarConverter::handle_input(float input)
{
	if (input >= 32 && input <= 126)
		std::cout << CHAR << "'" << static_cast<char>(input) << "'" << RESET << std::endl;
	else
		std::cout << CHAR << RED"Non displayable"RESET << std::endl;
	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
		std::cout << INT << RED"impossible"RESET << std::endl;
	else
		std::cout << INT << static_cast<int>(input) << RESET << std::endl;
	if (postdot || postzero)
		std::cout << FLOAT << input << ".0f" << RESET << std::endl;
	else
		std::cout << FLOAT << input << "f" << RESET << std::endl;
	if (postdot || postzero)
		std::cout << DOUBLE << input << ".0" << RESET << std::endl;
	else
		std::cout << DOUBLE << static_cast<double>(input) << RESET << std::endl;
}

void	ScalarConverter::handle_input(double input)
{
	if (input >= 32 && input <= 126)
		std::cout << CHAR << "'" << static_cast<char>(input) << "'" << RESET << std::endl;
	else
		std::cout << CHAR << RED"Non displayable"RESET << std::endl;
	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
		std::cout << INT << RED"impossible"RESET << std::endl;
	else
		std::cout << INT << static_cast<int>(input) << RESET << std::endl;
	if (postdot || postzero)
		std::cout << FLOAT << static_cast<float>(input) << ".0f" << RESET << std::endl;
	else
		std::cout << FLOAT << input << "f" << RESET << std::endl;
	if (postdot || postzero)
		std::cout << DOUBLE << input << ".0" << RESET << std::endl;
	else
		std::cout << DOUBLE << input << RESET << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	int		type = 0;
	char	_char = 0;
	int		_int = 0;
	float	_float = 0;
	double	_double = 0;

	if (check_psuedo(input))
		return ;
	type = check_type(input);
	switch (type)
	{
	case VAL_CHAR:
		_char = input[0];
		handle_input(_char);
		break;
	case VAL_INT:
		_int = atol(input.c_str());
		handle_input(_int);
		break;
	case VAL_FLOAT:
		_float = strtof(input.c_str(), NULL);
		handle_input(_float);
		break;
	case VAL_DOUBLE:
		_double = strtod(input.c_str(), NULL);
		handle_input(_double);
		break;
	default:
		std::cout << RED"Invalid Input."RESET << std::endl;
		break;
	}
}
