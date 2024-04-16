/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/10 09:36:22 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void titleHeader(const std::string& message)
{
	std::cout << "\033c";
	int standartSize = 60;
	int messageSize = message.length();
	int spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	int spacesAfter = (standartSize - messageSize) / 2 + 1 + messageSize % 2;

	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET_BG << std::endl;
	std::cout << BG_BLUE << "|" << std::setw(spacesBefore) << message << RESET_BG;
	std::cout << BG_BLUE << std::setw(spacesAfter) << "|" << RESET_BG << std::endl;
	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET_BG << std::endl;

}

void	subTitle1(const std::string& message)
{
	std::cout << YELLOW << ">>> " << message << RESET;
}

void	subTitle2(const std::string& message)
{
	std::cout << WHITE << "[" << GREEN << message << WHITE << "]" << RESET << "\n" << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "\n" << RED << "Error: " << RESET << "Invalid number of arguments. ";
		std::cerr << "\n" << MAGENTA << "Usage: " << RESET << "./scalarconverter <input>" << "\n" << std::endl;
		return (1);
	}

	titleHeader("Scalar Converter");

	if(av[1][0] == '\0')
	{
		std::cerr << "\n" << RED<< "Error: " << RESET << "Empty string." << std::endl;
		std::cerr << MAGENTA << "Usage: " << RESET << "./scalarconverter <input>" << "\n" << std::endl; 
		return (1);
	}

	std::cout << std::endl;
	subTitle1("Input: ");
	subTitle2(av[1]);

	ScalarConverter::convert(av[1]);
	std::cout << std::endl;

	return (0);
}

/* // expected output

	./convert 0
	char: Non displayable
	int: 0
	float: 0.0f
	double: 0.0
	
	./convert nan
	char: impossible
	int: impossible
	float: nanf
	double: nan
	
	./convert 42.0f
	char: '*'
	int: 42
	float: 42.0f
	double: 42.0
*/
