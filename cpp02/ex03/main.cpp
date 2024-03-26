/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/25 11:18:30 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Check if all points are distinct and not collinear
bool isTriangle(const Point& a, const Point& b, const Point& c)
{
	if ((a.getX()*(b.getY()-c.getY()) + b.getX()*(c.getY()-a.getY()) + \
		c.getX()*(a.getY()-b.getY())) == 0) 
		return (false);

	return (true);
}

char	**createGrid(int height, int width)
{
	char** grid = new char*[height];
	
	for (int i = 0; i < height; i++)
		grid[i] = new char[width];
	return (grid);
}

void	deleteGrid(char** grid, int height)
{
	for (int i = 0; i < height; i++)
		delete[] grid[i];
	delete[] grid;
}

// Bresenham's line algorithm
void drawLine(char** grid, Point p1, Point p2, char fill, int minX, int minY, int width, int height)
{
	int x0 = p1.getX().toInt() - minX;
	int y0 = p1.getY().toInt() - minY;
	int x1 = p2.getX().toInt() - minX;
	int y1 = p2.getY().toInt() - minY;

	int dx = abs(x1 - x0);
	int	sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int	sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (true)
	{
		if (x0 >= 0 && x0 < width && y0 >= 0 && y0 < height)
			grid[y0][x0] = fill;
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void drawTriangle(Point a, Point b, Point c, Point p)
{
	char fill = 'O';
	char vertex = '0';
	char empty = '.';
	
	Fixed minX = Fixed::min(Fixed::min(a.getX(), b.getX()), Fixed::min(c.getX(), p.getX()));
	Fixed maxX = Fixed::max(Fixed::max(a.getX(), b.getX()), Fixed::max(c.getX(), p.getX()));
	Fixed minY = Fixed::min(Fixed::min(a.getY(), b.getY()), Fixed::min(c.getY(), p.getY()));
	Fixed maxY = Fixed::max(Fixed::max(a.getY(), b.getY()), Fixed::max(c.getY(), p.getY()));
	
	int width = maxX.toInt() - minX.toInt() + 3;
	int height = maxY.toInt() - minY.toInt() + 3;

	char **grid = createGrid(height, width);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (bsp(a, b, c, Point(x + minX.toInt(), y + minY.toInt())))
				grid[y][x] = fill;
			else
				grid[y][x] = empty;
		}
	}

	drawLine(grid, a, b, vertex, minX.toInt(), minY.toInt(), width, height);
	drawLine(grid, b, c, vertex, minX.toInt(), minY.toInt(), width, height);
	drawLine(grid, c, a, vertex, minX.toInt(), minY.toInt(), width, height);

	std::cout << "  ";
	for (int x = 0; x < width - 2; x++)
		std::cout << WHITE << std::setfill('0') << std::setw(2) << (x + minX.toInt()) << " " << RESET;
	std::cout << std::endl;
	for (int y = 0; y < height - 2; y++)
	{
		std::cout << WHITE << std::setfill('0') << std::setw(2) << (y + minY.toInt()) << " " << RESET;
		for (int x = 0; x < width - 2; x++)
		{
			if ((Fixed)x + minX == p.getX() && (Fixed)y + minY == p.getY() && grid[y][x] == fill)
				std::cout << GREEN << "Y  " << RESET;
			else if ((Fixed)x + minX == p.getX() && (Fixed)y + minY == p.getY() && grid[y][x] != fill)
				std::cout << RED << "N  " << RESET;
			else if (grid[y][x] == fill)
				std::cout << YELLOW << grid[y][x] << "  " << RESET;
			else if (grid[y][x] == vertex)
				std::cout << CYAN << grid[y][x] << "  " << RESET;
			else
				std::cout << WHITE << grid[y][x] << "  " << RESET;
		}
		std::cout << std::endl;
	}
	deleteGrid(grid, height);
}

int	main (void)
{
	{
		Point const a(2,2);
		Point const b(8,2);
		Point const c(5,5);
		Point const p(5,3);

		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << " A (" << a.getX() << "," << a.getY() << ")" << std::endl;
		std::cout << " B (" << b.getX() << "," << b.getY() << ")" << std::endl;
		std::cout << " C (" << c.getX() << "," << c.getY() << ")" << std::endl;
		std::cout << " P (" << p.getX() << "," << p.getY() << ")" << std::endl;
		std::cout << std::endl;

		if (!isTriangle(a, b, c))
			std::cout << RED1 <<" --> It is not a" << RED << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;
		else
			std::cout << GREEN1 <<" --> It is a" << GREEN << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;

		if (bsp(a, b , c, p))
			std::cout << GREEN1 << " --> The point is" << GREEN << SBLINK <<" INSIDE" << GREEN1 << " the triangle!" << RESET << std::endl;
		else
			std::cout << RED1 <<" --> The point is" << RED << SBLINK << " NOT INSIDE" << RED1 << " the triangle!"<< RESET << std::endl;
		std::cout << std::endl;

		drawTriangle(a, b, c, p);
		std::cout << std::endl;	
	}

	{
		Point const a(0,0);
		Point const b(6,0);
		Point const c(3,3);
		Point const p(0,9);

		std::cin.get();
		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << " A (" << a.getX() << "," << a.getY() << ")" << std::endl;
		std::cout << " B (" << b.getX() << "," << b.getY() << ")" << std::endl;
		std::cout << " C (" << c.getX() << "," << c.getY() << ")" << std::endl;
		std::cout << " P (" << p.getX() << "," << p.getY() << ")" << std::endl;
		std::cout << std::endl;

		if (!isTriangle(a, b, c))
			std::cout << RED1 <<" --> It is not a" << RED << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;
		else
			std::cout << GREEN1 <<" --> It is a" << GREEN << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;

		if (bsp(a, b , c, p))
			std::cout << GREEN1 << " --> The point is" << GREEN << SBLINK <<" INSIDE" << GREEN1 << " the triangle!" << RESET << std::endl;
		else
			std::cout << RED1 <<" --> The point is" << RED << SBLINK << " NOT INSIDE" << RED1 << " the triangle!"<< RESET << std::endl;
		std::cout << std::endl;

		drawTriangle(a, b, c, p);
		std::cout << std::endl;	
	}

	{
		Point const a(0,0);
		Point const b(12,0);
		Point const c(12,12);
		Point const p(12,12);

		std::cin.get();
		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << " A (" << a.getX() << "," << a.getY() << ")" << std::endl;
		std::cout << " B (" << b.getX() << "," << b.getY() << ")" << std::endl;
		std::cout << " C (" << c.getX() << "," << c.getY() << ")" << std::endl;
		std::cout << " P (" << p.getX() << "," << p.getY() << ")" << std::endl;
		std::cout << std::endl;

		if (!isTriangle(a, b, c))
			std::cout << RED1 <<" --> It is not a" << RED << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;
		else
			std::cout << GREEN1 <<" --> It is a" << GREEN << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;

		if (bsp(a, b , c, p))
			std::cout << GREEN1 << " --> The point is" << GREEN << SBLINK <<" INSIDE" << GREEN1 << " the triangle!" << RESET << std::endl;
		else
			std::cout << RED1 <<" --> The point is" << RED << SBLINK << " NOT INSIDE" << RED1 << " the triangle!"<< RESET << std::endl;
		std::cout << std::endl;

		drawTriangle(a, b, c, p);
		std::cout << std::endl;	
	}
	
	{
		Point const a(0,0);
		Point const b(8,0);
		Point const c(4,4);
		Point const p(4,0);

		std::cin.get();
		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << " A (" << a.getX() << "," << a.getY() << ")" << std::endl;
		std::cout << " B (" << b.getX() << "," << b.getY() << ")" << std::endl;
		std::cout << " C (" << c.getX() << "," << c.getY() << ")" << std::endl;
		std::cout << " P (" << p.getX() << "," << p.getY() << ")" << std::endl;
		std::cout << std::endl;

		if (!isTriangle(a, b, c))
			std::cout << RED1 <<" --> It is not a" << RED << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;
		else
			std::cout << GREEN1 <<" --> It is a" << GREEN << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;

		if (bsp(a, b , c, p))
			std::cout << GREEN1 << " --> The point is" << GREEN << SBLINK <<" INSIDE" << GREEN1 << " the triangle!" << RESET << std::endl;
		else
			std::cout << RED1 <<" --> The point is" << RED << SBLINK << " NOT INSIDE" << RED1 << " the triangle!"<< RESET << std::endl;
		std::cout << std::endl;

		drawTriangle(a, b, c, p);
		std::cout << std::endl;	
		std::cin.get();
		std::cout << "\033c";
	}

	{
		Point const a(0,0);
		Point const b(0,0);
		Point const c(0,0);
		Point const p(3,2);

		std::cout << "\033c";
		std::cout << std::endl;
		std::cout << " A (" << a.getX() << "," << a.getY() << ")" << std::endl;
		std::cout << " B (" << b.getX() << "," << b.getY() << ")" << std::endl;
		std::cout << " C (" << c.getX() << "," << c.getY() << ")" << std::endl;
		std::cout << " P (" << p.getX() << "," << p.getY() << ")" << std::endl;
		std::cout << std::endl;

		if (!isTriangle(a, b, c))
			std::cout << RED1 <<" --> It is not a" << RED << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;
		else
			std::cout << GREEN1 <<" --> It is a" << GREEN << SBLINK << " TRIANGLE!"  << RESET << "\n" << std::endl;

		if (bsp(a, b , c, p))
			std::cout << GREEN1 << " --> The point is" << GREEN << SBLINK <<" INSIDE" << GREEN1 << " the triangle!" << RESET << std::endl;
		else
			std::cout << RED1 <<" --> The point is" << RED << SBLINK << " NOT INSIDE" << RED1 << " the triangle!"<< RESET << std::endl;
		std::cout << std::endl;

		drawTriangle(a, b, c, p);
		std::cout << std::endl;	
	}
	return (0);
}
