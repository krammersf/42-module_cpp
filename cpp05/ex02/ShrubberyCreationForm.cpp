/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:02:43 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 16:22:58 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm parameterized constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	std::cout << "ShrubberyCreationForm assignation operator called." << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy); 
		this->_target = copy._target;
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSigned())
	{
		if (_target.empty())
		{
			std::cerr << RED << "Error: Target is empty." << RESET << std::endl;
			return ;
		}
		std::ofstream outFile((_target + "_shrubbery").c_str(), std::ofstream::out);
		if (outFile.is_open())
		{
			outFile << "" << std::endl;
			outFile << "            /\\" << std::endl;
			outFile << "           /\\*\\" << std::endl;
			outFile << "          /\\O\\*\\" << std::endl;
			outFile << "         /\\*\\*\\/\\" << std::endl;
			outFile << "        /\\*\\/\\O\\/\\" << std::endl;
			outFile << "       /\\O\\/\\*\\/\\/\\" << std::endl;                  
			outFile << "      /\\*fde-carv*/\\" << std::endl;
			outFile << "     /\\O\\/\\*\\/\\O\\/\\*\\" << std::endl;
			outFile << "    /\\*\\/\\*\\/\\O\\/\\*\\/\\" << std::endl;
			outFile << "            ||" << std::endl;
			outFile << "            ||" << std::endl;
			outFile << "            ||" << std::endl;
			outFile << "            ||" << std::endl;
			outFile.close();
		}
		else
			std::cerr << "Unable to open file for shrubbery creation." << std::endl;
	}
	else
		std::cout << "Couldn't execute because \"" << this->getName() << "\" is not signed!" << std::endl;
}
