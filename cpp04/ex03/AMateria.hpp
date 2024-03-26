/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:19:45 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/20 17:13:43 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		// constructors and destructor
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& ref);
		virtual ~AMateria();
		
		//assigned operator
		AMateria& operator=(const AMateria& copy);
		
		// get functions
		std::string const & getType() const;

		// member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
