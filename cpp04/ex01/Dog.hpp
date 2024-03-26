/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:02:12 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/11 16:23:18 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	
	public:
		// constructors and destructor
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();

		// assigned operator
		Dog &operator=(const Dog &copy);
 
		// member functions
		virtual void	makeSound() const;

		// get functions
		Brain*	getBrain() const;
};

#endif
