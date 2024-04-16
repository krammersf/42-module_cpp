/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:02:40 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 12:10:32 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <cstdlib> // rand
# include <ctime> // time

class RobotomyRequestForm : public AForm
{
	private:
		std::string   _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
