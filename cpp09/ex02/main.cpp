/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/20 13:56:17 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
	./PmergeMe `shuf -i 1-1000 -r -n 3000 | tr "\n" " " `
	./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " " `
*/

int	main(int argc, char **argv)
{
	std::cout << std::endl;
	
	PmergeMe containers;
	std::vector<int> vector1;
	std::list<int> list1;
	
	if(argc < 3)
	{
		std::cerr << RED << " Error:" << RESET << " Invalid number of arguments.\n";
		std::cerr << "        It must have at least 2 arguments.";
		std::cerr << "\n" << std::endl;
		return (0);
	}

	for(int i = 1; i < argc; i++)
		containers.checkInput(argv[i]);

	for(int i = 1; i < argc; i++)
		containers.fillContainer(vector1, list1, argv[i]);

	containers.sortAlgorithm(vector1, list1);
	std::cout << std::endl;
	
	return (0);
}

// https://www.geeksforgeeks.org/merge-sort/

/*
For an array of 3000 elements, `std::vector` would likely be more efficient than
`std::list` for most operations, including sorting.

There are a few reasons for this:

1. **Locality of reference**: `std::vector` stores its elements in a contiguous block
of memory, which is good for locality of reference. This means that once one element
is accessed, it's likely that elements near it will be accessed soon. This is good
for the CPU cache, which can significantly speed up data access.

2. **Random access**: `std::vector` supports random access to its elements, which
means you can access any element directly using an index. This is useful for many
algorithms, including Merge Sort, which needs to split the vector into two halves.
`std::list`, on the other hand, does not support random access.

3. **Memory usage**: `std::list` uses more memory than `std::vector` because in
addition to the data, it also needs to store pointers to the next and previous element
in the list. This can be an issue if you're dealing with large amounts of data.

However, these are generalizations and the actual performance can vary depending on
many factors, including the specific compiler implementation and system architecture.
*/
