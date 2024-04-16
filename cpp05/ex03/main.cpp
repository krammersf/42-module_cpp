/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/27 11:02:25 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

void SubjectTest()
{
	subTitle("Subject Test");
	{
		Intern someRandomIntern;
		AForm *rrf = NULL;
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		rrf = someRandomIntern.makeForm("fde-carv request", "Fde-carv");
		if (rrf != NULL)
		{
			std::cout << std::endl;
			std::cout << "Created form named \"" << rrf->getName() << "\"" << std::endl;
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf != NULL)
		{
			std::cout << std::endl;
			std::cout << "Created form named \"" << rrf->getName() << "\"" << std::endl;
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}
	std::cout << std::endl;
}

void MixTest1()
{
	subTitle("Mix Test Shrubbery");
	{
		Bureaucrat bureaucrat1("Fred", 120);
		Bureaucrat bureaucrat2("Ana", 140);
		Intern someRandomIntern;
		std::cout << std::endl;
		std::cout << "Bureaucrat " << bureaucrat1 << std::endl;
		std::cout << "Bureaucrat " << bureaucrat2 << std::endl;
		
		AForm *form = NULL;
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		form = someRandomIntern.makeForm("fde-carv request", "Fde-carv");
		if (form != NULL)
		{
			std::cout << std::endl;
			std::cout << "Created form named \"" << form->getName() << "\"" << std::endl;
			std::cout << *form << std::endl;
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		form = someRandomIntern.makeForm("shrubbery creation", "One");
		if (form != NULL && form->getName().empty())
		{
			std::cerr << "\n" << RED << "Error: Form name is empty. ";
			std::cerr << "Please don't try to creat an empty form.";
			std::cerr << "\nSorry the program will shutdown. Please try again! 😀";
			std::cerr << RESET << "\n" << std::endl;
			delete form;
			exit(1);
		}
		if (form != NULL)
		{
			std::cout << std::endl;
			std::cout << *form << std::endl;
			try
			{
				std::cout << bureaucrat1.getName() << " tries to sign the form \"" << form->getName() << "\""<< std::endl;
				form->beSigned(bureaucrat1);
				std::cout << *form << std::endl;
				std::cout << bureaucrat1.getName() << " tries to execute the form \"" << form->getName() << "\""<< std::endl;
				form->execute(bureaucrat1);
				std::cout << bureaucrat1.getName() << " executed form \"" << form->getName() << "\"" << std::endl;
				std::cout << std::endl;
			}
			catch (std::exception const &e)
			{
				std::cerr << "Permission denied: " << RED << e.what() << RESET;
				std::cout << std::endl;
				std::cerr << bureaucrat1.getName() << " can't execute form \"" << form->getName() << "\"";
				std::cerr << " because: " << RED << e.what() << RESET;
				std::cout << "\n" << std::endl;
			} 
			try
			{
				std::cout << bureaucrat2.getName() << " tries to sign the form \"" << form->getName() << "\""<< std::endl;
				form->beSigned(bureaucrat2);
				std::cout << *form << std::endl;
				std::cout << bureaucrat2.getName() << " tries to execute the form \"" << form->getName() << "\""<< std::endl;
				form->execute(bureaucrat2);
				std::cout << bureaucrat2.getName() << " executed form \"" << form->getName() << "\"" << std::endl;
				std::cout << std::endl;
			}
			catch (std::exception const &e)
			{   
				std::cerr << "Permission denied: " << RED << e.what() << RESET;
				std::cout << std::endl;
				std::cerr << bureaucrat2.getName() << " can't execute form \"" << form->getName() << "\"";
				std::cerr << " because: " << RED << e.what() << RESET;
				std::cout << "\n" << std::endl;
			} 
			delete form;
		}
	}
}

void MixTest2()
{
	subTitle("Mix Test Robotomy");
	{
		Bureaucrat bureaucrat1("Rui", 10);
		Bureaucrat bureaucrat2("Matilde", 72);
		Intern someRandomIntern;
		std::cout << std::endl;
		std::cout << "Bureaucrat " << bureaucrat1 << std::endl;
		std::cout << "Bureaucrat " << bureaucrat2 << std::endl;
		
		AForm *form = NULL;
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		form = someRandomIntern.makeForm("super request", "Superuser");
		if (form != NULL)
		{
			std::cout << std::endl;
			std::cout << "Created form named \"" << form->getName() << "\"" << std::endl;
			std::cout << *form << std::endl;
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		form = someRandomIntern.makeForm("robotomy request", "Two");
		if (form != NULL)
		{
			std::cout << std::endl;
			std::cout << *form << std::endl;
			try
			{
				std::cout << bureaucrat1.getName() << " tries to sign the form \"" << form->getName() << "\""<< std::endl;
				form->beSigned(bureaucrat1);
				std::cout << *form << std::endl;
				std::cout << bureaucrat1.getName() << " tries to execute the form \"" << form->getName() << "\""<< std::endl;
				for(int i = 0; i < 3; i++)
				{
					form->execute(bureaucrat1);
					std::cout << " " << bureaucrat1.getName() << " executed form \"" << form->getName() << "\"" << std::endl;
					std::cout << std::endl;
				}
			}
			catch (std::exception const &e)
			{
				std::cerr << "Permission denied: " << RED << e.what() << RESET;
				std::cout << std::endl;
				std::cerr << bureaucrat1.getName() << " can't execute form \"" << form->getName() << "\"";
				std::cerr << " because: " << RED << e.what() << RESET;
				std::cout << "\n" << std::endl;
			} 
			try
			{
				std::cout << bureaucrat2.getName() << " tries to sign the form \"" << form->getName() << "\""<< std::endl;
				form->beSigned(bureaucrat2);
				std::cout << *form << std::endl;
				std::cout << bureaucrat2.getName() << " tries to execute the form \"" << form->getName() << "\""<< std::endl;
				form->execute(bureaucrat2);
				std::cout << bureaucrat2.getName() << " executed form \"" << form->getName() << "\"" << std::endl;
				std::cout << std::endl;
			}
			catch (std::exception const &e)
			{   
				std::cerr << "Permission denied: " << RED << e.what() << RESET;
				std::cout << std::endl;
				std::cerr << bureaucrat2.getName() << " can't execute form \"" << form->getName() << "\"";
				std::cerr << " because: " << RED << e.what() << RESET;
				std::cout << "\n" << std::endl;
			} 
			delete form;
		}
	}
}

void MixTest3()
{
	subTitle("Mix Test Presidential");
	{
		Bureaucrat bureaucrat1("Miguel", 1);
		Bureaucrat bureaucrat2("Maria", 25);
		Intern someRandomIntern;
		std::cout << std::endl;
		std::cout << "Bureaucrat " << bureaucrat1 << std::endl;
		std::cout << "Bureaucrat " << bureaucrat2 << std::endl;
		
		AForm *form = NULL;
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		form = someRandomIntern.makeForm("marcelo pardon", "Marcelo");
		if (form != NULL)
		{
			std::cout << std::endl;
			std::cout << "Created form named \"" << form->getName() << "\"" << std::endl;
			std::cout << *form << std::endl;
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern attempts to create a form." << std::endl;
		form = someRandomIntern.makeForm("presidential pardon", "Three");
		if (form != NULL)
		{
			std::cout << std::endl;
			std::cout << *form << std::endl;
			try
			{
				std::cout << bureaucrat1.getName() << " tries to sign the form \"" << form->getName() << "\""<< std::endl;
				form->beSigned(bureaucrat1);
				std::cout << *form << std::endl;
				std::cout << bureaucrat1.getName() << " tries to execute the form \"" << form->getName() << "\""<< std::endl;
				form->execute(bureaucrat1);
				std::cout << bureaucrat1.getName() << " executed form \"" << form->getName() << "\"" << std::endl;
				std::cout << std::endl;
			}
			catch (std::exception const &e)
			{
				std::cerr << "Permission denied: " << RED << e.what() << RESET;
				std::cout << std::endl;
				std::cerr << bureaucrat1.getName() << " can't execute form \"" << form->getName() << "\"";
				std::cerr << " because: " << RED << e.what() << RESET;
				std::cout << "\n" << std::endl;
			} 
			try
			{
				std::cout << bureaucrat2.getName() << " tries to sign the form \"" << form->getName() << "\""<< std::endl;
				form->beSigned(bureaucrat2);
				std::cout << *form << std::endl;
				std::cout << bureaucrat2.getName() << " tries to execute the form \"" << form->getName() << "\""<< std::endl;
				form->execute(bureaucrat2);
				std::cout << bureaucrat2.getName() << " executed form \"" << form->getName() << "\"" << std::endl;
				std::cout << std::endl;
			}
			catch (std::exception const &e)
			{   
				std::cerr << "Permission denied: " << RED << e.what() << RESET;
				std::cout << std::endl;
				std::cerr << bureaucrat2.getName() << " can't execute form \"" << form->getName() << "\"";
				std::cerr << " because: " << RED << e.what() << RESET;
				std::cout << "\n" << std::endl;
			} 
			delete form;
		}
	}
}

int main()
{
	titleHeader("Intern Test");
	SubjectTest();
	std::cin.get();
	MixTest1();
	std::cin.get();
	MixTest2();
	std::cin.get();
	MixTest3();
	std::cin.get();
	return (0);
}
