/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:13:11 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/21 15:34:44 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iomanip> // setw()

# define GREY "\033[1;30m"
# define YELLOW "\033[1;33m"
# define YELLOW1 "\033[0;33m"
# define GREEN "\033[1;32m"
# define GREEN1 "\033[0;32m"
# define RED "\033[1;31m"
# define RED1 "\033[0;31m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET "\033[0m"
# define SBLINK	"\033[5m"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		Point();
		Point(Point const &copy);
		Point(float const x, float const y);
		~Point();

		Point &operator=(Point const &copy);

		Fixed	getX() const;
		Fixed	getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

# endif
