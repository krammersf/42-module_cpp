/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:23:39 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:37 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _Name(name){}

Zombie::~Zombie(void)
{
	std::cout << this->_Name << " is dead." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
