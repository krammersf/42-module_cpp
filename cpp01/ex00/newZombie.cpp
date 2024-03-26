/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:23:32 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/19 10:54:46 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Dynamic memory allocation
Zombie	*newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	
	return (newZombie);
}
