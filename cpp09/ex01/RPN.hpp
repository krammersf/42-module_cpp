/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:28:30 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/20 00:11:28 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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
# include <cstdlib> // for atof()
# include <stack>

# include <sstream>

class RPN
{
	private:
		std::stack<int> stack;

	public:
		RPN();
		~RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &copy);

		void	errorManager(const std::string& message);
		void	clearStack();
		bool	checkInput(std::string input);
		void	doOperation(char input);
		void	execute(std::string input);
};

#endif