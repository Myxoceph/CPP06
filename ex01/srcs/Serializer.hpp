/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:53 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/12 15:21:55 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

typedef struct s_data
{
	std::string str;
	int			num;
}	Data;

class Serializer
{
	private:
			Serializer();
			Serializer(Serializer const &copy);
			Serializer &operator=(Serializer const &copy);
			~Serializer();
	public:
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
};


#endif
