/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/16 10:53:18 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib> // rand()
#include <ctime> // time()
#include <unistd.h> // sleep()
//#include <set> // set
#include <climits> // INT_MIN

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
	std::cout << YELLOW << ">>> " << message << RESET << std::endl;
}

int main(void)
{
	titleHeader("Iterating through an array in Template Function");
	srand(time(NULL));
	std::cout << std::endl;
	std::cin.get();
	int a = 5;
	int b = 10;
	int c = 0;


	subTitle("Test to create an FLOAT Array with a specific size");
	std::cout << std::endl;
	Array<double> floatArray(a);
	for (unsigned int i = 0; i < floatArray.size(); ++i)
	{
		floatArray[i] = static_cast<float>(rand()) / 2147483648 * 100.0;
		std::cout << " [" << CYAN << floatArray[i] << RESET << "] ";
	}
	std::cout << "\n" << std::endl;
	std::cin.get();


	subTitle("Test to create an INT Array with a specific size");
	std::cout << std::endl;
	Array<int> intArray(b);
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = rand() % 100;
		std::cout << " [" << CYAN << intArray[i] << RESET << "] ";
	}
	std::cout << "\n" << std::endl;
	std::cin.get();


	subTitle("Test to create an Array based on another Array (copy)");
	std::cout << std::endl;
	std::cout << "Original Array:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << " [" << CYAN << intArray[i] << RESET << "] ";
	std::cout << "\n\n" << "The address of the Original Array is: " << &intArray << "\n" << std::endl;
	Array<int> copyArray(intArray);
	std::cout << "\n" << "Copy Array:" << std::endl;
	for (unsigned int i = 0; i < copyArray.size(); ++i)
		std::cout << " [" << CYAN << copyArray[i] << RESET << "] ";
	std::cout << "\n\n" << "The address of the Copy Array is: " << &copyArray << std::endl;
	std::cout << std::endl;
	std::cin.get();


	subTitle("Test to assign an Array to another Array");
	std::cout << std::endl;
	Array<int> assignedArray;
	std::cout << "\n" << "The address of the EMPTY array is: " << &assignedArray << "\n" << std::endl;
	assignedArray = intArray;
	std::cout << "\n" << "Assigned Array:" << std::endl;
	for (unsigned int i = 0; i < copyArray.size(); ++i)
		std::cout << " [" << CYAN << copyArray[i] << RESET << "] ";
	std::cout << "\n\n" << "The address of the ORIGINAL array is: " << &intArray << std::endl;
	std::cout << "The address of the ASSIGNED array is: " << &assignedArray << std::endl;
	std::cout << std::endl;
	std::cin.get();


	subTitle("Test to access valid elements of the Array");
	if(intArray.size() != 0)
	{
		std::cout << std::endl;
		std::cout << "Original Array:" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << " [" << CYAN << intArray[i] << RESET << "] ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < 3; i++)
		{
			int z = rand() % intArray.size();
			//std::set<int> generatedIndices;
			//while (generatedIndices.count(a) > 0)
			//	generatedIndices.insert(a);
			std::cout << "\n" << "The slot " << z << " has the element:";
			std::cout << " [" << CYAN << intArray[z] << RESET << "] ";
		}
		std::cout << "\n" << std::endl;
	}
	std::cin.get();


	subTitle("Test to access invalid elements of the Array");
	std::cout << std::endl;
	std::cout << "Original Array has " << intArray.size() << " slots." << "\n" << std::endl;
	try
	{
		if(intArray.size() != 0)
			intArray[intArray.size() + 1] = 10;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << RED << "Caught exception: " << RED1 << e.what();
		std::cerr << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cin.get();


	subTitle("Test to access elements of the Array and change them");
	if(intArray.size() != 0)
	{
		std::cout << std::endl;
		std::cout << "Original Array has " << intArray.size() << " slots." << "\n" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << " [" << CYAN << intArray[i] << RESET << "] ";
		std::cout << "\n" << std::endl;
		std::cout << "Original Array has changed the last slot to INT MIN." << "\n" << std::endl;
		intArray[intArray.size() - 1] = INT_MIN;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << " [" << CYAN << intArray[i] << RESET << "] ";
		std::cout << "\n" << std::endl;
		std::cout << "Original Array has changed all the elements by adding 1000." << "\n" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			intArray[i] += 1000;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << " [" << CYAN << intArray[i] << RESET << "] ";
		std::cout << "\n" << std::endl;
	}	
	std::cin.get();


	subTitle("Test to create an empty Array");
	std::cout << std::endl;
	Array<int> emptyArray2;
	if(emptyArray2.size() > 0)
	{
		for (unsigned int i = 0; i < emptyArray2.size(); ++i)
		{
			emptyArray2[i] = rand() % 100;
			std::cout << " [" << CYAN << emptyArray2[i] << RESET << "] ";
		}
	}
	else
	{
		usleep(600000);
		std::cout << "\n" << "The array is empty. Impossible to output empty array." << std::endl;
		std::cout << "The address of the empty array is: " << &emptyArray2 << std::endl;
	}
	std::cout << std::endl;
	Array<int> emptyArray1(c);
	if(emptyArray1.size() > 0)
	{
		std::cout << std::endl;
		for (unsigned int i = 0; i < emptyArray1.size(); ++i)
		{
			emptyArray1[i] = rand() % 100;
			std::cout << " [" << CYAN << emptyArray1[i] << RESET << "] ";
		}
		std::cout << std::endl;
	}
	else
	{
		usleep(600000);
		std::cout << "\n" << "The array is empty. Impossible to output empty array." << std::endl;
		std::cout << "The address of the empty array is: " << &emptyArray1 << std::endl;
	}
	std::cout << std::endl;
	std::cin.get();


	subTitle("Test to create an empty array of 7 elements");
	std::cout << std::endl;
	Array<int> emptyArray7(7);
	std::cout << "\n" << "This Array has " << emptyArray7.size() << " slots:";
	if(emptyArray7.size() > 0)
	{
		std::cout << std::endl;
		for (unsigned int i = 0; i < emptyArray7.size(); ++i)
			std::cout << " [" << CYAN << emptyArray7[i] << RESET << "] ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cin.get();
}
