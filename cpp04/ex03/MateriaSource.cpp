/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:31:02 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/12 09:54:49 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	*this = copy;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
			if (copy._materias[i])
				this->_materias[i] = copy._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Invalid materia to learn." << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			std::cout << m->getType() << " was learned!" << std::endl;
			return ;
		}
	}
	std::cout << "Source is full. Materia of type " << m->getType() << " can't be learned." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			std::cout << type << " created." << std::endl;
			return (this->_materias[i]->clone());
		}
	}
	std::cout << type << " not found" << std::endl;
	return (NULL);
}
