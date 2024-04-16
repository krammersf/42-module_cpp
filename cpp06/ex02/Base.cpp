/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:45:39 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/10 09:48:21 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base	*generate()
{
	int i = std::rand() % 3;
	if (i == 0)
	{
		std::cout << "Creating a new " << CYAN << "A" << RESET << " instance." << std::endl;
		return (new A); 
	}
	else if (i == 1)
	{
		std::cout << "Creating a new " << BLUE << "B" << RESET << " instance." << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Creating a new " << MAGENTA << "C" << RESET << " instance." << std::endl;
		return (new C);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << CYAN << " A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BLUE << " B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << MAGENTA << " C" << RESET << std::endl;
	else
		std::cout << RED << " unknown (NULL)" << RESET << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& classA = dynamic_cast<A&>(p);
		(void)classA;
		std::cout << CYAN << " A" << RESET << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B& classB = dynamic_cast<B&>(p);
		(void)classB;
		std::cout << BLUE << " B" << RESET << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C& classC = dynamic_cast<C&>(p);
		(void)classC;
		std::cout << MAGENTA << " C" << RESET << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << RED << " unknown (NULL)" << RESET << std::endl;
}
