/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:05:32 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/22 13:16:27 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	if (this != &copy)
	{
		this->myVector = copy.myVector;
		this->myList = copy.myList;
	}
	return (*this);
}

// ========================================================================== //

void PmergeMe::checkInput(std::string input)
{
	input.erase(0, input.find_first_not_of(' '));
	input.erase(input.find_last_not_of(' ') + 1);

	for (std::size_t i = 0; i < input.size(); ++i)
	{
		if (!std::isdigit(input[i]))
		{
			std::cerr << RED << " Error:" << RESET << " Invalid input.";
			std::cerr << "\n" << std::endl;
			exit(1);
		}
	}

	long long number = std::atoll(input.c_str());
	if (number > INT_MAX)
	{
		std::cerr << RED << " Error:" << RESET;
		std::cerr << " The number is larger than the maximum integer value (INT_MAX).";
		std::cerr << "\n" << std::endl;
		exit(1);
	}
}

void PmergeMe::printTimeTaken(const std::string &container, const size_t size, const double time)
{
	std::stringstream ss;
	ss << time;
	std::string timeStr = ss.str();
	if(container == "std::vector")
	{
		std::cout << "Time to process a range of " << GREEN << size << RESET;
		std::cout << " elements with " << GREEN << container << std::setw(2);
		std::cout << ": " << GREEN1 << std::fixed << std::setprecision(4);
		if(timeStr.size() < 7)
			std::cout << std::setw(8) << std::setfill(' ');
		else if(timeStr.size() < 9)
			std::cout << std::setw(9) << std::setfill(' ');
		std::cout << time << RESET << " milliseconds" << std::endl;
	}
	else if(container == "std::list")
	{
		std::cout << "Time to process a range of " << YELLOW << size << RESET;
		std::cout << " elements with " << YELLOW << container << std::setw(4);
		std::cout << ": " << YELLOW1 << std::fixed << std::setprecision(4);
		if(timeStr.size() < 7)
			std::cout << std::setw(8) << std::setfill(' ');
		else if(timeStr.size() < 9)
			std::cout << std::setw(9) << std::setfill(' ');
		std::cout << time << RESET << " milliseconds" << std::endl;
	}
	else
		std::cout << RED << "There is a problem with the container!" << RESET << std::endl;
}

void PmergeMe::fillContainer(std::vector<int> &myVector, std::list<int> &myList, std::string input)
{
	std::istringstream stringToStream(input);
	int str;
	while (stringToStream >> str)
	{
		myVector.push_back(str);
		myList.push_back(str);
	}
}

// ========================================================================== //

void PmergeMe::printSequenceVector(const std::string &msg, const std::vector<int> &sequence)
{
	std::vector<int>::const_iterator it;
	if(msg == "Before:")
	{
		std::cout << BG_CYAN << msg << RESET;
		for (it = sequence.begin(); it != sequence.end(); ++it)
			std::cout << " " << CYAN1 << *it << RESET;
	}
	else if(msg == "After:")
	{
		std::cout << BG_BLUE << msg << RESET;
		for (it = sequence.begin(); it != sequence.end(); ++it)
			std::cout << " " << BLUE1 << *it << RESET;
	}
	else
		std::cout << RED << "There is a problem with the message!" << RESET << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printSequenceList(const std::string &msg, const std::list<int> &sequence)
{
	std::list<int>::const_iterator it;
	if(msg == "Before:")
	{
		std::cout << BG_CYAN << msg << RESET;
		for (it = sequence.begin(); it != sequence.end(); ++it)
			std::cout << " " << CYAN1 << *it << RESET;
	}
	else if(msg == "After:")
	{
		std::cout << BG_BLUE << msg << RESET;
		for (it = sequence.begin(); it != sequence.end(); ++it)
			std::cout << " " << BLUE1 << *it << RESET;
	}
	else
		std::cout << RED << "There is a problem with the message!" << RESET << std::endl;
	std::cout << std::endl;
}

// ========================================================================== //

void PmergeMe::sortVector(std::vector<int> &vector1)
{
	if (vector1.size() == 1)
		return ;

	int middle = vector1.size() / 2;

	std::vector<int> left(vector1.begin(), vector1.begin() + middle);
	std::vector<int> right(vector1.begin() + middle, vector1.end());

	sortVector(left);
	sortVector(right);
	mergeVector(left, right, vector1);

}

void PmergeMe::mergeVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector1)
{
	size_t leftIndex = 0;
	size_t rightIndex = 0;
	size_t vec = 0;

	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex] < right[rightIndex])
		{
			vector1[vec] = left[leftIndex];
			vec++;
			leftIndex++;
		}
		else
		{
			vector1[vec] = right[rightIndex];
			vec++;
			rightIndex++;
		}
	}

	while (leftIndex < left.size())
	{
		vector1[vec] = left[leftIndex];
		vec++;
		leftIndex++;
	}
	while (rightIndex < right.size())
	{
		vector1[vec] = right[rightIndex];
		vec++;
		rightIndex++;
	}
}

void PmergeMe::sortList(std::list<int> &list)
{
	if (list.size() == 1)
		return ;
	
	int middle = list.size() / 2;
	std::list<int>::iterator midIt = list.begin();
	
	std::advance(midIt, middle);

	std::list<int> left(list.begin(), midIt);
	std::list<int> right(midIt, list.end());

	sortList(left);
	sortList(right);
	mergeList(left, right, list);
}

void PmergeMe::mergeList(std::list<int> &left, std::list<int> &right, std::list<int> &list)
{
	std::list<int>::iterator itLeft = left.begin();
	std::list<int>::iterator itRight = right.begin();
	std::list<int>::iterator itList = list.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
		{
			*itList = *itLeft;
			++itLeft;
		}
		else
		{
			*itList = *itRight;
			++itRight;
		}
		++itList;
	}

	while (itLeft != left.end())
	{
		*itList = *itLeft;
		++itLeft;
		++itList;
	}
	while (itRight != right.end())
	{
		*itList = *itRight;
		++itRight;
		++itList;
	}
}

void PmergeMe::sortAlgorithm(std::vector<int> &vector1, std::list<int> &list1)
{
	printSequenceVector("Before:", vector1); // option 1
	//printSequenceList("Before:", list1); // option 2
	
	clock_t start1 = clock();
	sortVector(vector1);
	clock_t end1 = clock();
	double time_elapsed_vector = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
	printSequenceVector("After:", vector1); // option 1
	
	clock_t start2 = clock();
	sortList(list1);
	clock_t end2 = clock();
	double time_elapsed_list = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;
	//printSequenceList("After:", list1); // option 2
	
	std::cout << std::endl;
	printTimeTaken("std::vector", vector1.size(), time_elapsed_vector);
	printTimeTaken("std::list", list1.size(), time_elapsed_list);
}

//		https://www.geeksforgeeks.org/merge-sort/

// ========================================================================== //

/*
// ----- PRINTING THE ENTIRE PROCESS OF SORTING ----- //

void PmergeMe::sortVector(std::vector<int> &vector1)
{
	if (vector1.size() == 1)
	{
		std::cout << CYAN << "Reached a vector of size 1: " << vector1[0] << RESET << '\n'; //PRINT
		return;
	}

	int middle = vector1.size() / 2;

	std::vector<int> left(vector1.begin(), vector1.begin() + middle);
	std::vector<int> right(vector1.begin() + middle, vector1.end());

	std::cout << BLUE << "Vector before sorting: " << RESET; //PRINT
	for (std::vector<int>::const_iterator it = vector1.begin(); it != vector1.end(); ++it) //PRINT
	{ //PRINT
		std::cout << *it << ' '; //PRINT
	} //PRINT
	std::cout << '\n'; //PRINT

	std::cout << BG_RED << "Sorting left vector: " << RESET; //PRINT
	for (std::vector<int>::const_iterator it = left.begin(); it != left.end(); ++it) //PRINT
	{ //PRINT
		std::cout << *it << ' '; //PRINT
	} //PRINT
	std::cout << '\n'; //PRINT
	sortVector(left);

	std::cout << RED << "Left vector after sorting: " << RESET; //PRINT
	for (std::vector<int>::const_iterator it = left.begin(); it != left.end(); ++it) //PRINT
	{ //PRINT
		std::cout << *it << ' '; //PRINT
	} //PRINT
	std::cout << '\n'; //PRINT

	std::cout << BG_MAGENTA << "Sorting right vector: " << RESET; //PRINT
	for (std::vector<int>::const_iterator it = right.begin(); it != right.end(); ++it) //PRINT
	{ //PRINT
		std::cout << *it << ' '; //PRINT
	} //PRINT
	std::cout << '\n'; //PRINT
	sortVector(right);

	std::cout << MAGENTA << "Right vector after sorting: " << RESET; //PRINT
	for (std::vector<int>::const_iterator it = right.begin(); it != right.end(); ++it) //PRINT
	{ //PRINT
		std::cout << *it << ' '; //PRINT
	} //PRINT
	std::cout << '\n'; //PRINT

	std::cout << "Merging vectors...\n"; //PRINT
	mergeVector(left, right, vector1);

	std::cout << BG_DARK_GRAY << "Merged vector: " << RESET_BG; //PRINT
	for (std::vector<int>::const_iterator it = vector1.begin(); it != vector1.end(); ++it) //PRINT
	{ //PRINT
		std::cout << *it << ' '; //PRINT
	} //PRINT
	std::cout << '\n'; //PRINT
}

void PmergeMe::mergeVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector1)
{
	size_t leftIndex = 0;
	size_t rightIndex = 0;
	size_t vec = 0;

	while (leftIndex < left.size() && rightIndex < right.size())
	{
		std::cout << "Left: " << left[leftIndex] << " || Right: " << right[rightIndex] << std::endl; //PRINT
		if (left[leftIndex] < right[rightIndex])
		{
			vector1[vec] = left[leftIndex];
			std::cout << "Adding " << left[leftIndex] << " from left to merged vector.\n"; //PRINT
			vec++;
			leftIndex++;
		}
		else
		{
			vector1[vec] = right[rightIndex];
			std::cout << "Adding " << right[rightIndex] << " from right to merged vector.\n"; //PRINT
			vec++;
			rightIndex++;
		}
	}

	while (leftIndex < left.size())
	{
		vector1[vec] = left[leftIndex];
		std::cout << "Adding remaining " << left[leftIndex] << " from left to merged vector.\n"; //PRINT
		vec++;
		leftIndex++;
	}
	while (rightIndex < right.size())
	{
		vector1[vec] = right[rightIndex];
		std::cout << "Adding remaining " << right[rightIndex] << " from right to merged vector.\n"; //PRINT
		vec++;
		rightIndex++;
	}
}
*/