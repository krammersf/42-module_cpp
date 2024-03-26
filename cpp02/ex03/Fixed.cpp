/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:16:08 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/11 11:27:44 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Fixed::Fixed() : _Value(0) {}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(int const value)
{
	this->_Value = value * (1 << Fixed::_fractionalBits);
}

Fixed::Fixed(float const value)
{
	this->_Value = roundf(value * (1 << Fixed::_fractionalBits));
}

Fixed::~Fixed() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~ ARITHEMETIC  OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~

Fixed &Fixed::operator=(Fixed const &copy)
{
	if (this != &copy)
		this->_Value = copy.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const &copy) const
{
	return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed Fixed::operator-(Fixed const &copy) const
{
	return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed Fixed::operator*(Fixed const &copy) const
{
	return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed Fixed::operator/(Fixed const &copy) const
{
	return (Fixed(this->toFloat() / copy.toFloat()));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ COMPARISON OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool Fixed::operator>(Fixed const &copy) const
{
	return (this->getRawBits() > copy.getRawBits());
}

bool Fixed::operator>=(Fixed const &copy) const
{
	return (this->getRawBits() >= copy.getRawBits());
}

bool Fixed::operator<(Fixed const &copy) const
{
	return (this->getRawBits() < copy.getRawBits());
}

bool Fixed::operator<=(Fixed const &copy) const
{
	return (this->getRawBits() <= copy.getRawBits());
}

bool Fixed::operator==(Fixed const &copy) const
{
	return (this->getRawBits() == copy.getRawBits());
}

bool Fixed::operator!=(Fixed const &copy) const
{
	return (this->getRawBits() != copy.getRawBits());
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ INCREMENT  OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~

Fixed Fixed::operator++(void)
{
	this->_Value++;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->_Value--;
	return (*this);
}

Fixed Fixed::operator++(int temp)
{
	(void)temp;
	Fixed duplicate(*this);
	++(*this);
	return (duplicate);
}

Fixed Fixed::operator--(int temp)
{
	(void)temp;
	Fixed duplicate(*this);
	--(*this);
	return (duplicate);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAX / MIN  FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);

}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TO FLOAT // TO INT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

float	Fixed::toFloat(void) const
{
	return ((float)this->_Value / (float)(1 << Fixed::_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_Value / (1 << Fixed::_fractionalBits));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATOR << ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return (out);
}
