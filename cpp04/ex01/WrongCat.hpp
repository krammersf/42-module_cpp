/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:02:38 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/24 14:15:29 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// constructors and destructor
		WrongCat();
		WrongCat(const WrongCat &copy);
		virtual ~WrongCat();

		// assigned operator
		WrongCat &operator=(const WrongCat &copy);

		// member functions
		void	makeSound() const;
};

#endif
