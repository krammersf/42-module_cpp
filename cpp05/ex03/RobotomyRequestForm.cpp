/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:02:38 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 17:01:22 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm parameterized constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	std::cout << "RobotomyRequestForm assignation operator called." << std::endl;
	if (this != &copy)
		this->_target = copy.getTarget();
	return (*this);
}

std::string   RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
	{
		throw GradeTooLowException();
	}
	
	if (this->getSigned())
	{
		int num = rand() % 2;
		std::cout << " Brruuummmmm..." << std::endl;
		if(num == 1)
			std::cout << " Form \"" << this->getTarget() << "\" has been robotomized successfully!" << std::endl;
		else
			std::cout << " Form \"" << this->getTarget() << "\" robotomization failed!" << std::endl;
	}
	else
		std::cout << "Couldn't execute because \"" << this->getName() << "\" is not signed!" << std::endl;
}