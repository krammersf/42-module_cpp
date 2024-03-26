/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/22 09:48:04 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "|                         FragTrap GAME                      |" << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << std::endl;
		std::cout << "Press any key to continue..." << std::endl;
		std::cin.get();
		std::cout << std::endl;

		FragTrap player_8;
		std::cout << std::endl << YELLOW;
		player_8.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		FragTrap player_9("RODRIGO");
		std::cout << std::endl << CYAN;
		player_9.displayInfo();
		std::cout << std::endl;
		FragTrap player_10(player_9);
		std::cout << "A copy " << CYAN << "[" << player_9.getName() << "]" << RESET;
		std::cout << " has been made." << std::endl << "--> " << BLUE "[*COPY*_";
		std::cout << player_9.getName() << "]" << RESET << std::endl;
		std::string player_9_name = player_9.getName();
		player_10.setName("*COPY*_" + player_9_name);
		std::cout << std::endl << BLUE;
		player_10.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_9.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_8.takeDamage(30);
		std::cout << RESET << std::endl << CYAN;
		player_9.displayInfo();
		std::cout << std::endl << YELLOW;
		player_8.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_9.beRepaired(0);
		std::cout << RESET << YELLOW;
		player_8.beRepaired(5);
		std::cout << RESET << std::endl << CYAN;
		player_9.displayInfo();
		std::cout << std::endl << YELLOW;
		player_8.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_9.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_8.takeDamage(90);
		std::cout << RESET << std::endl << CYAN;
		player_9.displayInfo();
		std::cout << std::endl << YELLOW;
		player_8.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << BLUE;
		player_10.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_8.takeDamage(8);
		std::cout << RESET << std::endl << CYAN;
		player_9.displayInfo();
		std::cout << RESET << std::endl << BLUE;
		player_10.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_8.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << BLUE;
		player_10.displayInfo();
		std::cout << RESET << std::endl;
		std::cout << "Now " << BLUE << "[" << player_10.getName() << "]" << RESET << " will be replaced \nby ";
		std::cout << YELLOW << "[" << player_8.getName() << "]" << RESET <<"'s copy --> ";
		std::cout << MAGENTA "[*COPY*_" << player_8.getName() << "]" << RESET << std::endl;
		player_10 = player_8;
		std::string player_8_name = player_8.getName();
		player_10.setName("*COPY*_" + player_8_name);
		std::cout << std::endl << MAGENTA;
		player_10.displayInfo();
		std::cout << RESET;
		std::cout << std::endl << YELLOW;
		player_8.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		player_8.highFivesGuys();
		player_9.highFivesGuys();
		player_10.highFivesGuys();;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << MAGENTA;
		player_10.displayInfo();
		std::cout << RESET << std::endl;
		std::cout << "Now " << MAGENTA << "[" << player_10.getName() << "]" << RESET << " will be replaced \nby ";
		std::cout << CYAN << "[" << player_9.getName() << "]" << RESET << "'s copy --> ";
		std::cout << BLUE << "[*COPY*_" << player_9.getName() << "]" << RESET << std::endl;
		player_10 = player_9;
		player_10.setName("*COPY*_" + player_9_name);
		std::cout << std::endl << BLUE;
		player_10.displayInfo();
		std::cout << RESET;
		std::cout << std::endl << CYAN;
		player_9.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		player_8.highFivesGuys();
		player_9.highFivesGuys();
		player_10.highFivesGuys();;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
