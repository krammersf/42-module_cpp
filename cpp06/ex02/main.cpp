/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/08 14:50:34 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

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
	titleHeader("Dynamic Cast");
	std::cin.get();

	int arrayNumber = 7;

	std::cout << "==> " << GREEN << "Creating an array of " << arrayNumber;
	std::cout << " instances." << RESET;
	std::cout << std::endl;
	std::cin.get();

	std::srand(std::time(NULL));
	for (int i = 0; i < arrayNumber; i++)
	{
		if (i > 0)
			std::cout << std::endl;
		Base *base;
		base = generate();
		std::cout << " Base address" << std::setw(9) << ": " << base << std::endl;
		std::cout << " Base type POINTER" << std::setw(3) << ":";
		identify(base); // Pointer
		std::cout << " Base type REFERENCE" << std::setw(0) << ":";
		identify(*base); // Derferencing pointer -> Passing reference
		delete base;
	}
	std::cin.get();

	std::cout << "==> " << GREEN << "Creating an empty";
	std::cout << " instance." << RESET << std::endl;
	std::cin.get();

	std::cout << "Creating a new " << RED << "empty";
	std::cout << RESET << " instance." << std::endl;
	Base *emptyPointer = NULL;
	Base emptyClass;

	std::cout << " emptyPointer address" << std::setw(0) << ": " << &emptyPointer << std::endl;
	std::cout << " Base type" << std::setw(12) << ":";
	identify(emptyPointer);

	std::cout << " emptyClass address" << std::setw(4) << ": " << &emptyClass << std::endl;
	std::cout << " Base type" << std::setw(12) << ":";
	identify(emptyClass);
	std::cout << std::endl;
}
