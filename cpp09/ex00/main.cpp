/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/22 09:52:17 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char**argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << std::endl;
		std::cerr << RED << " Error: could not open file." << RESET << std::endl;
		std::cerr << YELLOW << " Usaged: " << CYAN << "./btc " << "<txt_file_name>";
		std::cerr << RESET << "\n" << std::endl;
		return (0);
	}
	BitcoinExchange btc = BitcoinExchange();
	btc.fileToData();
	btc.parsingInputFile(argv[1]);
	std::cout << std::endl;
}

/*
	--> example of an input.txt file: 'make' txt1 or 'make' txt2
	
		$> head input.txt
		date | value
		2011-01-03 | 3
		2011-01-03 | 2
		2011-01-03 | 1
		2011-01-03 | 1.2
		2011-01-09 | 1
		2012-01-11 | -1
		2001-42-42
		2012-01-11 | 1
		2012-01-11 | 2147483648
		$>
*/

/*
	--> espected output:

		$> ./btc
		Error: could not open file.
		$> ./btc input.txt
		2011-01-03 => 3 = 0.9
		2011-01-03 => 2 = 0.6
		2011-01-03 => 1 = 0.3
		2011-01-03 => 1.2 = 0.36
		2011-01-09 => 1 = 0.32
		Error: not a positive number.
		Error: bad input => 2001-42-42
		2012-01-11 => 1 = 7.1
		Error: too large a number.
		$>
*/
