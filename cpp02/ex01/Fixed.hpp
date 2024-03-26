/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:16:04 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/20 15:29:56 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		static const int	_fractionalBits = 8;
		int					_Value;
	
	public:
		// Constructors and Destructors
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(int const value);
		Fixed(float	const value);
		~Fixed();

		// Overload
		Fixed &operator=(Fixed const &copy);

		// Getters and Setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Member functions
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, Fixed const &copy);

#endif
