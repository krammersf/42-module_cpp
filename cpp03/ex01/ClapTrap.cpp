/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:09:03 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/22 09:29:46 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ClapTrap::ClapTrap(void)
{
	std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
	this->_name = "DEFAULT";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GREEN << "ClapTrap constructor with parameter called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << GREEN << "ClapTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "ClapTrap destructor called" << RESET << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ClapTrap	&ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << GREEN << "ClapTrap copy assignation constructor called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_attackDamage = copy.getAttackDamage();
		this->_energyPoints = copy.getEnergyPoints();
	}	
	return (*this);	
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap:: getHitPoints(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void	ClapTrap::setName(const std::string &name)
{
	this->_name = name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << "[" << this->_name << "] " << " is out of energy and is out of action!!!" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << "[" << this->_name << "] " << " is already " << RED << "DEAD" << RESET << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << "[" << this->_name << "] attacks [" << target << "]" <<std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "[" << this->_name << "] " << "is already " << RED << "DEAD" << RESET << std::endl;
		return ;
	}
	if (amount >= (unsigned int)this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "[" << this->_name << "]" << " took " << amount << " points of damage!" << std::endl;
		std::cout << "[" << this->_name << "] " << "is " << RED << "DEAD" << RESET << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "[" << this->_name << "] takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[" << this->_name << "] is repaired by " << amount << " points!" << std::endl;
	if (this->_hitPoints == 0)
	{
		std::cout << "[" << this->_name << "] " << "can not be reapaired becouse is " << RED << "DEAD" << RESET << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "[" << this->_name << "] : " << "I have no energy to repair myself!" << std::endl;
		return ;
	}

	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void	ClapTrap::displayInfo(void)
{
	std::cout << "[" << this->_name << "]" << std::endl;
	std::cout << "Health (hit points)   : " << this->_hitPoints << std::endl;
	std::cout << "Energy (energy points): " << this->_energyPoints << std::endl;
	std::cout << "Attack damage         : " << this->_attackDamage << std::endl;	
}
