/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:09:52 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/18 10:40:49 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

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
# include <iomanip>
# include <stack>
# include <list>

template <typename T> class MutantStack : public std::stack<T>
{
	public:

		MutantStack() : std::stack<T>()
		{
			std::cout << GREEN1 << "MutantStack created" << RESET << "\n" << std::endl;
		}

		virtual~MutantStack()
		{
			std::cout << RED1 << "\n" << "MutantStack destroyed" << RESET << "\n" << std::endl;
		}

		MutantStack(const MutantStack& copy) : std::stack<T>(copy)
		{
			std::cout << "MutantStack copied" << std::endl;
			*this = copy;
		}

		MutantStack &operator=(const MutantStack &copy)
		{
			std::cout << "MutantStack assigned" << std::endl;
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator begin()
		{
			return (std::stack<T>::c.begin());
		}
		
		iterator end()
		{
			return (std::stack<T>::c.end());
		}
};

#endif

/*
  A template class `MutantStack` that inherits from the `std::stack<T>` class from 
  the Standard Template Library (STL). 

  The `template <typename T>` part before the class declaration indicates that `MutantStack`
  is a template class that can work with any data type `T`. This means you can create a
  `MutantStack` of integers, doubles, strings, or any other type.

  The `: public std::stack<T>` part indicates that `MutantStack` is a derived class that
  inherits from the `std::stack<T>` base class. This means that `MutantStack` will have all
  the public and protected members (methods and variables) of `std::stack<T>`. 

  Inheritance is a fundamental concept in object-oriented programming. It allows you to define
  a class based on another class, which leads to code reusability and a logical, hierarchical
  class structure. In this case, `MutantStack` is a specialized version of `std::stack<T>`.
*/