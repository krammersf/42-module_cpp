/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:30:59 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/12 09:55:08 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];
	
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		~MateriaSource();

		MateriaSource &operator=(MateriaSource const &copy);

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif
