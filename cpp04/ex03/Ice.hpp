/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:25:59 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/12 09:52:51 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// constructors and destructor
		Ice();
		Ice(Ice const &copy);
		virtual ~Ice();

		// assigned operator
		Ice &operator=(Ice const &copy);

		// member functions
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif
