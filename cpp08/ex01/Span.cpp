/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:58:59 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/18 10:22:59 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &copy) : _N(copy._N), _v(copy._v)
{
	*this = copy;
}

Span::~Span() {}

Span &Span::operator=(Span const &copy)
{
	if (this != &copy)
	{
		_v.clear();
		_N = copy._N;
		_v = copy._v;
	}
	return (*this);
}

// ========================================================================== //

unsigned int const &Span::getN() const
{
	return (this->_N);
}

void Span::addNumber(int number)
{
	if (_v.size() < _N)
		_v.push_back(number);
	else
		throw VectorFullException();
}

int Span::shortestSpan() const
{
	if (_v.size() < 2)
		throw LowStoredNumbersException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min = INT_MAX;
	std::vector<int>::iterator it;
	for (it = v.begin(); it != v.end() - 1; it++)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}

int Span::longestSpan() const
{
	if (_v.size() < 2)
		throw LowStoredNumbersException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return (v.back() - v.front());
}

void	Span::fillVector(std::vector<int> &vector, unsigned int _N, unsigned int randomBase)
{
	while (vector.size() < _N)
	{
		int randomNumber = std::rand() % randomBase;
		vector.push_back(randomNumber);
		this->addNumber(randomNumber);
	}
	for (unsigned int i = 0; i < _v.size(); i++)
		std::cout << " [" << CYAN << _v[i] << RESET << "] ";
}
