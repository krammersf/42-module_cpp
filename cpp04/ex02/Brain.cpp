/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:25:18 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/24 13:39:30 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Brain::Brain()
{
	int N = 100;
	for(int i = 0; i < N; i++)
		ideas[i] = "";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Brain &Brain::operator=(const Brain &copy)
{
	int N = 100;
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < N; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Brain::addIdea(std::string idea)
{
	int i = 0;
	int N = 100;
	while (i < 1 && ideas[i] != "")
		i++;
	if (i == N)
		std::cout << "Brain full 🧠 Cannot add idea: " << idea << std::endl;
	else
	{
		ideas[i] = idea;
		std::cout << "New idea: " << idea << std::endl;
	}
}
void Brain::printIdeas() const
{
	size_t N = 100;
	for (size_t i = 0; i < N; i++)
	{
		if (ideas[i] != "")
			std::cout << ideas[i] << std::endl;
	}
}