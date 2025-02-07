/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:22:23 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/07 18:39:16 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

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
