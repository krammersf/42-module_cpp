/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:18 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/25 09:55:46 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
--> This code defines a [`ScavTrap`] class that inherits from the `ClapTrap` class using virtual inheritance.
	Virtual inheritance is a technique used in C++ to prevent multiple "instances" of a given class appearing
	in an inheritance hierarchy when using multiple inheritances.
*/

class ScavTrap : public ClapTrap
{
	//private:

	public:
		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &copy);
		~ScavTrap(void);

		// Operators
		ScavTrap    &operator=(ScavTrap const &copy);

		// Member functions
		void    attack(const std::string& target);
		void    guardGate(void);
};

#endif
