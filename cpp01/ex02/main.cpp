/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/19 10:55:54 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip> // --> setw()

int main(void)
{
	std::string nColor = "\033[1;33m";
	std::string resetColor = "\033[0m";

	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::endl;
	std::cout << "The memory address of the string variable" << std::setw(0) << ": " << nColor << &str << resetColor << std::endl;
	std::cout << "The memory address held by stringPTR" << std::setw(7) << ": " << nColor << stringPTR << resetColor << std::endl;
	std::cout << "The memory address held by stringREF" << std::setw(7) << ": " << nColor << &stringREF << resetColor << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable" << std::setw(3) << ": " << nColor << str << resetColor << std::endl;
	std::cout << "The value pointed to by stringPTR" << std::setw(0) << ": " << nColor << *stringPTR << resetColor << std::endl;
	std::cout << "The value pointed to by stringREF" << std::setw(0) << ": " << nColor << stringREF << resetColor << std::endl;
	std::cout << std::endl;

	return (0);
}
