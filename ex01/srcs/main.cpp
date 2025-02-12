/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:44 by abakirca          #+#    #+#             */
/*   Updated: 2025/02/12 15:48:59 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data someData;
	Data *ptr;
	uintptr_t raw;
	someData.str = "abakirca";
	someData.num = 42;

	std::cout << BLUE"========================================"RESET << std::endl;
	std::cout << GREEN"The values of the struct before serialization :"RESET << std::endl;
	std::cout << CYAN"Data's address: "WHITE << &someData << RESET << std::endl;
	std::cout << CYAN"String: "WHITE << someData.str << RESET << std::endl;
	std::cout << CYAN"Number: "WHITE << someData.num << RESET << std::endl;
	std::cout << BLUE"========================================"RESET << std::endl;
	raw = Serializer::serialize(&someData);
	std::cout << GREEN"The raw value after serialization :"RESET << std::endl;
	std::cout << CYAN"Raw: "WHITE << raw << RESET << std::endl;
	std::cout << BLUE"========================================"RESET << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << GREEN"The values of the struct after deserialization :"RESET << std::endl;
	std::cout << CYAN"Data's address: "WHITE << ptr << RESET << std::endl;
	std::cout << CYAN"String: "WHITE << ptr->str << RESET << std::endl;
	std::cout << CYAN"Number: "WHITE << ptr->num << RESET << std::endl;
	std::cout << BLUE"========================================"RESET << std::endl;
	std::cout << GREEN"Conclusion :"RESET << std::endl;
	std::cout << CYAN"Preserialize Data's address:	"WHITE << &someData << RESET << std::endl;
	std::cout << CYAN"Postserialize Data's address:	"WHITE << ptr << RESET << std::endl;
	std::cout << BLUE"========================================"RESET << std::endl;
	
	return 0;
}
