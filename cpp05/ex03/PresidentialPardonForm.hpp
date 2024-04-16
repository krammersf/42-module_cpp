/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:02:35 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/18 12:06:21 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		virtual ~PresidentialPardonForm();
		
		PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

		std::string  getTarget() const;

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
