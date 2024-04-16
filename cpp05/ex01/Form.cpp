/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:22:22 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 16:17:35 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Form::Form() : _name("Default"), _isSigned(false), _signGrade(100), _execGrade(50)
{
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(std::string const name, bool isSigned, int signGrade, int execGrade) : 
	_name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form parameterized constructor called." << std::endl;
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
}

Form::Form(Form const &copy) : 
	_name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	std::cout << "Form copy constructor called." << std::endl;
	*this = copy;
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Form &Form::operator=(Form const &copy)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &copy)
		_isSigned = copy.getSigned();
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::string const	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_isSigned);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if ((int)bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
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

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade to sign is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade to sign is too low!";
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OTHER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::ostream& operator<<(std::ostream& output, const Form& copy)
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
