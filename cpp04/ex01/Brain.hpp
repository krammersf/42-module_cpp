/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:25:14 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/24 13:39:22 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		// constructors and destructor
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();

		//assigned operator
		Brain &operator=(const Brain &copy);

		// member functions
		void addIdea(std::string idea);
		void printIdeas() const;
};

#endif
