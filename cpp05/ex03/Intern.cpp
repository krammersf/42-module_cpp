/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:26:27 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 17:09:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
}

Intern &Intern::operator=(Intern const &copy)
{
	(void)(copy);
	std::cout << "Intern assignation operator called." << std::endl;
	return (*this);
}

AForm *Intern::makeForm(std::string const form, std::string const target)
{
	int index = -1;

	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for(int i = 0; i < 3; i++)
	{
		if (form == formTypes[i])
		{
			index = i;
			break;
		}
	}

	switch (index)
	{
		default:
			std::cerr << "Intern " << RED << "could not creat form ";
			std::cerr << RESET << form << " named \"" << target << "\"." << std::endl;
			return NULL;
		case 0:
			std::cout << "Intern" << CYAN << " creates form " << RESET;
			std::cout << form << " named \"" << target << "\".\n" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern" << CYAN << " creates form " << RESET;
			std::cout << form << " named \"" << target << "\".\n" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern" << CYAN << " creates form " << RESET;
			std::cout << form << " named \"" << target << "\".\n" << std::endl;
			return (new PresidentialPardonForm(target));
	}
}
