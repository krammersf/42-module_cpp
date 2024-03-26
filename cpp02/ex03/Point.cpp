/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:13:07 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/25 11:18:40 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(Point const &copy) : _x(copy.getX()), _y(copy.getY()) {};

Point::Point(float const x, float const y) : _x(x), _y(y) {};

Point::~Point() {}

Point &Point::operator=(Point const &copy)
{
	if (this != &copy)
	{
		(Fixed)this->_x = copy.getX();
		(Fixed)this->_y = copy.getY();
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (Fixed(this->_x));
}

Fixed Point::getY() const
{
	return (Fixed(this->_y));
}
