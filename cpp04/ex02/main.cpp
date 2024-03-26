/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 10:09:43 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp" 
#include "WrongCat.hpp"
#include <iomanip>
#include "Brain.hpp"

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

void	test_polimorphism_array(void)
{
	titleHeader("Testing polimorphism with arrays");

	int	animalSize = 4;
	Animal*		animals[animalSize];
	//Animal test;

	subTitle("Creating animals array");
	for (int i = 0; i < animalSize; i++)
	{
		if (i < (animalSize / 2))
		{
			animals[i] = new Dog();
			std::cout << "[" << i << "] ";
			animals[i]->makeSound();
			std::cout << std::endl;
		}
		else
		{
			animals[i] = new Cat();
			std::cout << "[" << i << "] ";
			animals[i]->makeSound();
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	subTitle("Destroying animals array with polymorphism");
	for (int i = 0; i < animalSize; i++)
		delete animals[i];
}

void	test_deep_copy(void)
{
	titleHeader("Testing Deep Copy");

	{
		subTitle("Creating dog and temp dog");
		Dog	dog;
		Dog	temp = dog;
		std::cout << std::endl;
		subTitle("Using dog and temp dog");
		dog.makeSound();
		std::cout << "Dog brain: " << dog.getBrain() << std::endl;
		dog.getBrain()->addIdea("I'm a dog");
		dog.getBrain()->printIdeas();
		std::cout << "Temp ";
		temp.makeSound();
		temp.getBrain()->printIdeas();
		std::cout << "Temp dog brain: " << temp.getBrain() << std::endl;
		std::cout << std::endl;
		subTitle("Destroying dog and temp dog");
	}
	
	{
		std::cout << std::endl;
		subTitle("Creating cat and clone");
		Cat*	animal = new Cat();
		Cat*	clone = new Cat(*animal);
		std::cout << std::endl;
		subTitle("Using cat");
		animal->makeSound();
		animal->getBrain()->addIdea("I'm a cat");
		animal->getBrain()->printIdeas();
		std::cout << "Animal brain: " << animal->getBrain() << std::endl;
		std::cout << std::endl;
		subTitle("Using clone");
		clone->makeSound();
		clone->getBrain()->printIdeas();
		std::cout << "Clone brain: " << clone->getBrain() << std::endl;
		std::cout << std::endl;
		subTitle("Destroying cat and clone");
		delete animal;
		delete clone;
		std::cout << std::endl;
	}
}

int	main(void)
{
	std::cout << "\033c";
	test_polimorphism_array();
	std::cout << std::endl;
	std::cin.get();
	test_deep_copy();
	std::cout << std::endl;
	return (0);
}

/*
	// Example of the main function output:

	int main()
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
		...

		return 0;
	}
*/
