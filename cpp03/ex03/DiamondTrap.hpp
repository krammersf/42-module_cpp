/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:47:42 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/25 09:56:41 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/*
--> Because `ScavTrap` and `FragTrap` both inherit from `ClapTrap`, and `DiamondTrap` inherits
  from both `ScavTrap` and `FragTrap`, the `DiamondTrap` class will have two instances of the
  `ClapTrap` class in its inheritance hierarchy.
  This is because `ScavTrap` and `FragTrap` both inherit from `ClapTrap` using virtual inheritance,
  but `DiamondTrap` does not.
*/

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &copy);
		~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap const &copy);

		void whoAmI();
		using ScavTrap::attack;
};

#endif
