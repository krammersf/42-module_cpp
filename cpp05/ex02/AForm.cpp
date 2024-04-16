/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:22:22 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 16:16:41 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(100), _execGrade(50)
{
	std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(std::string const name, int signGrade, int execGrade) : 
	_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "AForm parameterized constructor called." << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm const &copy) : 
	_name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	std::cout << "AForm copy constructor called." << std::endl;
	*this = copy;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called." << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AForm &AForm::operator=(AForm const &copy)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &copy)
		_isSigned = copy.getSigned();
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::string const   AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_isSigned);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if ((int)bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else if (!this->_isSigned)
	{
		std::cout << bureaucrat.getName() << " signed form \"" << this->getName() << "\""<< std::endl;
		this->_isSigned = true;
	}
	else
	{
		std::cout << bureaucrat.getName() << " couldn't sign form \"";
		std::cout << this->getName() << "\" because it's already signed" << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade to is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade to is too low!";
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OTHER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::ostream& operator<<(std::ostream& output, const AForm& copy)
{
	output << "Form \"" << copy.getName() << "\" is ";
	if (copy.getSigned())
		output << GREEN << "signed" << RESET << " | ";
	else
		output << MAGENTA << "not signed" << RESET << " | ";
	output << "Sign Grade is: [" << copy.getSignGrade() << "] and Executable Grade is: [";
	output << copy.getExecGrade() << "]." <<std::endl;
	return (output);
}
