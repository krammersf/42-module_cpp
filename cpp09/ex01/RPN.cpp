/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:05 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/22 13:09:02 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

	RPN::RPN() {}

	RPN::~RPN() {}

	RPN::RPN(RPN const &copy) : stack(copy.stack)
	{
		*this =copy;
	}
	
	RPN &RPN::operator=(RPN const &copy)
	{
		if(this != &copy)
			stack = copy.stack;
		return (*this);
	}

// ========================================================================== //

void	RPN::errorManager(const std::string& message)
{
	std::cerr << "\n" << RED << " Error: " << RED1 << message << std::endl;
	std::cerr << RESET << std::endl;
	clearStack();
}

void	RPN::clearStack()
{
	while (!stack.empty())
	{
		stack.pop();
	}
}

bool	RPN::checkInput(std::string input)
{
	for(size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' \
			|| input[i] == '/' || input[i] == ' ' || isdigit(input[i]))
			continue;
		else
		{
			errorManager("Invalid input.");
			return (false);
		}
	}
	return (true);
}

void	RPN::doOperation(char input)
{
	int num2 = stack.top();
	stack.pop();
	int num1 = stack.top();
	stack.pop();
	int result;

	if(input == '+')
	{
		result = num1 + num2;
		stack.push(result);
	}
	else if(input == '-')
	{
		result = num1 - num2;
		stack.push(result);
	}
	else if(input == '*')
	{
		result = num1 * num2;
		stack.push(result);
	}
	else if(input == '/')
	{
		if(num2 == 0)
		{
			errorManager("Division by zero.");
			return ;
		}
		result = num1 / num2;
		stack.push(result);
	}
}

void RPN::execute(std::string input)
{
	if (!checkInput(input))
		return;

	std::istringstream stringToStream(input); // Declare and initialize strintToStream (1)(2)
	std::string line; // line (1)
	while (std::getline(stringToStream, line)) // reads a line from the input (1)
	{ // (1)_
		std::istringstream lineStream(line); // streams the line (1)
		std::string token; // (1)(2)
		//while (stringToStream >> token) // (2)
		while (std::getline(lineStream, token, ' ')) // splits the line into tokens (1)
		{
			bool isWhitespace = true;
			for (unsigned int i = 0; i < token.size(); ++i)
			{
				if (token[i] != ' ')
				{
					isWhitespace = false;
					break;
				}
			}
			if(isWhitespace)
				continue ;

			if(token.size() > 1)
			{
				errorManager(" Invalid number size.");
				return ;
			}
			
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				if (stack.size() < 2)
				{
					errorManager("Not enough numbers to execute an operation.");
					return;
				}
				doOperation(token[0]);
			}
			else
				stack.push(std::atof(token.c_str()));

			if (stack.empty())
				return ;
		} // (1)
	}

	if (stack.size() > 1)
	{
		errorManager("Not enough operator(s).");
		return ;
	}

	std::cout << "\n" << GREEN << stack.top() << "\n" << RESET << std::endl;
	stack.pop();
}
