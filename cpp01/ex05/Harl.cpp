/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:09:35 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/19 10:59:43 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::_Debug(void)
{
	std::cout << "\033[1;33mI love having extra bacon for my 7XL-double-cheese";
	std::cout << "-triple-pickle-specialketchup burger. I really do!\033[0m" << std::endl;
}

void	Harl::_Info(void)
{
	std::cout << "\033[1;33mI cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!\033[0m" << std::endl;
}

void	Harl::_Warning(void)
{
	std::cout << "\033[1;33mI think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\033[0m" << std::endl;
}

void	Harl::_Error(void)
{
	std::cout << "\033[1;33mThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*array[4])(void) = {&Harl::_Debug, &Harl::_Info, &Harl::_Warning, &Harl::_Error};
	std::string levels[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			(this->*array[i])();
}
