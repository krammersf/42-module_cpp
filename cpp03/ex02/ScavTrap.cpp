/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:23 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/11 14:58:28 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ScavTrap::ScavTrap(void)
{
	std::cout << GREEN1 <<"ScavTrap default constructor called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	std::cout << GREEN1 <<"ScavTrap constructor with parameter called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << GREEN1 << "ScavTrap copy constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED1 <<"ScavTrap destructor called" << RESET << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ScavTrap    &ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << GREEN1 <<"ScavTrap copy assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackDamage = copy.getAttackDamage();
	}
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "[" << this->_name << "] " << " is out of energy and is out of action!!!" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "[" << this->_name << "] " << " is already " << RED << "DEAD" << RESET << std::endl;
		return ;
	}
	std::cout << "[" << this->_name << "] attacks [" << target << "]" << std::endl;
	this->_energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	std::cout << BG_MAGENTA << "[" << this->_name << "] is enter in Gate keeper mode." << RESET << std::endl;
}
