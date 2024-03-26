/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:02:06 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/11 16:14:04 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// constructors and destructor
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();

		// assigned operator
		Cat &operator=(const Cat &copy);
 
		// member functions
		virtual void makeSound() const;
};

#endif
