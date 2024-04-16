/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/27 10:58:21 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void titleHeader(const std::string& message)
{
	std::cout << "\033c";
	int standartSize = 60;
	int messageSize = message.length();
	int spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	int spacesAfter = (standartSize - messageSize) / 2 + 1 + messageSize % 2;

	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET_BG << std::endl;
	std::cout << BG_BLUE << "|" << std::setw(spacesBefore) << message << RESET_BG;
	std::cout << BG_BLUE << std::setw(spacesAfter) << "|" << RESET_BG << std::endl;
	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET_BG << std::endl;
	std::cin.get();
}

void	subTitle(const std::string& message)
{
	std::cout << YELLOW << ">>> " << message << RESET <<"\n" << std::endl;
}

void ShrubberyCreation()
{
	subTitle("Shrubbery Test");
	try
	{
		Bureaucrat bureaucrat1("Ines", 146);
		Bureaucrat bureaucrat2("Fred", 130);
		ShrubberyCreationForm form("One");

		if (form.getTarget().empty())
		{
			std::cerr << "\n" << RED << "Error: Form name is empty. ";
			std::cerr << "Please don't try to creat an empty form.";
			std::cerr << "\nSorry the program will shutdown. Please try again! 😀";
			std::cerr << RESET << "\n" << std::endl;
			exit(1);
		}

		std::cout << std::endl;
		std::cout << "Bureaucrat " << bureaucrat1 << std::endl;
		std::cout << "Bureaucrat " << bureaucrat2 << std::endl;
		std::cout << form << std::endl;

		try
		{
			std::cout << bureaucrat1.getName() << " tries to sign the form \"" << form.getName() << "\""<< std::endl;
			form.beSigned(bureaucrat1);
			std::cout << form << std::endl;
			std::cout << bureaucrat1.getName() << " tries to execute the form \"" << form.getName() << "\""<< std::endl;
			form.execute(bureaucrat1);
			std::cout << bureaucrat1.getName() << " executed form \"" << form.getName() << "\"" << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "Permission denied: " << RED << e.what() << RESET;
			std::cout << std::endl;
			std::cerr << bureaucrat1.getName() << " can't execute form \"" << form.getName() << "\"";
			std::cerr << " because: " << RED << e.what() << RESET;
			std::cout << "\n" << std::endl;
		} 
		try
		{
			std::cout << bureaucrat2.getName() << " tries to sign the form \"" << form.getName() << "\""<< std::endl;
			form.beSigned(bureaucrat2);
			std::cout << form << std::endl;
			std::cout << bureaucrat2.getName() << " tries to execute the form \"" << form.getName() << "\""<< std::endl;
			form.execute(bureaucrat2);
			std::cout << bureaucrat2.getName() << " executed form \"" << form.getName() << "\"" << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "Permission denied: " << RED << e.what() << RESET;
			std::cout << std::endl;
			std::cerr << bureaucrat2.getName() << " can't execute form \"" << form.getName() << "\"";
			std::cerr << " because: " << RED << e.what() << RESET;
			std::cout << "\n" << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}


void RobotomyRequest()
{
	subTitle("Robotomy Test");
	try
	{
		Bureaucrat bureaucrat1("Maria", 130);
		Bureaucrat bureaucrat2("Rodrigo", 40);
		RobotomyRequestForm form("Two");

		std::cout << std::endl;
		std::cout << "Bureaucrat " << bureaucrat1 << std::endl;
		std::cout << "Bureaucrat " << bureaucrat2 << std::endl;
		std::cout << form << std::endl;

		try
		{
			std::cout << bureaucrat1.getName() << " tries to sign the form \"" << form.getName() << "\""<< std::endl;
			form.beSigned(bureaucrat1);
			std::cout << form << std::endl;
			std::cout << bureaucrat1.getName() << " tries to execute the form \"" << form.getName() << "\""<< std::endl;
			form.execute(bureaucrat1);
			std::cout << bureaucrat1.getName() << " executed form \"" << form.getName() << "\"" << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "Permission denied: " << RED << e.what() << RESET;
			std::cout << std::endl;
			std::cerr << bureaucrat1.getName() << " can't execute form \"" << form.getName() << "\"";
			std::cerr << " because: " << RED << e.what() << RESET;
			std::cout << "\n" << std::endl;
		} 
		try
		{
			std::cout << bureaucrat2.getName() << " tries to sign the form \"" << form.getName() << "\""<< std::endl;
			form.beSigned(bureaucrat2);
			std::cout << form << std::endl;
			std::cout << bureaucrat2.getName() << " tries to execute the form \"" << form.getName() << "\":" << std::endl;
			for(int i = 0; i < 3; i++)
			{
				form.execute(bureaucrat2);
				std::cout << " " << bureaucrat2.getName() << " executed form \"" << form.getName() << "\"" << std::endl;
				std::cout << std::endl;
			}
		}
		catch (std::exception const &e)
		{
			std::cerr << "Permission denied: " << RED << e.what() << RESET;
			std::cout << std::endl;
			std::cerr << bureaucrat2.getName() << " can't execute form \"" << form.getName() << "\"";
			std::cerr << " because: " << RED << e.what() << RESET;
			std::cout << "\n" << std::endl;
		} 
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void PresidentialPardon()
{
	subTitle("Presidential Test");
	try
	{
		Bureaucrat bureaucrat1("Maria", 2);
		Bureaucrat bureaucrat2("Rodrigo", 20);
		PresidentialPardonForm form("Three");

		std::cout << std::endl;
		std::cout << "Bureaucrat " << bureaucrat1 << std::endl;
		std::cout << "Bureaucrat " << bureaucrat2 << std::endl;
		std::cout << form << std::endl;

		try
		{
			std::cout << bureaucrat1.getName() << " tries to sign the form \"" << form.getName() << "\""<< std::endl;
			form.beSigned(bureaucrat1);
			std::cout << form << std::endl;
			std::cout << bureaucrat1.getName() << " tries to execute the form \"" << form.getName() << "\""<< std::endl;
			form.execute(bureaucrat1);
			std::cout << bureaucrat1.getName() << " executed form \"" << form.getName() << "\"" << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "Permission denied: " << RED << e.what() << RESET;
			std::cout << std::endl;
			std::cerr << bureaucrat1.getName() << " can't execute form \"" << form.getName() << "\"";
			std::cerr << " because: " << RED << e.what() << RESET;
			std::cout << "\n" << std::endl;
		} 
		try
		{
			std::cout << bureaucrat2.getName() << " tries to sign the form \"" << form.getName() << "\""<< std::endl;
			form.beSigned(bureaucrat2);
			std::cout << form << std::endl;
			std::cout << bureaucrat2.getName() << " tries to execute the form \"" << form.getName() << "\""<< std::endl;
			form.execute(bureaucrat2);
			std::cout << bureaucrat2.getName() << " executed form \"" << form.getName() << "\"" << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "Permission denied: " << RED << e.what() << RESET;
			std::cout << std::endl;
			std::cerr << bureaucrat2.getName() << " can't execute form \"" << form.getName() << "\"";
			std::cerr << " because: " << RED << e.what() << RESET;
			std::cout << "\n" << std::endl;
		} 
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	titleHeader("Shrubbery + Robotomy + Presidential Test");
	ShrubberyCreation();
	std::cin.get();
	RobotomyRequest();
	std::cin.get();
	PresidentialPardon();
	std::cin.get();
	return (0);
}
