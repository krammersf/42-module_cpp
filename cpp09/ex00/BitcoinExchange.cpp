/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:00:10 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/22 09:59:29 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp" 

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->_btcDataBase.clear();
	this->_btcDataBase = copy._btcDataBase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	this->_btcDataBase.clear();
	if (this != &copy)
		this->_btcDataBase = copy._btcDataBase;
	return (*this);
}

// ========================================================================== //

void	BitcoinExchange::fileToData()
{
	_dataBasefile.open("cpp_09/data.csv");
	if (!_dataBasefile)
	{
		std::cerr << RED << "\n" << " ❌ ERROR: Could not open database file.";
		std::cerr << YELLOW << "\n" << "    => Please check if you have run 'make download' first.";
		std::cerr << "\n" << RESET << std::endl;
		exit (1);
	}
	else
	{
		std::cout << GREEN << "\n" << " ✅ Database file opened successfully.";
		std::cout << RESET << std::endl;
	}

	std::string	line;
	std::string	part1;
	std::string	part2;
	getline(_dataBasefile, line);
	while (getline(_dataBasefile, line))
	{
		size_t i = line.find(",");
		part1 = line.substr(0, i);
		part2 = line.substr(i + 1);
		_btcDataBase.insert(std::pair<std::string, double>(part1, std::strtod(part2.c_str(), NULL)));
	}
	_dataBasefile.close();
}

// ========================================================================== //

bool	BitcoinExchange::checkDateFormat(const std::string& checkDate)
{
	if (checkDate.length() != 10)
		return (false);
	if (checkDate[4] != '-' || checkDate[7] != '-')
	 	return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7 && (checkDate[i] < '0' || checkDate[i] > '9')) //checks digits between '-'
			return (false);
	}
	std::string dateInicial = "2009-01-02";
	if (!verifyDateFormat(checkDate))
		return (false);
	if ((checkDate < dateInicial))
		return (false);
	return (true);
}

bool	BitcoinExchange::verifyDateFormat(const std::string& checkDate)
{
	unsigned int	i;
	std::string	year;
	std::string	month;
	std::string day;
	i = checkDate.find("-");
	if (i == std::string::npos)
		return (false);
	year = checkDate.substr(0, i);
	month = checkDate.substr(i + 1, 2);
	i = checkDate.find("-", i + 1);
	if (i == std::string::npos)
		return (false);
	day = checkDate.substr(i + 1, 2);
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
		return (false);
	if (!checkDateIsCorrect(atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str())))
		return (false);
	return (true);
}

bool BitcoinExchange::checkDateIsCorrect(int day, int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day < 1 || day > 30)
			return (false);
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		if (day < 1 || day > 31)
			return (false);
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day < 1 || day > 29)
				return (false);
		}
		else
		{
			if (day < 1 || day > 28)
				return (false);
		}
	}
	return (true);
}

// ========================================================================== //

bool	BitcoinExchange::checkBTCValue(std::string valueString)
{
	if (valueString.empty())
	{
		std::cout << RED1 << "Error: input is empty" << RESET << std::endl;
		return (false);
	}
	
	size_t start = valueString.find_first_not_of(" \t");
	size_t end = valueString.find_last_not_of(" \t");
	valueString = valueString.substr(start, end - start + 1); // Trim the input string

	for (size_t i = 0; i < valueString.size(); ++i)
	{
		if (!std::isdigit(valueString[0]) || (!std::isdigit(valueString[i]) && valueString[i] != '.'))
		{
			std::cout << RED1 << "Error: not a number." << RESET << std::endl;
			return (false);
		}
	}

	size_t dotPos = valueString.find(".");
	if (dotPos != std::string::npos)
	{
		dotPos = valueString.find(".", dotPos + 1);
		if (dotPos != std::string::npos)
		{
			std::cout << RED1 << "Error: more than one '.'" << RESET << std::endl;
			return (false);
		}
	}
	
	double value = atof(valueString.c_str());
	if (value < 0)
	{
		std::cout << RED1 << "Error: not a positive number." << RESET << std::endl;
		return (false);
	}

	if (value > 1000)
	{
		std::cout << RED1 << "Error: too large a number." << RESET << std::endl;
		return (false);
	}

	return (true);
}

// ========================================================================== //

bool BitcoinExchange::openInputFile(std::string file)
{
	_inputFile.open(file.c_str());
	if (!_inputFile)
	{
		std::cerr << RED << " ❌ Error: could not open input file." << RESET << std::endl;
		std::cerr << YELLOW << "    => Check if the file exists and try again.";
		std::cerr << RESET << std::endl;
		return (false);
	}
	else
	{
		std::cout << GREEN << " ✅ Input file opened successfully.";
		std::cout << RESET << std::endl;
		return (true);
	}
}

void BitcoinExchange::checkInputFileHeader(void)
{
	std::string line;
	getline(_inputFile, line);

	if (line.empty())
	{
		std::cerr << RED << " ❌ Error: bad input fields." << RESET << std::endl;
		std::cerr << YELLOW << "    => The input file should start with header 'date | value' in the first line.";
		std::cerr << RESET << std::endl;
		_inputFile.close(); 
		return;
	}

	size_t start = line.find_first_not_of(" \t");
	size_t end = line.find_last_not_of(" \t");

	if (start != std::string::npos && end != std::string::npos)
		line = line.substr(start, end - start + 1); // Trim the line
	else
	{
		std::cerr << RED << " ❌ Error: bad input fields." << RESET << std::endl;
		std::cerr << YELLOW << "    => The input file should start with header 'date | value' in the first line.";
		std::cerr << RESET << std::endl;
		_inputFile.close(); 
		return;
	}

	if (line != "date | value")
	{
		std::cerr << RED << " ❌ Error: bad input fields." << RESET << std::endl;
		std::cerr << YELLOW << "    => The input file should start with header 'date | value' in the first line.";
		std::cerr << RESET << std::endl;
		_inputFile.close(); 
		return;
	}
	else
	{
		std::cout << GREEN << " ✅ Input fields are correct.";
		std::cout << "\n" << RESET << std::endl;
	}
}

void BitcoinExchange::processInputFileLines()
{
	std::string date;
	std::string value;
	//std::string valueBeforeOne;
	size_t i;
	std::string line;

	while (getline(_inputFile, line))
	{
		while (1)
		{
			i = line.find("|");
			if (i == std::string::npos || i == line.size() - 1)
			{
				std::cerr << RED1 << "Error: bad input => " << line << RESET << std::endl;
				break;
			}
			date = line.substr(0, i - 1);
			//valueBeforeOne = line.substr(i + 1);
			value = line.substr(i + 1); //value = line.substr(i + 2);
			
			size_t start = value.find_first_not_of(" \t");
			size_t end = value.find_last_not_of(" \t");
			if (start != std::string::npos && end != std::string::npos) // Trim the value string for printing
				value = value.substr(start, end - start + 1);
			else
				value = "";

			if (!checkDateFormat(date))
			{
				std::cerr << RED1 << "Error: bad date => " << date << RESET << std::endl;
				break;
			}
			// if(!isspace(valueBeforeOne[0]))
			// {
			// 	std::cerr << RED1 << "Error: bad input => " << line << RESET << std::endl;
			// 	break;
			// }
			if (!checkBTCValue(value))
				break;
			execute(date, value);
			break;
		}
	}
}

// ========================================================================== //

void	BitcoinExchange::execute(std::string date, std::string value)
{
	double valueConverted = std::strtod(value.c_str(), NULL);
	std::cout << date << " => " << value << " = ";
	double foundValue = 0;
	std::map<std::string,double>::iterator it;
	for (it = _btcDataBase.begin(); it != _btcDataBase.end(); it++)
	{
		if ((date < it->first)) // date bigger > steps down 1 position
		{
			--it;
			foundValue = it->second;
			break ;
		}
	}
	if (it == _btcDataBase.end()) // date greater 
	{
		--it;
		foundValue = it->second;
	}
	double calc = 0;
	calc = foundValue * valueConverted;
	std::cout << calc << std::endl;
}

void BitcoinExchange::parsingInputFile(std::string file)
{
	if(!openInputFile(file))
		return ;
	checkInputFileHeader();
	processInputFileLines();
}

/*
The `std::map` is a data structure that stores elements in key-value pairs.
The keys are unique and the elements are automatically sorted by the key in
ascending order.

In the `_btcDataBase` is a `std::map` where the keys are strings (`std::string`)
and the values are double-precision floating-point numbers (`double`).

Here are some common operations you can perform on a `std::map`:

- **Insert elements**: You can insert a key-value pair into a `std::map` using the `insert()` 
function or the `[]` operator. For example, `_btcDataBase.insert(std::make_pair("2022-01-01", 45000.0));
`inserts the pair ("2022-01-01", 45000.0) into `_btcDataBase`.

- **Access elements**: You can access the value associated with a key using the `[]` operator.
For example, `_btcDataBase["2022-01-01"]` returns the value associated with the key "2022-01-01".

- **Remove elements**: You can remove an element from a `std::map` using the `erase()` function.
For example, `_btcDataBase.erase("2022-01-01");` removes the element with the key "2022-01-01"
from `_btcDataBase`.

- **Iterate over elements**: You can iterate over the elements of a `std::map` using an iterator.
In your code, `it` is an iterator that traverses the elements of `_btcDataBase`. `it->first` is the
key of the current element and `it->second` is the value of the current element.

- **Find elements**: You can find an element in a `std::map` using the `find()` function. For example,
`_btcDataBase.find("2022-01-01");` returns an iterator to the element with the key "2022-01-01", or
`_btcDataBase.end()` if the element is not found.
*/

/*
There are several data structures in C++ that can store elements in key-value pairs, in addition
to std::map.

==> std::unordered_map: It is similar to std::map, but it uses a hash table internally and
	therefore its insertion and lookup operations have an average constant time complexity.

==> std::multimap: Allows multiple values for a single key. It is a version of std::map that allow
	duplicate keys.

==> std::unordered_multimap: It is similar to std::multimap, but it uses a hash table internally
	and therefore its insertion and lookup operations have an average constant time complexity.

==> boost::bimap: If you are using the Boost library, boost::bimap allows a bidirectional mapping
	between keys and values, allowing you to use either as a key for the other.

==> std::pair: Although not a mapping data structure, std::pair can be used to store a key-value pair.
	However, you would have to manage the collection of pairs yourself, for example by storing them
	in a std::vector or std::list.
*/
