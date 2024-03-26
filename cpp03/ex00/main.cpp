/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/22 08:58:01 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	{
		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "|                         ClapTrap GAME                      |" << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << std::endl;
		std::cout << "Press any key to continue..." << std::endl;
		std::cin.get();
		std::cout << std::endl;
		ClapTrap player_2("FRED");
		ClapTrap player_1;
		std::cout << std::endl;

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << YELLOW;
		player_1.attack("FRED");
		std::cout << RESET << CYAN;
		player_2.takeDamage(0);
		std::cout << RESET << std::endl << CYAN;
		player_2.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_1.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_2.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_1.takeDamage(05);
		std::cout << RESET << std::endl << CYAN;
		player_2.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_1.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << YELLOW;
		player_1.attack("FRED");
		std::cout << RESET << CYAN;
		player_2.takeDamage(3);
		std::cout << RESET << std::endl << CYAN;
		player_2.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_1.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_2.beRepaired(0);
		std::cout << RESET << YELLOW;
		player_1.beRepaired(1);
		std::cout << RESET << std::endl << CYAN;
		player_2.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_1.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_2.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_1.takeDamage(8);
		std::cout << RESET << std::endl << CYAN;
		player_2.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_1.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		ClapTrap* player_3 = new ClapTrap(player_2);
		std::cout << "A deep copy of ClapTrap [" << player_2.getName() << "] has been made..." << std::endl;
		std::cout << RESET;
		std::cout << std::endl;
		std::string player_2_name = player_2.getName();
		player_3->setName("*COPY*_" + player_2_name);
		std::cout << BLUE;
		player_3->attack("DEFAULT");
		std::cout << YELLOW;
		player_1.takeDamage(8);
		std::cout << RESET << std::endl << CYAN;
		player_2.displayInfo();
		std::cout << RESET << std::endl << BLUE;
		player_3->displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_1.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		delete player_3;
	}
	std::cout << std::endl;
	return (0);
}
