/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:02:45 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 12:11:55 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream> // ofstream
# include "AForm.hpp"

class Bureaucret;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string   _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
