/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/22 10:08:50 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	{
		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "|                         DiamondTrap GAME                      |" << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << std::endl;
		std::cout << "Press any key to continue..." << std::endl;
		std::cin.get();
		std::cout << std::endl;

		DiamondTrap player_88;
		std::cout << std::endl << YELLOW;
		player_88.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		DiamondTrap player_99("MARIA");
		std::cout << std::endl << CYAN;
		player_99.displayInfo();
		std::cout << std::endl;
		DiamondTrap player_100(player_99);
		std::cout << "A copy " << CYAN << "[" << player_99.getName() << "]" << RESET;
		std::cout << " has been made." << std::endl << "--> " << BLUE "[*COPY*_";
		std::cout << player_99.getName() << "]" << RESET << std::endl;
		std::string player_99_name = player_99.getName();
		player_100.setName("*COPY*_" + player_99_name);
		std::cout << std::endl << BLUE;
		player_100.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_99.attack("DEFAULT_clap_name");
		std::cout << RESET << YELLOW;
		player_88.takeDamage(30);
		std::cout << RESET << std::endl << CYAN;
		player_99.displayInfo();
		std::cout << std::endl << YELLOW;
		player_88.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_99.beRepaired(0);
		std::cout << RESET << YELLOW;
		player_88.beRepaired(5);
		std::cout << RESET << std::endl << CYAN;
		player_99.displayInfo();
		std::cout << std::endl << YELLOW;
		player_88.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_99.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_88.takeDamage(90);
		std::cout << RESET << std::endl << CYAN;
		player_99.displayInfo();
		std::cout << std::endl << YELLOW;
		player_88.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << BLUE;
		player_100.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_88.takeDamage(8);
		std::cout << RESET << std::endl << CYAN;
		player_99.displayInfo();
		std::cout << RESET << std::endl << BLUE;
		player_100.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_88.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << BLUE;
		player_100.displayInfo();
		std::cout << RESET << std::endl;
		std::cout << "Now " << BLUE << "[" << player_100.getName() << "]" << RESET << " will be replaced \nby ";
		std::cout << YELLOW << "[" << player_88.getName() << "]" << RESET <<"'s copy --> ";
		std::cout << MAGENTA "[*COPY*_" << player_88.getName() << "]" << RESET << std::endl;
		player_100 = player_88;
		std::string player_88_name = player_88.getName();
		player_100.setName("*COPY*_" + player_88_name);
		std::cout << std::endl << MAGENTA;
		player_100.displayInfo();
		std::cout << RESET;
		std::cout << std::endl << YELLOW;
		player_88.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		player_88.guardGate();
		player_99.guardGate();
		player_100.guardGate();
		std::cout << std::endl;
		player_88.highFivesGuys();
		player_99.highFivesGuys();
		player_100.highFivesGuys();
		std::cout << std::endl;
		player_88.whoAmI();
		player_99.whoAmI();
		player_100.whoAmI();
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << MAGENTA;
		player_100.displayInfo();
		std::cout << RESET << std::endl;
		std::cout << "Now " << MAGENTA << "[" << player_100.getName() << "]" << RESET << " will be replaced \nby ";
		std::cout << CYAN << "[" << player_99.getName() << "]" << RESET << "'s copy --> ";
		std::cout << BLUE << "[*COPY*_" << player_99.getName() << "]" << RESET << std::endl;
		player_100 = player_99;
		player_100.setName("*COPY*_" + player_99_name);
		std::cout << std::endl << BLUE;
		player_100.displayInfo();
		std::cout << RESET;
		std::cout << std::endl << CYAN;
		player_99.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		player_88.guardGate();
		player_99.guardGate();
		player_100.guardGate();
		std::cout << std::endl;
		player_88.highFivesGuys();
		player_99.highFivesGuys();
		player_100.highFivesGuys();
		std::cout << std::endl;
		player_88.whoAmI();
		player_99.whoAmI();
		player_100.whoAmI();
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
