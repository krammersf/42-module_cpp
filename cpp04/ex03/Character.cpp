/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:23:25 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 09:52:02 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Character::Character() : _name("default"), _unequippedMateriasCount(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name), _unequippedMateriasCount(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character parameterized constructor called" << std::endl;    
}

Character::Character(Character const &copy) : _name(copy._name), _unequippedMateriasCount(0)
{
	for (int i = 0;  i < 4; i++)
		this->_inventory[i] = NULL;
	*this = copy;
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character destructor called" << std::endl;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ OPERATORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Character& Character::operator=(Character const &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
			if (_inventory[i])
				delete _inventory[i];
		for (int i = 0; i < 4; i++)
		{
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GET FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::string const &Character::getName() const
{
	return (this->_name);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid materia." << std::endl;
		return;
	}

	bool equipped = false;
	for (size_t i = 0; i < 4; i++)
	{
		if (m == _inventory[i])
		{
			std::cout << _name << " already has this materia equipped." << std::endl;
			return ;
		}
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equipped materia of type " << m->getType() << " on slot [" << i << "]." << std::endl;
			equipped = true;
			break ;
		}
	}

	if (!equipped)
	{
		if (_unequippedMateriasCount < 100)
		{
			_unequippedMaterias[_unequippedMateriasCount++] = m;
			std::cout << _name << "'s inventory is full. Materia of type " << m->getType() << " can't be equipped." << std::endl;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index for unequip. Can't unequip materias." << std::endl;
		return;
	}
	if (this->_inventory[idx])
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
		std::cout << this->_name << " unequipped slot [" << idx << "]." <<std::endl;
	}
	else
		std::cout << this->_name << "'s slot [" << idx << "] is already empty." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index in use. Can't use materias." << std::endl;
		return ;
	}
	else if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << "'s slot [" << idx << "] is empty." << std::endl;
		return ;
	}
	else
	{
		std::cout << _name << " ";
		this->_inventory[idx]->use(target);
	}
}

void Character::cleanup() 
{
	for (int i = 0; i < _unequippedMateriasCount; i++)
	{
		delete _unequippedMaterias[i];
		_unequippedMaterias[i] = NULL;
	}
	_unequippedMateriasCount = 0;
}
