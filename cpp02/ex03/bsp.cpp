/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:12:54 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/25 11:17:29 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool isOverTheEdge(const Point p1, const Point p2, const Point p)
{
	Fixed slope((p1.getY() - p2.getY()) / (p1.getX() - p2.getX()));
	Fixed intercept(p1.getY() - slope * p1.getX());

	if(p.getY() != slope * p.getX() + intercept)
		return (false);

	return(true);
}

float getTriangleArea(const Point p1, const Point p2, const Point p3)
{
	Fixed first(p1.getX() * p2.getY() - p3.getX() * p2.getY());
	Fixed second(p3.getX() * p1.getY() - p1.getX() * p3.getY());
	Fixed third(p2.getX() * p3.getY() - p2.getX() * p1.getY());
	Fixed result(first + second + third);

	return (std::abs(result.toFloat()) / 2);
}

bool checkEqualPoints(const Point p1, const Point p2)
{
	Fixed aX(p1.getX());
	Fixed aY(p1.getY());
	Fixed bX(p2.getX());
	Fixed bY(p2.getY());

	if(aX == bX && aY == bY)
		return (true);

	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if(isOverTheEdge(a, b, point) || isOverTheEdge(b, c, point) || isOverTheEdge(c, a, point))
		return (false);

	if(checkEqualPoints(a, b) || checkEqualPoints(b, c) || checkEqualPoints(c, a))
		return (false);

	float areaABC = getTriangleArea(a, b, c);
	float subABP = getTriangleArea(a, b, point);
	float subBCP = getTriangleArea(b, c, point);
	float subCAP = getTriangleArea(c, a, point);

	if(areaABC != subABP + subBCP + subCAP)
		return (false);

	return (true);
}
