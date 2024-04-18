/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:58:56 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/17 16:47:58 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define GREY "\033[1;30m"
# define YELLOW "\033[1;33m"
# define YELLOW1 "\033[0;33m"
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
# include <iomanip> // setw()
# include <vector> // vector
# include <algorithm> // sort()
# include <climits> // INT_MAX

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_v;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &copy);
		~Span();

		Span &operator=(Span const &copy);

		unsigned int const &getN() const;
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		void fillVector(std::vector<int>& vector, unsigned int size, unsigned int randomBase);

		class VectorFullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Vector is full!");
				}
		};

		class LowStoredNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Not enough numbers in vector!");
				}
		};
};

#endif
