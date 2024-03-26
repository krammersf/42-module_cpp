/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/19 10:55:14 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	readInput(std::string str)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\n\nError: reading getline\n";
			exit(1);
		}
	}
	return (input);
}

bool	is_number(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

int	main(void)
{
	std::string	input;
	int			num;
	std::string zombieName;
	Zombie *horde;

	std::cout << "\033c";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "     Welcome to the Zombie Factory!" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	while(1)
	{
		input = readInput("Enter the number of zombies: ");
		if(is_number(input))
		{
			num = std::atoi(input.c_str());
			if (num > 0)
				break;
			else
			{
				std::cout << "Invalid number!\nPress ENTER to continue and try again.." << std::endl;
				std::cin.clear();
				std::cin.get();
			}
		}
		else
		{
			std::cout << "Invalid number!\nPress ENTER to continue and try again.." << std::endl;
			std::cin.clear();
			std::cin.get();
		}
	}
	std::cout << "Now enter a name to the zombie: ";
	getline(std::cin, zombieName);
	std::cout << std::endl;
	horde = zombieHorde(num, zombieName);
	for (int i = 0; i < num; i++)
		horde[i].announce();
	delete[] horde;
	std::cout << std::endl;
	return (0);
}
