/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/19 10:41:57 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string chumpName;
	std::string zombieName;
	Zombie *zombie;

	std::cout << std::endl;
	std::cout << "Now enter a name to the zombie: " << std::endl;
	getline(std::cin, zombieName);
	std::cout << "Enter a name to the chump: " << std::endl;
	getline(std::cin, chumpName);

	zombie = newZombie(zombieName); 
	std::cout << std::endl;
	zombie->announce();
	randomChump(chumpName);
	delete zombie;
	std::cout << std::endl;
	return (0);
}
