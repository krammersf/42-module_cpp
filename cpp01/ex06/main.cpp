/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/19 11:00:05 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl;
	std::string	levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	level = -1;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter [LEVEL] -->"; 
		std::cout << " <DEBUG> <INFO> <WARNING> <ERROR>" << std::endl;
		return (1);
	}

	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		if (levels[i] == av[1])
			level = i;
	while (level < 4)
	{
		switch (level)
		{
			default:
				std::cout << "[ \033[1;31mProbably complaining about insignificant problems\033[0m ]\n" << std::endl;
				break;
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				harl.complain("debug");
				std::cout << std::endl;
				break;
			case 1:
				std::cout << "[ INFO ]" << std::endl;
				harl.complain("info");
				std::cout << std::endl;
				break;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;
				harl.complain("warning");
				std::cout << std::endl;
				break;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;
				harl.complain("error");
				std::cout << std::endl << std::endl;
				break;
		}
		if (level == 3 || level == -1)
			break;
		else
		{
			level++;
			std::cout << std::endl;	
		}
	}
}
