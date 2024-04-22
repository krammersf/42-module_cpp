/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/20 11:58:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cerr << std::endl;
		std::cerr << RED << " Error: Invalid parameters number." << RESET << std::endl;
		std::cerr << YELLOW << " Usaged:  " << CYAN << "./RPN " << "\"Reverse Polish Notation mathematical expression\"" << "\n";
		std::cerr << YELLOW << " Example: " << CYAN << "./RPN " << "\"8 9 * 9 - 9 - 9 - 4 - 1 +\"";
		std::cerr << RESET << "\n" << std::endl;
		return (1);
	}

	const char* input = argv[1];
	while (*input != '\0') // whitespace checker in input
	{
		if (!std::isspace(*input))
			break;
		input++;
	}

	if (*input == '\0')
	{
		std::cerr << RED << "\n" << " Error: String is either empty or contains only whitespace characters." << RESET << std::endl;
		std::cerr << YELLOW << " Usage:   " << CYAN << "./RPN " << "\"Reverse Polish Notation mathematical expression\"" << "\n";
		std::cerr << YELLOW << " Example: " << CYAN << "./RPN " << "\"8 9 * 9 - 9 - 9 - 4 - 1 +\"";
		std::cerr << RESET << "\n" << std::endl;
		return (1);
	}

	RPN ReversePolishNotation = RPN();
	ReversePolishNotation.execute(argv[1]);

	return (0);
}

/*
	--> espected output:

	$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	42
	$> ./RPN "7 7 * 7 -"
	42
	$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
	0
	$> ./RPN "(1 + 1)"
	Error
	$>
*/

// valgrind ./RPN "9 0 /"
// valgrind ./RPN ""
// valgrind ./RPN "  	"


