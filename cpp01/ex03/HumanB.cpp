/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:57:36 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/19 10:58:09 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	std::string nColor = "\033[1;33m";
	std::string resetColor = "\033[0m";
	
	if(this->_weapon)
		std::cout << this->_name << nColor <<" attacks with their " << resetColor << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << nColor << " has no weapon to attack with" << resetColor << std::endl;
}
