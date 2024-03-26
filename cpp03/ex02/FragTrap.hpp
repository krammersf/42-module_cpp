/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:17:15 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/11 14:57:42 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	//private:

	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const &copy);
		~FragTrap(void);

		// Operators
		FragTrap	&operator=(FragTrap const &copy);

		// Member functions
		void	highFivesGuys(void);
};

#endif
