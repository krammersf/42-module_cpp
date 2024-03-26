/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:16:08 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/20 15:49:36 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Fixed::Fixed() : _Value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) : _Value(copy._Value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const value) : _Value(value * 1 << Fixed::_fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _Value(roundf(value * (1 << Fixed::_fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Fixed &Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_Value = copy.getRawBits();
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SET // GET ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int	Fixed::getRawBits(void) const
{
	return (this->_Value);
}

void Fixed::setRawBits(int const raw)
{
	this->_Value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_Value / (float)(1 << Fixed::_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_Value / (1 << Fixed::_fractionalBits));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATOR << ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::ostream &operator<<(std::ostream &output, Fixed const &copy)
{
	output << copy.toFloat();
	return (output);
}
