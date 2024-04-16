/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/15 12:16:21 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

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

template <typename T> void DoubleIncrementWrapper(const T &x)
{
	DoubleIncrement(x);
}

template <typename T> void TenIncrementWrapper(const T &x)
{
	TenIncrement(x);
}

template <typename T> void ReplaceWrapper(const T &x)
{
	Replace(x);
}

int main(void)
{
	titleHeader("Iterating through an array in Template Function");
	std::cout << std::endl;

	{
		subTitle("INT Array Test");
		std::cout << std::endl;
		int array[5] = {99, 4, 5, 2, 43};
		std::cout << "Original Array: " << std::endl;
		iter(array, 5, &print);

		std::cout << "\n"<< std::endl;
		std::cout << "After double the values: " << std::endl;
		iter(array, 5, DoubleIncrementWrapper<int>);
		std::cout << "\n" << std::endl;
	}
	std::cout << std::endl;
	{
		subTitle("DOUBLE Array Test");
		std::cout << std::endl;
		double array[5] = {99.1, 4.201, 5.30, 2.4001, 43.5};
		std::cout << "Original Array: " << std::endl;
		iter(array, 5, &print);

		std::cout << "\n"<< std::endl;
		std::cout << "After incrementing 10 to the values: " << std::endl;
		iter(array, 5, &TenIncrementWrapper<double>);
		std::cout << "\n" << std::endl;
	}
	std::cout << std::endl;
	{
		subTitle("STRING Array Test");
		std::cout << std::endl;
		std::string array[5] = {"Hello", "my name", "in 42", "school", "is fde-carv"};
		std::cout << "Original Array: " << std::endl;
		iter(array, 5, &print);

		std::cout << "\n"<< std::endl;
		std::cout << "After replacing [string] for 'fde-carv': " << std::endl;
		iter(array, 5, &ReplaceWrapper<std::string>);
		std::cout << "\n" << std::endl;
	}
	std::cout << std::endl;
}

// int	main(void)
// {
// 	titleHeader("Iterating through an array in Template Function");
// 	std::cout << std::endl;

// 	{
// 		subTitle("INT Array Test");
// 		std::cout << std::endl;
// 		int	array[5] = {99, 4, 5, 2, 43};
// 		std::cout << "Original Array: " << std::endl;
// 		iter(array, 5, &print);

// 		std::cout << "\n"<< std::endl;
// 		std::cout << "After double the values: " << std::endl;
// 		iter(array, 5, DoubleIncrement<int>);
// 		std::cout << "\n" << std::endl;
// 	}
// 	std::cout << std::endl;
// 	{
// 		subTitle("DOUBLE Array Test");
// 		std::cout << std::endl;
// 		double	array[5] = {99.1, 4.201, 5.30, 2.4001, 43.5};
// 		std::cout << "Original Array: " << std::endl;
// 		iter(array, 5, &print);

// 		std::cout << "\n"<< std::endl;
// 		std::cout << "After incremente 10 to the values: " << std::endl;
// 		iter(array, 5, &TenIncrement<double>);
// 		std::cout << "\n" << std::endl;
// 	}
// 	std::cout << std::endl;
// 	{
// 		subTitle("STRING Array Test");
// 		std::cout << std::endl;
// 		std::string	array[5] = {"Hello", "my name", "in 42", "school", "is fde-carv"};
// 		std::cout << "Original Array: " << std::endl;
// 		iter(array, 5, &print);

// 		std::cout << "\n"<< std::endl;
// 		std::cout << "After replacing [string] for 'fde-carv': " << std::endl;
// 		iter(array, 5, &Replace<std::string>);
// 		std::cout << "\n" << std::endl;
// 	}
// 	std::cout << std::endl;
// }
