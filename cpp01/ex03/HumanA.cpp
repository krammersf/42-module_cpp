/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:57:29 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 10:34:26 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::string nColor = "\033[1;33m";
	std::string resetColor = "\033[0m";

	std::cout << this->_name << nColor << " attacks with their " << resetColor << this->_weapon.getType() << std::endl;
}
