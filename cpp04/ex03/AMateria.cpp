/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:21:28 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/21 09:42:06 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy) //: _type(copy._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AMateria& AMateria::operator=(const AMateria& copy)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::string const & AMateria::getType() const
{
	return (this->_type);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void AMateria::use(ICharacter& target)
{
	(void)target;
}
