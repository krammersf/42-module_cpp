/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/27 09:43:36 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void normalTest()
{
	subTitle("Basic test: Grade 100");
	try
	{
		Bureaucrat bureaucrat("Fred", 100);
		Form form("One", false, 100, 100);

		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		try
		{
			std::cout << std::endl;
			bureaucrat.decrementGrade();
			std::cout << "After decrementing grade, Bureaucrat: " << bureaucrat << std::endl;
			bureaucrat.signForm(form);
		}
		catch (std::exception const &e)
		{
			std::cerr << "After decrementing grade, " << "Bureaucrat: Exception caught: " << RED << e.what() << RESET;
		}
		try
		{
			std::cout << std::endl;
			bureaucrat.incrementGrade();
			std::cout << std::endl;
			std::cout << "After incrementing grade, Bureaucrat: " << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "after incrementing grade, Bureaucrat: " << "\n" << "Exception caught: " << RED << e.what() << RESET;
		} 
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void normalTest2()
{
	subTitle("Basic test 2: Grade 100");
	try
	{
		Bureaucrat bureaucrat("Ana", 100);
		Form form("Two", false, 100, 100);

		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		try
		{
			std::cout << std::endl;
			bureaucrat.incrementGrade();
			std::cout << "After incrementing grade, Bureaucrat: " << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "after incrementing grade, Bureaucrat: " << "\n" << "Exception caught: " << RED << e.what() << RESET;
		} 
		try
		{
			bureaucrat.incrementGrade();
			std::cout << "After incrementing grade, Bureaucrat: " << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "after incrementing grade, Bureaucrat: " << "\n" << "Exception caught: " << RED << e.what() << RESET;
		} 
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void normalTest3()
{
	subTitle("Basic test 3: Grade 1 and Grade 150");
	try
	{
		Bureaucrat bureaucrat1("Jorge", 1);
		Bureaucrat bureaucrat2("Rodrigo", 150);
		Form form("Three", false, 30, 30);

		std::cout << "Bureaucrat " << bureaucrat1 << std::endl;
		std::cout << "Bureaucrat " << bureaucrat2 << std::endl;
		std::cout << form << std::endl;
		try
		{
			std::cout << "Bureaucrat ";
			bureaucrat1.signForm(form);
			std::cout << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << RED << e.what() << RESET;
		} 
		try
		{
			std::cout << "Bureaucrat " << bureaucrat2.getName() << " ";
			bureaucrat2.signForm(form);
			std::cout << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << RED << e.what() << RESET;
		}
		try
		{
			std::cout << "\n" << std::endl;
			std::cout << "Bureaucrat ";
			bureaucrat1.signForm(form);
			std::cout  << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << RED << e.what() << RESET;
		} 
	}
	catch (std::exception const &e)
	{
		std::cerr << "exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void lowInvalidTest()
{
	subTitle("Low Invalid Number");

	std::cout << "Trying to create a form with a sign-grade of 151 and execution-grade of 150" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Rosa", 150);
		Form form("Three", false, 151, 150);
		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void highInvalidTest()
{
	subTitle("High Invalid Number");

	std::cout << "Trying to create a form with a sign-grade of 0 and execution-grade of 1" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Miguel", 1);
		Form form("Three", false, 0, 1);
		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
		std::cout << form << std::endl;
		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void deepCopyTest()
{
	subTitle("Deep Copy Tests");

	Form theOriginal("Six", false ,100, 110);
	std::cout << theOriginal << std::endl;
	
	std::cout << "Original --> Name: \"" << theOriginal.getName() << "\"" << std::endl;
	std::cout << "Memory address: " << &theOriginal << "\n" << std::endl;

	Form *theCopy = new Form(theOriginal);

	std::cout << std::endl;
	std::cout << "Copy --> Name: \"" << theCopy->getName() << "\"" << std::endl;
	std::cout << "Memory address: " << &theCopy << "\n" << std::endl;
	
	std::cout << "Deleting the Copy" << std::endl;
	delete theCopy;
	std::cout << "Deleting the Original" << std::endl;
}

int main()
{
	titleHeader("BUREAUCRAT AND FORM TESTS");
	normalTest();
	std::cin.get();
	normalTest2();
	std::cin.get();
	normalTest3();
	std::cin.get();
	lowInvalidTest();
	std::cin.get();
	highInvalidTest();
	std::cin.get();
	deepCopyTest();
	std::cout << std::endl;
	std::cin.get();
	return (0);
}
