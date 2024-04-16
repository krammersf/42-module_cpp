/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:22:19 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 13:41:38 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; 

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;
	
	public:
		AForm();
		AForm(std::string const name, int signGrade, int execGrade);
		AForm(AForm const &copy);
		virtual ~AForm();
		
		AForm &operator=(AForm const &copy);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& output, const AForm& copy);

#endif
