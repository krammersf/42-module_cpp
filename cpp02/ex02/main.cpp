/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/25 11:17:14 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	test_comparasions()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	
	std::cout << "a > b is " << ((a > b) == 0 ? "false" : "true") << std::endl;
	std::cout << "a < b is " << ((a < b) == 0 ? "false" : "true") << std::endl;
	std::cout << "a >= b is " << ((a >= b )== 0 ? "false" : "true") << std::endl;
	std::cout << "a <= b is " << ((a <= b) == 0 ? "false" : "true") << std::endl;
	std::cout << "a == b is " << ((a == b) == 0 ? "false" : "true") << std::endl;
	std::cout << "a != b is " << ((a != b) == 0 ? "false" : "true") << std::endl;

	std::cout << "a > c is " << ((a > c) == 0 ? "false" : "true") << std::endl;
	std::cout << "a < c is " << ((a < c) == 0 ? "false" : "true") << std::endl;
	std::cout << "a >= c is " << ((a >= c) == 0 ? "false" : "true") << std::endl;
	std::cout << "a <= c is " << ((a <= c )== 0 ? "false" : "true") << std::endl;
	std::cout << "a == c is " << ((a == c) == 0 ? "false" : "true") << std::endl;
	std::cout << "a != c is " << ((a != c) == 0 ? "false" : "true") << std::endl;

	std::cout << "b > c is " << ((b > c) == 0 ? "false" : "true") << std::endl;
	std::cout << "b < c is " << ((b < c) == 0 ? "false" : "true") << std::endl;
	std::cout << "b >= c is " << ((b >= c) == 0 ? "false" : "true") << std::endl;
	std::cout << "b <= c is " << ((b <= c) == 0 ? "false" : "true") << std::endl;
	std::cout << "b == c is " << ((b == c) == 0 ? "false" : "true") << std::endl;
	std::cout << "b != c is " << ((b != c) == 0 ? "false" : "true") << "\n" << std::endl;
}

void	test_arithmetic()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "a + b is " << (a + b) << std::endl;
	std::cout << "a - b is " << (a - b) << std::endl;
	std::cout << "a * b is " << (a * b) << std::endl;
	std::cout << "a / b is " << (a / b) << std::endl;

	std::cout << "a + c is " << (a + c) << std::endl;
	std::cout << "a - c is " << (a - c) << std::endl;
	std::cout << "a * c is " << (a * c) << std::endl;
	std::cout << "a / c is " << (a / c) << std::endl;

	std::cout << "b + c is " << (b + c) << std::endl;
	std::cout << "b - c is " << (b - c) << std::endl;
	std::cout << "b * c is " << (b * c) << std::endl;
	std::cout << "b / c is " << (b / c) << "\n" << std::endl;
}

void	test_increment_decrement()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;

	std::cout << "--b is " << --b << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "b-- is " << b-- << std::endl;
	std::cout << "b is " << b << std::endl;

	std::cout << "++c is " << ++c << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "c++ is " << c++ << std::endl;
	std::cout << "c is " << c << "\n" << std::endl;
}

void	test_min_max()
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(20);
	Fixed const d(30);
	Fixed const e(40);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) is " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, c) is " << Fixed::min(a, c) << std::endl;
	std::cout << "max(a, c) is " << Fixed::max(a, c) << std::endl;
	std::cout << "min(d, e) is " << Fixed::min(d, e) << std::endl;
	std::cout << "max(d, e) is " << Fixed::max(d, e) << std::endl;
}

void	subTitle(const std::string& message)
{
	std::cout << "\033[1;33m" << ">>> " << message << "\033[0m" <<"\n" << std::endl;
}

int main(void)
{
	std::cout << "\033c";
	std::cout << std::endl;
	subTitle("Subject Test");
	Fixed	a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;

	std::cin.get();
	std::cout << std::endl;

	subTitle("Comparaion Test");
	test_comparasions();
	std::cin.get();
	
	subTitle("Aritthmetic Test");
	test_arithmetic();
	std::cin.get();

	subTitle("Increment Test");
	test_increment_decrement();
	std::cin.get();
	
	subTitle("Min or Max Test");
	test_min_max();
	std::cout << std::endl;
	
	return (0);
}

/*
	The exercise output is: (Subject Test)

	$> ./a.out
	0
	0.00390625
	0.00390625
	0.00390625
	0.0078125
	10.1016
	10.1016
	$>
*/
