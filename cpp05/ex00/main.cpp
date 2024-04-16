/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/27 09:42:05 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Bureaucrat.hpp"

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
	subTitle("Basic tests: Grade 100");
	try
	{
		Bureaucrat bureaucrat("Fred", 100);
		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
		try
		{
			bureaucrat.incrementGrade();
			std::cout << "After incrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After incrementing grade, Bureaucrat: " << "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << bureaucrat << std::endl;
		} 
		try
		{
			bureaucrat.decrementGrade();
			std::cout << "After decrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After decrementing grade, Bureaucrat: " "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << bureaucrat << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void maxTest()
{
	subTitle("Basic tests: Grade 150");
	try
	{
		Bureaucrat bureaucrat("Rui", 150);
		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
		try
		{
			bureaucrat.incrementGrade();
			std::cout << "After incrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After incrementing grade, Bureaucrat: " << "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << bureaucrat << std::endl;
		} 
		try
		{
			bureaucrat.decrementGrade();
			std::cout << "After decrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After decrementing grade, Bureaucrat: " << "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << bureaucrat << std::endl;
		}
		try
		{
			bureaucrat.decrementGrade();
			std::cout << "After decrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After decrementing grade, Bureaucrat: " << "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << "" << bureaucrat << std::endl;
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void minTest()
{
	subTitle("Basic tests: Grade 1");
	try
	{
		Bureaucrat bureaucrat("Ana", 1);
		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
		try
		{
			bureaucrat.decrementGrade();
			std::cout << "After decrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After decrementing grade, Bureaucrat: " << "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << bureaucrat << std::endl;
		}
		try
		{
			bureaucrat.incrementGrade();
			std::cout << "After incrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After incrementing grade, Bureaucrat: " << "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << bureaucrat << std::endl;
		}
		try
		{
			bureaucrat.incrementGrade();
			std::cout << "After incrementing grade, Bureaucrat: " << bureaucrat << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << "After incrementing grade, Bureaucrat: " << "Exception caught: " << RED << e.what() << RESET;
			std::cout << " " << bureaucrat << std::endl;
		} 
	}
	catch (std::exception const &e)
	{
	   std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void lowInvalidTest()
{
	subTitle("Low Invalid Number: Grade 151");
	try
	{
		Bureaucrat bureaucrat("Rosa", 151);
		std::cout << "Bureaucrat: " << bureaucrat << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

void highInvalidTest()
{
	subTitle("High Invalid Number: Grade 0");
	try
	{
		Bureaucrat bureaucrat("Rodrigo", 0);
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

	Bureaucrat theOriginal("Sofia", 111);
	std::cout << "Original --> Name: " << theOriginal.getName() << ", Grade: " << theOriginal.getGrade() << std::endl;
	std::cout << "Memory address: " << &theOriginal << "\n" << std::endl;

	std::cout << "Try to increment grade" << std::endl;
	theOriginal.incrementGrade();

	std::cout << "Original --> Name: " << theOriginal.getName() << ", Grade: " << theOriginal.getGrade() << "\n" << std::endl;

	Bureaucrat *theCopy = new Bureaucrat(theOriginal);

	std::cout << "Copy --> Name: " << theCopy->getName() << ", Grade: " << theCopy->getGrade() << std::endl;
	std::cout << "Memory address: " << &theCopy << "\n" << std::endl;

	std::cout << "Try to decrement grade" << std::endl;
	theCopy->decrementGrade();

	std::cout << "Copy after decrement: Name: " << theCopy->getName() << ", Grade: " << theCopy->getGrade() << "\n" << std::endl;
	
	std::cout << "Deleting the Copy" << std::endl;
	delete theCopy;
	std::cout << "Deleting the Original" << std::endl;
	
}

int main()
{
	titleHeader("BUREAUCRAT TESTS");
	normalTest();
	std::cin.get();
	maxTest();
	std::cin.get();
	minTest();
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
