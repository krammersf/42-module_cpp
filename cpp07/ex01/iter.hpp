/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:04:38 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/16 10:42:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

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
# include <iomanip> // for setw

template <typename T> void print(const T &x)
{
	std::cout << " [" << CYAN << x << RESET << "]";
}

template <typename T> void DoubleIncrement (T x)
{
	x *= 2;
	print(x);
}

template <typename T> void TenIncrement (T x)
{
	x += 10;
	print(x);
}

template <typename T> void Replace(T x)
{
	x = "fde-carv";
	print(x);
}

template <typename T> void iter(T *array, int size, void (*function)(const T&))
{
	for (int i = 0; i < size; i++)
		function(array[i]);
}

#endif

// template <typename T> void print(T x)
// {
// 	std::cout << " [" << CYAN << x << RESET << "]";
// }

// template <typename T> void DoubleIncrement (T x)
// {
// 	x *= 2;
// 	::print(x);
// }

// template <typename T> void TenIncrement (T x)
// {
// 	x += 10;
// 	::print(x);
// }

// template <typename T> void Replace(T x)
// {
// 	x = "fde-carv";
// 	::print(x);
// }

// template <typename T> void iter(T *array, int size, void (*fun)(T))
// {
// 	for (int i = 0; i < size; i++)
// 		fun(array[i]);
// }
