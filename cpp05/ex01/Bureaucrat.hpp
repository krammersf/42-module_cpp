/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:08:18 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/27 10:40:41 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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
# include "Form.hpp"
# pragma once

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();
		
		Bureaucrat &operator=(Bureaucrat const &copy);
		
		std::string const	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& copy);

#endif

/*
- **Nested Classes**:
	- `GradeTooHighException` and `GradeTooLowException`: These are exception classes
	that inherit from `std::exception`. They override the `what()` method, which should
	return a string describing the exception.
*/