/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:16:04 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/21 10:02:40 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int					_Value;
		static const int	_fractionalBits = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed &copy);

		Fixed &operator=(Fixed const &copy);

		int		getRawBits(void) const; // get raw value of the fixed point value
		void	setRawBits(int const raw); // set the raw value of the fixed point value
};

#endif

// https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html