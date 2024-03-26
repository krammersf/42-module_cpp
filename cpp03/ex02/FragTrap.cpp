/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:17:20 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/11 14:57:29 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

FragTrap::FragTrap(void)
{
	std::cout << BG_GREEN <<"FragTrap default constructor called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << BG_GREEN <<"FragTrap constructor with parameter called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << BG_GREEN << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << BG_RED <<"FragTrap destructor called" << RESET << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

FragTrap    &FragTrap::operator=(FragTrap const &copy3)
{
	std::cout << GREEN1 <<"FragTrap copy assignation operator called" << RESET << std::endl;
	if (this != &copy3)
	{
		this->_name = copy3.getName();
		this->_hitPoints = copy3.getHitPoints();
		this->_energyPoints = copy3.getEnergyPoints();
		this->_attackDamage = copy3.getAttackDamage();
	}
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void	FragTrap::highFivesGuys()
{
	std::cout << BG_BLUE << "[" << this->_name << "] gives a HIGH FIVE." << RESET << std::endl;
}
