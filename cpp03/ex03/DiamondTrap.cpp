/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:47:46 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/11 15:23:26 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DiamondTrap::DiamondTrap(void)
{
	std::cout << BG_GREEN_BLACK <<"DiamondTrap default constructor called" << RESET << std::endl;
	this->_name = "DEFAULT";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string const diamondName) : ClapTrap(diamondName), ScavTrap(diamondName), FragTrap(diamondName)
{
	std::cout << BG_GREEN_BLACK <<"DiamondTrap constructor with parameter called" << RESET << std::endl;
	this->_name = diamondName;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << BG_GREEN_BLACK << "DiamondTrap copy constructor called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << BG_RED_BLACK <<"DiamondTrap destructor called" << RESET << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DiamondTrap    &DiamondTrap::operator=(DiamondTrap const &copy)
{
	std::cout << BG_GREEN_BLACK << "DiamondTrap copy assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackDamage = copy.getAttackDamage();
		this->ClapTrap::_name = copy.ClapTrap::_name;
	}
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void	DiamondTrap::whoAmI()
{
	std::cout << BG_DARK_GRAY << "My name is [" << this->_name << "] and I'm a DiamondTrap.";
	std::cout << " My ClapTrap name is [" << ClapTrap::_name << "]"<< RESET << std::endl;
}
