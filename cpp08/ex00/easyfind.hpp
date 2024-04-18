/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:30:37 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/15 13:56:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

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
# include <iomanip> // for std::setw
# include <list> // for std::list
# include <vector> // for std::vector
# include <deque> // for std::deque
# include <set> // for std::set
# include <algorithm> // for std::find for std::distance

template <typename T> void easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		std::cout << " " << RED << "NOT Found " << RESET << std::endl;
	else
	{
		int distance = std::distance(container.begin(), std::find(container.begin(), \
		container.end(), value));
		std::cout << " " << GREEN << "Found " << RESET << "--> " << "[";
		std::cout << CYAN <<*it << RESET << "]" << " in position " << distance << "." << std::endl;
	}
}

#endif
