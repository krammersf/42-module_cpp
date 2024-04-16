/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:22:19 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 11:46:54 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; 

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;

	public:
		Form();
		Form(std::string const name, bool isSigned, int signGrade, int execGrade);
		Form(Form const &copy);
		~Form();

		Form &operator=(Form const &copy);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream& output, const Form& copy);

#endif
