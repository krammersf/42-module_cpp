/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/22 09:43:05 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "|                         ScavTrap GAME                      |" << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << std::endl;
		std::cout << "Press any key to continue..." << std::endl;
		std::cin.get();
		std::cout << std::endl;

		ScavTrap player_4;
		std::cout << std::endl << YELLOW;
		player_4.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		ScavTrap player_5("RODRIGO");
		std::cout << std::endl << CYAN;
		player_5.displayInfo();
		std::cout << std::endl;
		ScavTrap player_6(player_5);
		std::cout << "A copy " << CYAN << "[" << player_5.getName() << "]" << RESET;
		std::cout << " has been made " << "--> " << BLUE "[*COPY*_";
		std::cout << player_5.getName() << "]" << RESET << std::endl;
		std::string player_5_name = player_5.getName();
		player_6.setName("*COPY*_" + player_5_name);
		std::cout << std::endl << BLUE;
		player_6.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_5.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_4.takeDamage(20);
		std::cout << RESET << std::endl << CYAN;
		player_5.displayInfo();
		std::cout << std::endl << YELLOW;
		player_4.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_5.beRepaired(0);
		std::cout << RESET << YELLOW;
		player_4.beRepaired(5);
		std::cout << RESET << std::endl << CYAN;
		player_5.displayInfo();
		std::cout << std::endl << YELLOW;
		player_4.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << CYAN;
		player_5.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_4.takeDamage(90);
		std::cout << RESET << std::endl << CYAN;
		player_5.displayInfo();
		std::cout << std::endl << YELLOW;
		player_4.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << BLUE;
		player_6.attack("DEFAULT");
		std::cout << RESET << YELLOW;
		player_4.takeDamage(8);
		std::cout << RESET << std::endl << CYAN;
		player_5.displayInfo();
		std::cout << RESET << std::endl << BLUE;
		player_6.displayInfo();
		std::cout << RESET << std::endl << YELLOW;
		player_4.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << BLUE;
		player_6.displayInfo();
		std::cout << RESET << std::endl;
		std::cout << "Now " << BLUE << "[" << player_6.getName() << "]" << RESET << " will be replaced \nby ";
		std::cout << YELLOW << "[" << player_4.getName() << "]" << RESET <<"'s copy --> ";
		std::cout << MAGENTA "[*COPY*_" << player_4.getName() << "]" << RESET << std::endl;
		player_6 = player_4;
		std::string player_4_name = player_4.getName();
		player_6.setName("*COPY*_" + player_4_name);
		std::cout << std::endl << MAGENTA;
		player_6.displayInfo();
		std::cout << RESET;
		std::cout << std::endl << YELLOW;
		player_4.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		player_4.guardGate();
		player_5.guardGate();
		player_6.guardGate();
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		std::cout << MAGENTA;
		player_6.displayInfo();
		std::cout << RESET << std::endl;
		std::cout << "Now " << MAGENTA << "[" << player_6.getName() << "]" << RESET << " will be replaced \nby ";
		std::cout << CYAN << "[" << player_5.getName() << "]" << RESET << "'s copy --> ";
		std::cout << BLUE << "[*COPY*_" << player_5.getName() << "]" << RESET << std::endl;
		player_6 = player_5;
		//std::string player_4_name = player_4.getName();
		player_6.setName("*COPY*_" + player_5_name);
		std::cout << std::endl << BLUE;
		player_6.displayInfo();
		std::cout << RESET;
		std::cout << std::endl << CYAN;
		player_5.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
		player_4.guardGate();
		player_5.guardGate();
		player_6.guardGate();;
		std::cin.get();
		
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;

		std::cout << YELLOW;
		player_4.displayInfo();
		std::cout << std::endl;
		ClapTrap player_3("JORGE");
		std::cout << "Now " << "[" << player_3.getName() << "]" << RESET << " was created." << std::endl;
		std::cout << std::endl;
		player_3.displayInfo();
		std::cout << RESET;
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;

		player_3.attack("DEFAULT");
		std::cout << YELLOW;
		player_4.takeDamage(5);
		std::cout << "\n" << YELLOW;
		player_4.displayInfo();
		std::cout << "\n" << RESET;
		player_3.displayInfo();
		std::cin.get();

		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
