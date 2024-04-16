/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:05:34 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/10 09:41:16 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
--> This function will convert the input to char, int, float and double
`static_cast` is a compile-time type casting operator in C++. It is used to convert
one type into another, similar to how you might convert a `float` to an `int` or a
base class pointer to a derived class pointer.

 static_cast<int>(f);
 int -> is the new tipe
 (f) -> is the value to be converted

The fractional part of `f` is discarded.

--> nan -> not a number
*/ 
void	Converter(long double input)
{
	{ // char
		if ((input < std::numeric_limits<char>::min() || input > std::numeric_limits<char>::max()))
			std::cout << std::setw(9) << "char: " << "impossible" << std::endl;
		else if (!isprint(input))
			std::cout << std::setw(9) << "char: " << "Non displayable" << std::endl;
		else
			std::cout << std::setw(10) << "char: '" << static_cast<char>(input) << "'" << std::endl;
	}

	{ // int
		if ((input < std::numeric_limits<int>::min() || input > std::numeric_limits<int>::max()))
			std::cout << std::setw(9) << "int: " << "impossible" << std::endl;
		else
			std::cout << std::setw(9) << "int: " << static_cast<int>(input) << std::endl;    
	}

	{ // float
		if ((input < -std::numeric_limits<float>::max() || input > std::numeric_limits<float>::max()))
			std::cout << std::setw(9) << "float: " << "impossible" << std::endl;
		else
		{
			if (input - static_cast<int>(input) == 0)
				std::cout << std::setw(9) << "float: " << static_cast<float>(input) << ".0f" << std::endl;
			else
				std::cout << std::setw(9) << "float: " << static_cast<float>(input) << "f" << std::endl;
		}
	}

	{ //double
		if ((input < -std::numeric_limits<double>::max() || input > std::numeric_limits<double>::max()))
			std::cout << std::setw(9) << "double: " << "impossible" << std::endl;
		else
		{
			if (input - static_cast<int>(input) == 0)
				std::cout << std::setw(9) << "double: " << static_cast<double>(input) << ".0" << std::endl;
			else
				std::cout << std::setw(9) << "double: " << static_cast<double>(input) << std::endl;
		}
	}
}

bool	isInt(std::string arg)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if ((arg[i] == '+' || arg[i] == '-') && i != 0)
			return (false);
		if (!isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-')
			return (false);
	}
	return (true);
}

bool	isFloat(std::string input)
{
	if (input[input.size() - 1] != 'f')
		return(false);
	if (input.find('.') == std::string::npos)
		return (false);
	if (input.find_first_of('.') != input.find_last_of('.'))
		return(false);
	for(size_t	i = 0; i < input.size() - 1; i++)
	{
		if (i == 0 && (input[0] == '-' && input[0] == '+'))
			continue;
		if (input[i] == '.')
			continue;
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool	isDouble(std::string input)
{
	if (input.find('.') == std::string::npos)
		return (false);
	if (input.find_first_of('.') != input.find_last_of('.'))
		return(false);
	for(size_t	i = 0; i < input.size(); i++)
	{
		if (i == 0 && (input[0] == '-' || input[0] == '+'))
			continue;
		if (input[i] == '.')
			continue;
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool	isPseudo(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

void	ContertPseudo(std::string input)
{
	std::cout << std::setw(19) << "char: impossible" << std::endl;
	std::cout << std::setw(19) << "int: impossible" << std::endl;
	std::cout << std::setw(9) << "float: " << input << "f" << std::endl;
	std::cout << std::setw(9) << "double: " << input << std::endl; 
}

bool	isPseudoF1(std::string input)
{
	if (input == "-inff" || input == "+inff")
		return (true);
	return (false);
}

void	ContertPseudoF1(std::string input)
{
	std::cout << std::setw(19) << "char: impossible" << std::endl;
	std::cout << std::setw(19) << "int: impossible" << std::endl;
	std::cout << std::setw(9) << "float: " << input << std::endl;
	std::cout << std::setw(9) << "double: " << input.substr(0, 4) << std::endl; 
}

void	ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		Converter(input[0]);
	else if (isPseudo(input))
		ContertPseudo(input);
	else if (isPseudoF1(input))
		ContertPseudoF1(input);
	else if (isInt(input) || isFloat(input) || isDouble(input))
		Converter(std::strtod(input.c_str(), NULL)); // std::strtod converts a string to a double
	else
		std::cerr << "Impossible conversion" << std::endl;
}
