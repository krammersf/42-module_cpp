/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:02:28 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 12:10:23 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm(target, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm parameterized constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	std::cout << "PresidentialPardonForm assignation operator called." << std::endl;
	if (this != &copy)
		this->_target = copy.getTarget();
	return (*this);
}

std::string  PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
	{
		throw GradeTooLowException();
	}
	
	if (this->getSigned())
		std::cout << "Form \"" << this->getTarget() << "\" has been pardoned by Zafod Beeblebrox." << std::endl;
}
