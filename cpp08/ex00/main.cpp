/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/18 10:10:37 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <cstdlib> // rand()
#include <ctime> // time()

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

int	main (void)
{
	titleHeader("Associative Containers");
	std::srand(std::time(NULL));
	int printNumber = 8;
	unsigned int randomBase = 10;
	unsigned int containerSize = randomBase;
	std::cin.get();

	{
		subTitle("USING LIST");
		std::cout << YELLOW1 << " (List)" << "\n" << RESET << std::endl;
		std::list<int>	list;
		while (list.size() < containerSize)
		{
			int randomNumber = std::rand() % randomBase;
			if (std::find(list.begin(), list.end(), randomNumber) == list.end())
				list.push_back(randomNumber);
		}
		std::cout << "List: ";
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << "[" << CYAN << *it << RESET << "] ";
		std::cout << "\n" << std::endl;
		int numbersToFind[printNumber];
		std::set<int> generatedNumbers;
		for (int i = 0; i < printNumber; i++)
		{
			int randomNumber = std::rand() % (randomBase * 2);
			while (generatedNumbers.find(randomNumber) != generatedNumbers.end())
			{
				randomNumber = std::rand() % (randomBase * 2);
			}
			generatedNumbers.insert(randomNumber);
			numbersToFind[i] = randomNumber;
			std::cout << "Trying to find " << std::setw(2) << numbersToFind[i] << ": ";
			easyfind(list, numbersToFind[i]);
		}
		std::cout << std::endl;
		std::cin.get();
	}

	{
		subTitle("USING DEQUE");
		std::cout << YELLOW1 << " (Double-ended queue)" << "\n" << RESET << std::endl;
		std::deque<int>	deque;
		while (deque.size() < containerSize)
		{
			int randomNumber = std::rand() % randomBase;
			if (std::find(deque.begin(), deque.end(), randomNumber) == deque.end())
				deque.push_back(randomNumber);
		}
		std::cout << "Deque: ";
		for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
			std::cout << "[" << CYAN << *it << RESET << "] ";
		std::cout << "\n" << std::endl;
		int numbersToFind[printNumber];
		std::set<int> generatedNumbers;
		for (int i = 0; i < printNumber; i++)
		{
			int randomNumber = std::rand() % (randomBase * 2);
			while (generatedNumbers.find(randomNumber) != generatedNumbers.end())
			{
				randomNumber = std::rand() % (randomBase * 2);
			}
			generatedNumbers.insert(randomNumber);
			numbersToFind[i] = randomNumber;
			std::cout << "Trying to find " << std::setw(2) << numbersToFind[i] << ": ";
			easyfind(deque, numbersToFind[i]);
		}
		std::cout << std::endl;
		std::cin.get();
	}

	{
		subTitle("USING VECTOR");
		std::cout << YELLOW1 << " (Array resizable)" << "\n" RESET << std::endl;
		std::vector<int>	vector;
		while (vector.size() < containerSize)
		{
			int randomNumber = std::rand() % randomBase;
			if (std::find(vector.begin(), vector.end(), randomNumber) == vector.end())
				vector.push_back(randomNumber);
		}
		std::cout << "Vector: ";
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
			std::cout << "[" << CYAN << *it << RESET << "] ";
		std::cout << "\n" << std::endl;
		int numbersToFind[printNumber];
		std::set<int> generatedNumbers;
		for (int i = 0; i < printNumber; i++)
		{
			int randomNumber = std::rand() % (randomBase * 2);
			while (generatedNumbers.find(randomNumber) != generatedNumbers.end())
			{
				randomNumber = std::rand() % (randomBase * 2);
			}
			generatedNumbers.insert(randomNumber);
			numbersToFind[i] = randomNumber;
			std::cout << "Trying to find " << std::setw(2) << numbersToFind[i] << ": ";
			easyfind(vector, numbersToFind[i]);
		}
		std::cout << std::endl;
		std::cin.get();
	}

	{
		subTitle("USING SET");
		std::cout << YELLOW1 << " (Ordered unique elements container)" << "\n" RESET << std::endl;
		std::set<int>	set;
		while (set.size() < containerSize)
		{
			int randomNumber = std::rand() % randomBase;
			if (std::find(set.begin(), set.end(), randomNumber) == set.end())
				set.insert(randomNumber);
		}
		std::cout << "Set: ";
		for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
			std::cout << "[" << CYAN << *it << RESET << "] ";
		std::cout << "\n" << std::endl;
		int numbersToFind[printNumber];
		std::set<int> generatedNumbers;
		for (int i = 0; i < printNumber; i++)
		{
			int randomNumber = std::rand() % (randomBase * 2);
			while (generatedNumbers.find(randomNumber) != generatedNumbers.end())
			{
				randomNumber = std::rand() % (randomBase * 2);
			}
			generatedNumbers.insert(randomNumber);
			numbersToFind[i] = randomNumber;
			std::cout << "Trying to find " << std::setw(2) << numbersToFind[i] << ": ";
			easyfind(set, numbersToFind[i]);
		}
		std::cout << std::endl;
		std::cin.get();
	}	
	return (0);
}
/*
	PRINCIPAL CONTAINERS ()
		- std::list
		- std::deque
		- std::vector
		- std::set

	std::list<int>: A list is a linear sequence container that supports constant time
	insertion and removal of elements anywhere within the sequence. It differs from vector
	and deque in the way elements are stored internally and in the way they allow for
	insertions and deletions in the middle of the sequence.

	std::deque<int>: A deque, short for double-ended queue, is a sequence container that
	supports constant time insertion and removal of elements at both the beginning and the
	end of the sequence. It is similar to a vector but provides more efficient insertion and
	deletion at the beginning and end.

	std::vector<int>: A vector is a dynamic array that provides constant time access to
	elements, but linear time insertion and deletion at the end of the sequence. It stores
	elements in contiguous memory locations, allowing for efficient element access.

	std::set<int>: A set is an associative container that contains unique elements only.
	It automatically sorts its elements in ascending order and does not allow duplicate
	elements. Elements are stored internally in a balanced binary search tree, which provides
	logarithmic time complexity for insertions, deletions, and searches.
*/