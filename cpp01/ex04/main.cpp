/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/20 09:35:22 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit

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

typedef struct s_info
{
	int count;
}		t_info;

std::string findAndReplaceInLine(std::string s1, std::string s2, std::string line, t_info *info)
{
	std::string newLine;
	size_t startPosition = 0;

	while (1)
	{
		size_t foundPosition = line.find(s1, startPosition);
		if (foundPosition == std::string::npos)
			break;
		newLine += line.substr(startPosition, foundPosition - startPosition);
		newLine += s2;
		startPosition = foundPosition + s1.length();
		info->count++;
	}
	newLine += line.substr(startPosition);
	return (newLine);
}

void	checkFile(std::string filename)
{
	// Open the input file
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cout << RED << "Error: " << RESET << "Failed to open input file: " << filename << std::endl;
		exit (1);
	}

	// Open the output file
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cout << RED << "Error: " << RESET << "Failed to create output file: " << filename << ".replace" << std::endl;
		inputFile.close();
		exit (1);
	}
}

void 	replaceInFile(std::string filename, std::string s1, std::string s2)
{
   	t_info info;
	info.count = 0;
	
	std::ifstream inputFile(filename.c_str());
	checkFile(filename);
	std::ofstream outputFile((filename + ".replace").c_str());

	// checks if the file is empty
	if (inputFile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "\n" << filename <<" is an empty file." << std::endl;
		std::cout << GREEN <<"A new empty file was created: " << RESET;
		std::cout << filename << ".replace\n" << std::endl;
		inputFile.close();
		return ;
	}

	// Read the file line by line
	std::string line;
	while (std::getline(inputFile, line))
	{
		line = findAndReplaceInLine(s1, s2, line, &info);
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();

	if (info.count > 0)
	{	
		std::cout << GREEN <<"\nReplacement completed." << " It was used " << info.count << " times." << RESET;
		std::cout <<"\nCheck the file: ";
		std::cout << RESET << filename << ".replace\n" << std::endl;
	}
	else
	{
		std::cout << "\n'" << s1 << "' was not found in the file." << std::endl;
		std::cout << GREEN << "The original content was copied to: " << RESET << filename << ".replace\n" << std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << YELLOW << "Usage: " << RESET << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cout << RED << "Error: " << RESET << "s1 cannot be an empty string" << std::endl;
		return (1);
	}
	replaceInFile(filename, s1, s2);

	return (0);
}
