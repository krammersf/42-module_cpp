/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:05:29 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/22 13:15:33 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define GREY "\033[1;30m"
# define YELLOW "\033[1;33m"
# define YELLOW1 "\033[0;33m"
# define GREEN "\033[1;32m"
# define GREEN1 "\033[0;32m"
# define RED "\033[1;31m"
# define RED1 "\033[0;31m"
# define BLUE "\033[1;34m"
# define BLUE1 "\033[1;34m"
# define CYAN "\033[1;36m"
# define CYAN1 "\033[0;36m"
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
# include <climits> // for INT_MAX
# include <sstream> // for std::stringstream
# include <vector>
# include <list>
# include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> myVector;
		std::list<int> myList;
	
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &copy);

		void	checkInput(std::string input);
		void	printTimeTaken(const std::string& containerType, const size_t size, const double elapsed_time);
		void	fillContainer(std::vector<int> &myVector, std::list<int> &myList, std::string input);

		void	printSequenceVector(const std::string &text, const std::vector<int> &sequence);
		void	printSequenceList(const std::string &msg, const std::list<int> &sequence);
		
		void	sortVector(std::vector<int> &vector1);
		void	mergeVector(std::vector<int> &left, std::vector<int>&right, std::vector<int> &vector);
		
		void	sortList(std::list<int> &list1);
		void	mergeList(std::list<int> &left, std::list<int>&right, std::list<int> &list);
		
		void	sortAlgorithm(std::vector<int> &vector, std::list<int> &list);
};

#endif