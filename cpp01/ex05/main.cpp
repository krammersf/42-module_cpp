/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/02/07 08:43:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << std::endl;
	std::cout << "Debug Message from Harl: " << std::endl;
	harl.complain("debug");
	std::cout << std::endl;
	std::cout << "Info Message from Harl: " << std::endl;
	harl.complain("info");
	std::cout << std::endl;
	std::cout << "Warning Message from Harl: " << std::endl;
	harl.complain("warning");
	std::cout << std::endl;
	std::cout << "Error Message from Harl: " << std::endl;
	harl.complain("error");
	std::cout << std::endl;
}
