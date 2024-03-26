/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:23:43 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/20 09:34:02 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib> // --> atoi()

# define CLEAR "\033c"

class Zombie
{
	private:
		std::string	_Name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void announce( void );
		void getName(std::string name);
};

	Zombie* zombieHorde( int N, std::string name );

#endif
