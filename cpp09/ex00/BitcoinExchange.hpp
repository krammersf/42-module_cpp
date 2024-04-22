/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:09:52 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/22 13:07:08 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define GREY "\033[1;30m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define GREEN1 "\033[0;32m"
# define RED "\033[1;31m"
# define RED1 "\033[0;31m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET "\033[0m"
# define SBLINK	"\033[5m"
# define BG_GREEN "\033[42m"
# define MAGENTA "\033[1;35m"
# define REVERSE "\033[7m"
# define BG_MAGENTA "\033[45m"
# define BG_RED "\033[41m"
# define BG_GREEN_YELLOW "\033[42;33m"
# define BG_RED_YELLOW "\033[41;33m"
# define BG_GREEN_BLACK "\033[42;30m"
# define BG_RED_BLACK "\033[41;30m"
# define BG_DARK_GRAY "\033[100m"
# define BG_CYAN "\033[46m"
# define BG_BLUE "\033[44m"
# define RESET_BG "\033[49m"

# include <iostream>
# include <iomanip> // for setw()
# include <map> // for std::map
# include <fstream> //for file handling
# include <cstdlib> // for exit() | stdtod()

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_btcDataBase;
		std::ifstream					_dataBasefile;
		std::ifstream					_inputFile;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &copy);

		void	fileToData();

		bool	checkDateFormat(const std::string &checkDate);
		bool	verifyDateFormat(const std::string &checkDate);
		bool	checkDateIsCorrect(int day, int month, int year);

		bool	checkBTCValue(std::string valueString);

		bool	openInputFile(std::string file);
		void	checkInputFileHeader();
		void	processInputFileLines();
		
		void	execute(std::string date, std::string value);
		void	parsingInputFile(std::string file);
};

#endif

/*
Why i used a map container?

Maps are a powerful container that provide efficient lookup times, ordered traversal,
and an associative relationship between keys and values. However, they come with some
overhead and may not be the best choice in all scenarios, especially when fast
insertion/deletion or lower memory usage is a priority.

Advantages of using a map container:
==> Fast Search: Maps provide fast lookup times (O(log n)) for key-value pairs,
	making them efficient for searching and retrieving data based on keys.
==> Ordered: By default, maps are ordered based on their keys. This means that
	iterating over a map will result in items being visited in sorted order by key.
==> Associative Relationship: Maps allow for an associative relationship between
	keys and values, making it easy to store and retrieve data based on unique
	identifiers (keys).
==> No Duplicates: Each key in a map is unique, ensuring that there are no duplicate
	keys. This can be advantageous in scenarios where uniqueness is required.
==> Flexible Key Types: Maps support a wide range of key types, including custom
	types, allowing for versatile use cases.

Disadvantages of using a map container:
==> Overhead: Maps typically have more memory overhead compared to other containers
	due to the internal data structures used for maintaining the associative relationship.
==> Slower Insertion/Deletion: Insertion and deletion operations in maps are generally
	slower (O(log n)) compared to vectors or lists, especially when the map needs to be
	reorganized.
==> Complexity: Maps have more complexity compared to simpler containers like vectors or
	arrays. This complexity can make them harder to understand and use for beginners.
==> Ordered: While the ordered nature of maps can be advantageous in some cases, it can
	also be a disadvantage if unordered access is needed. In such cases, unordered 
	containers like unordered_map might be more suitable.
==> Iterators: Iterating over a map can be slightly slower compared to iterating over
	other containers due to the tree structure used internally.
*/