/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/08 14:19:37 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void titleHeader(const std::string& message)
{
	std::cout << "\033c";
	int standartSize = 60;
	int messageSize = message.length();
	int spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	int spacesAfter = (standartSize - messageSize) / 2 + 1 + messageSize % 2;

	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << RESET_BG << std::endl;
	std::cout << BG_BLUE << "|" << std::setw(spacesBefore) << message << RESET_BG;
	std::cout << BG_BLUE << std::setw(spacesAfter) << "|" << RESET_BG << std::endl;
	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << RESET_BG << std::endl;
}

void	subTitle(const std::string& message)
{
	std::cout << YELLOW << ">>> " << message << RESET << std::endl;
}

int	main(void)
{
	titleHeader("Seralizer and Deserializer");
	std::cout << std::endl;

	subTitle("Data structure");
	Data	data;
	data.age = 44;
	data.FirstName = "Frederico";
	data.LastName = "Bajouco";
	data.FirstLetter = data.FirstName[0];

	std::cout << " Data address: " << &data << std::endl;
	std::cout << " Data age: " << data.age << std::endl;
	std::cout << " Data first name: " << data.FirstName << std::endl;
	std::cout << " Data last name: " << data.LastName << std::endl;
	std::cout << " Data first letter: " << data.FirstLetter << std::endl;
	std::cout << std::endl;

	subTitle("Serializing");
	uintptr_t	ptr = Serializer::serialize(&data);
	std::cout << " Serialized uintptr: " << ptr << std::endl;
	std::cout << std::endl;

	subTitle("Deserializing");
	Data	*convertion = Serializer::deserialize(ptr);
	std::cout << " Deserialized address: " << convertion << std::endl;
	std::cout << " Deserialized data age: " << convertion->age << std::endl;
	std::cout << " Deserialized data first name: " << convertion->FirstName << std::endl;
	std::cout << " Deserialized data last name: " << convertion->LastName << std::endl;
	std::cout << " Deserialized data first letter: " << convertion->FirstLetter << std::endl;
	std::cout << std::endl;

	subTitle("Final Result");
	std::string s0 = "data adresss";
	std::string s1 = "data age";
	std::string s2 = "data first name";
	std::string s3 = "data last name";
	std::string s4 = "data first letter";
	std::cout << " The " << MAGENTA << s0 << RESET << " and the " << CYAN << "deserialized ";
	std::cout << s0 << RESET << " are equal?";
	if (&data == Serializer::deserialize(ptr))
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << " The " << MAGENTA << s1 << RESET << " and the " << CYAN << "deserialized ";
	std::cout << s1 << RESET << " are equal?";
	if (data.age == Serializer::deserialize(ptr)->age)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << " The " << MAGENTA << s2 << RESET << " and the " << CYAN << "deserialized ";
	std::cout << s2 << RESET << " are equal?";
	if (data.FirstName == Serializer::deserialize(ptr)->FirstName)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;
	std::cout << " The " << MAGENTA << s3 << RESET << " and the " << CYAN << "deserialized ";
	std::cout << s3 << RESET << " are equal?";	
	if (data.LastName == Serializer::deserialize(ptr)->LastName)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;	
	std::cout << " The " << MAGENTA << s4 << RESET << " and the " << CYAN << "deserialized ";
	std::cout << s4 << RESET << " are equal?";
	if (data.FirstLetter == Serializer::deserialize(ptr)->FirstLetter)
		std::cout << GREEN << " Yes" <<  RESET << std::endl;
	else
		std::cout << RED << " No" <<  RESET << std::endl;

	// std::cout << std::endl;	// for testing the final result
	// std::cout << " The " << MAGENTA << s2 << RESET << " and the " << CYAN << "deserialized ";
	// std::cout << s3 << RESET << " are equal?";
	// if (data.FirstName == Serializer::deserialize(ptr)->LastName)
	// 	std::cout << GREEN << " Yes" <<  RESET << std::endl;
	// else
	// 	std::cout << RED << " No" <<  RESET << std::endl;

	std::cout << std::endl;
}
