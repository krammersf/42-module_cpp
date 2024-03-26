/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/24 11:43:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp" 
#include "WrongCat.hpp"
#include <iomanip>

void titleHeader(const std::string& message)
{
    int standartSize = 60;
    int messageSize = message.length();
    int spacesBefore = (standartSize - messageSize) / 2 + messageSize;
    int spacesAfter = (standartSize - messageSize) / 2 + 1 + messageSize % 2;

    std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET_BG << std::endl;
    std::cout << BG_BLUE << "|" << std::setw(spacesBefore) << message << RESET_BG;
    std::cout << BG_BLUE << std::setw(spacesAfter) << "|" << RESET_BG << std::endl;
    std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET_BG << std::endl;
	std::cin.get();
}

void	subTitle(const std::string& message)
{
	std::cout << YELLOW << ">>> " << message << RESET <<"\n" << std::endl;
}

int	main(void)
{
	{
		std::cout << "\033c";
		titleHeader("Subject Test");

		subTitle("Creating Animals");
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;

		subTitle("Using Animals");
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		subTitle("Testing MakeSound");
		meta->makeSound();
		i->makeSound();
		j->makeSound();

		std::cout << std::endl;
		subTitle("Destroying Animals");
		delete meta;
		delete j;	
		delete i;
		std::cin.get();
	}
	
	{
		titleHeader("My Test");

		subTitle("Creating Animals");
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		std::cout << std::endl;

		subTitle("Using Animals");
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;

		subTitle("Testing MakeSound");
		meta->makeSound();
		j->makeSound();
		i->makeSound();

		std::cout << std::endl;
		subTitle("Destroying Animals");
		delete meta;
		delete j;	
		delete i;
		std::cin.get();
	}

	{
		titleHeader("Copy Test");

		subTitle("Creating Dog");
		const Animal* dog = new Dog();
		std::cout << std::endl;
		subTitle("Creating Dog Pointer Copy");
		const Animal* copy = dog;
		std::cout << "Copy type: " << copy->getType() << "\n" << std::endl;
		subTitle("Testing MakeSound Pointer Copy");
		copy->makeSound();
		std::cout << std::endl;
		subTitle("Destroying Dog");
		delete dog;
		std::cout << std::endl;
	}
	return (0);
}

/*
	// Example of the main function output:

	int main()
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		...
	}
	return 0;
*/
