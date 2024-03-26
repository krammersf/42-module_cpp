/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:23:39 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 10:21:36 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Zombie::Zombie();

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _Name(name){}

Zombie::~Zombie()
{
	std::cout << this->_Name << " is dead." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::getName(std::string name)
{
	this->_Name = name;
}
