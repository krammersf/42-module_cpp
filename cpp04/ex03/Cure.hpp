/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:25:53 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/12 09:52:27 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// constructors and destructor
		Cure();
		Cure(Cure const & copy);
		virtual ~Cure();

		// assigned operator
		Cure & operator=(Cure const & copy);

		// member functions
		AMateria* clone() const;
		void use(ICharacter & target);
};

#endif
