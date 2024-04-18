/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/18 10:30:47 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib> // rand()
#include <ctime> // time()
#include <unistd.h> // sleep()

void titleHeader(const std::string& message)
{
	std::cout << "\033c";
	int standartSize = 60;
	int messageSize = message.length();
	int spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	int spacesAfter = (standartSize - messageSize) / 2 + 1 + messageSize % 2;

	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << RESET_BG << std::endl;
	std::cout << BG_BLUE << "|" << std::setw(spacesBefore) << message << RESET_BG;
	std::cout << BG_BLUE << std::setw(spacesAfter) << "|" << RESET_BG << std::endl;
	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << RESET_BG << std::endl;
}

void	subTitle(const std::string& message)
{
	std::cout << YELLOW << ">>> " << message << RESET;
}

void	subTitle2(const std::string& message)
{
	std::cout << YELLOW1 << "... " << message << RESET;
}

int calculate(const std::vector<int>& vector)
{
	int smallestDifference = INT_MAX;
	int smallestValue = 0;
	int secondSmallestValue = 0;
	for (unsigned int i = 0; i < vector.size() - 1; ++i)
	{
		int difference = vector[i + 1] - vector[i];
		if (difference < smallestDifference)
		{
			smallestDifference = difference;
			smallestValue = vector[i];
			secondSmallestValue = vector[i + 1];
		}
	}
	//int distance0 = std::distance(vector.begin(), std::find(vector.begin(), vector.end(), smallestValue));
	//int distance1 = std::distance(vector.begin(), std::find(vector.begin(), vector.end(), secondSmallestValue));
	//std::cout << "Values for smallest difference" << std::setw(1) << ": ";
	//std::cout << distance0 << "-->" << smallestValue << " and " << distance1 << "-->" << secondSmallestValue << std::endl;
	std::cout << " Values for smallest difference" << std::setw(1) << ": ";
	std::cout << smallestValue << " and " << secondSmallestValue << std::endl;
	std::cout << " Smallest Difference" << std::setw(13) << ": ";
	std::cout  << secondSmallestValue - smallestValue << std::endl;
	return(secondSmallestValue - smallestValue);
}

void	checkPositive()
{
	std::cout << std::setw(10) << GREEN << "\u2714 Sucess!" << RESET << std::endl;
}

void	checkNegative()
{
	std::cout << std::setw(10) << RED << "\033[1mX Fail!" << RESET << std::endl;
}

void checkLongestSpan(const Span& sp, const std::vector<int>& vector)
{
	if (sp.longestSpan() == (vector.back() - vector.front()))
		checkPositive();
	else 
		checkNegative();
}

void checkShortestSpan(const Span& sp, const std::vector<int>& vector)
{
	int result = calculate(vector);
	std::cout << MAGENTA << " Shortest Span" << std::setw(19) << ": " << RESET << sp.shortestSpan();
	if (sp.shortestSpan() == result)
		checkPositive();
	else
		checkNegative();
}

int main(void)
{
	titleHeader("SPAN from the shortest to the longest");
	std::srand(std::time(NULL));
	std::cout << std::endl;


	{
		subTitle("Subject Test");
		std::cout << "\n" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << MAGENTA << " Shortest Span" << std::setw(1) << ": " << RESET << sp.shortestSpan() << std::endl;
		std::cout << MAGENTA << " Longest Span" << std::setw(3) << ": " << RESET << sp.longestSpan() << "\n" << std::endl;
		std::cin.get();
	}


	{
		unsigned int vectorSize = 1;
		unsigned int randomBase = 10;
		subTitle("Preparing to printing a VECTOR with ");
		std::cout << YELLOW << vectorSize << " element." << RESET << std::endl; 

		Span sp = Span(vectorSize);
		std::vector<int> vector;
		std::cout << std::endl;
		sp.fillVector(vector, vectorSize, randomBase);
		std::cout << "\n\n Vector size" << std::setw(3) << ": " << sp.getN() << std::endl;
		std::cout << " Vector range" << std::setw(3) << ": 0 to " << randomBase - 1 << "\n" << std::endl;

		try
		{
			std::cout << "Try to print the SHORTEST SPAN with one number" << std::endl;
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << "\n" << " --> ";
			std::cerr << RED << e.what() << RESET << "\n" << std::endl;
		}

		try
		{
			std::cout << "Try to print the LONGEST SPAN with one number" << std::endl;
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << "\n" << " --> ";
			std::cerr << RED << e.what() << RESET << "\n" << std::endl;
		}

		try
		{
			std::cout << "Try to ADD a NUMBER in a FULL VECTOR" << std::endl;
			sp.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << "\n" << " --> ";
			std::cerr << RED << e.what() << RESET << "\n" << std::endl;
		}
		std::cin.get();
	}


	{
		unsigned int vectorSize = 10;
		unsigned int randomBase = 100;
		subTitle("Preparing to printing a VERY SMALL VECTOR with ");
		std::cout << YELLOW << vectorSize << " elements." << std::endl; 
		subTitle2("Please wait ...");
		std::cout.flush(); // clean waiting buffer
		sleep(2);
		Span sp = Span(vectorSize);
		std::vector<int> vector;
		std::cout << "\n" << std::endl;
		sp.fillVector(vector, vectorSize, randomBase);
		std::cout << "\n\n Vector size" << std::setw(3) << ": " << sp.getN() << std::endl;
		std::cout << " Vector range" << std::setw(3) << ": 0 to " << randomBase - 1 << "\n" << std::endl;

		std::sort(vector.begin(), vector.end());
		std::cout << " MIN and MAX vector value" << std::setw(8) << ": " << vector.front() << " and " << vector.back() << std::endl;
		std::cout << " Difference between MAX and MIN: " << vector.back() - vector.front() << std::endl;
		std::cout << MAGENTA << " Longest Span" << std::setw(20) << ": " << RESET << sp.longestSpan();
		checkLongestSpan(sp, vector);
		std::cout << std::endl;

		checkShortestSpan(sp, vector);
		std::cout << std::endl;
		std::cin.get();
	}


	{
		unsigned int vectorSize = 500;
		unsigned int randomBase = 10000;
		subTitle("Preparing to printing a MEDIUM VECTOR with ");
		std::cout << YELLOW << vectorSize << " elements." << std::endl; 
		subTitle2("Please wait ...");
		std::cout.flush();
		sleep(3);
		Span sp = Span(vectorSize);
		std::vector<int> vector;
		std::cout << "\n" << std::endl;
		sp.fillVector(vector, vectorSize, randomBase);
		std::cout << "\n\n Vector size" << std::setw(3) << ": " << sp.getN() << std::endl;
		std::cout << " Vector range" << std::setw(3) << ": 0 to " << randomBase - 1 << "\n" << std::endl;

		std::sort(vector.begin(), vector.end());
		std::cout << " MIN and MAX vector value" << std::setw(8) << ": " << vector.front() << " and " << vector.back()  << std::endl;
		std::cout << " Difference between MAX and MIN: " << vector.back() - vector.front() << std::endl;
		std::cout << MAGENTA << " Longest Span" << std::setw(20) << ": " << RESET << sp.longestSpan();
		checkLongestSpan(sp, vector);
		std::cout << std::endl;

		checkShortestSpan(sp, vector);
		std::cout << std::endl;
		std::cin.get();
	}


	{
		unsigned int vectorSize = 100000;   //    (100.000) 100 thousand
		unsigned int randomBase = 10000000; // (10.000.000) 10 million
		subTitle("Preparing to printing a VERY LARGE VECTOR with ");

		std::cout << YELLOW << vectorSize << " elements. (100 thousand)" << std::endl; 
		subTitle2("Please wait ...");
		std::cout.flush();
		sleep(3);
		Span sp = Span(vectorSize);
		std::vector<int> vector;
		std::cout << "\n" << std::endl;
		sp.fillVector(vector, vectorSize, randomBase);
		std::cout << "\n\n Vector size" << std::setw(3) << ": " << sp.getN() << std::endl;
		std::cout << " Vector range" << std::setw(3) << ": 0 to " << randomBase - 1 << "\n" << std::endl;

		std::sort(vector.begin(), vector.end());
		std::cout << " MIN and MAX vector value" << std::setw(8) << ": " << vector.front() << " and " << vector.back()  << std::endl;
		std::cout << " Difference between MAX and MIN: " << vector.back() - vector.front() << std::endl;
		std::cout << MAGENTA << " Longest Span" << std::setw(20) << ": " << RESET << sp.longestSpan();
		checkLongestSpan(sp, vector);
		std::cout << std::endl;

		checkShortestSpan(sp, vector);
		std::cout << std::endl;
	}


	return (0);
}

/*
	int main()
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
	}
*/

/*
	Should output:
	$> ./ex01
	2
	14
	$>
*/
