/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:08:22 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 17:26:10 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat parameterized constructor called." << std::endl;
	{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if(this != &copy)
		this->_grade = getGrade();
	return (*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::string const   Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bureaucrat::incrementGrade()
{
	_grade -= 1;
	if (_grade < 1)
	{
		_grade = 1;
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{
	_grade += 1;
	if (_grade > 150)
	{
		_grade = 150;
		throw GradeTooLowException();    
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OTHER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::ostream &operator<<(std::ostream &output, const Bureaucrat &copy)
{
	output << "Name: " << copy.getName() << " and Grade: [" << copy.getGrade() << "].";
	return output;
}
