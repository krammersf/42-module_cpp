/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:03:45 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/16 10:42:53 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

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

template <typename T> class Array
{
	private:
		T* _array;
		unsigned int _size;
		
	public:
		Array() :  _array(new T[0]), _size(0) //_array(NULL), _size(0)
		{
			std::cout << GREEN1 << "Creating an empty default Array (Default Contructor)." << RESET << std::endl; 
		}
		
		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			for (unsigned int i = 0; i < n; i++)
				_array[i] = T();
			std::cout << GREEN1 << "Creating Array with " << this->_size << " slots (Parameterized Constructor)." << RESET << std::endl;
		}
		
		Array(const Array &copy) : _array(new T[copy._size]), _size(copy._size)
		{
			std::cout << GREEN1 << "Create copy Array from 'copy' (Copy Constructor)." << RESET << std::endl; 
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
			*this = copy;
		}
		
		~Array()
		{
			std::cout << RED1 << "Destroing Array of " << std::setw(2);
			std::cout << this->_size << " slots (Destructor)." << RESET << std::endl;
			delete[] _array;
		}

		Array &operator=(const Array& copy)
		{
			std::cout << GREEN1 << "Assign Array to 'copy' (Assignation Operator Constructor)." << RESET << std::endl;
			if (this != &copy)
			{
				delete[] _array;
				_size = copy._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = copy._array[i];
			}
			return (*this);
		}

		T &operator[](unsigned int i)
		{
			if (i >= _size)
			{
				std::cout << GREEN1 << "Invalid access to slot " << i << " --> " << RESET;
				throw std::out_of_range("Slot out of range.");
			}
			return _array[i];
		}
	
		unsigned int size() const
		{ 
			return (this->_size);
		}
};

#endif
