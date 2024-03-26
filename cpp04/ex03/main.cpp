/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/03/26 10:05:35 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

// class NotCharacter : public ICharacter
// {
// 	private:
// 		std::string name;
// 	public:
// 		NotCharacter() : name("NotCharacter") {}
// 		~NotCharacter() {}
// 		std::string const &getName() const { return name; }
// 		void equip(AMateria* ) {}
// 		void unequip(int ) {}
// 		void use(int , ICharacter& ) {}
// };

void titleHeader(const std::string& message)
{
	std::cout << "\033c";
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

int main()
{
	titleHeader("SUBJECT TEST");

	int indexCreateAndEquip = 5;
	int indexUseAndUnequip = indexCreateAndEquip + 0;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cin.get();

	// ----------------------------------------------------------- //
	titleHeader("MY TESTS");

	subTitle("CALLING MATERIASOURCE CONSTRUCTOR");
	IMateriaSource *newSrc = new MateriaSource();
	newSrc->learnMateria(new Ice());
	newSrc->learnMateria(new Cure());
	std::cin.get();

	subTitle("CREATE CHARACTERS");
	ICharacter *fred = new Character("Fred");
	std::cout << fred->getName() << std::endl;
	ICharacter *rodrigo = new Character("Rodrigo");
	std::cout << rodrigo->getName() << std::endl;
	std::cin.get();

	subTitle("CREATE AND EQUIP MATERIAS");
	if(indexCreateAndEquip > 100)
	{
		std::cout << RED << "Index for creating and equipping materias is too large.";
		std::cout << "\n" "The program will terminate. Try with an index less than 100." << RESET;
		std::cout << "\n" << GREEN << "Thanks for understanding...! 😀 " << RESET << std::endl;
		std::cin.get();
		delete fred;
		delete rodrigo;
		delete newSrc;
		std::cout << std::endl;
		return (1);
	}
	std::cout << "Creating a index of: " << indexCreateAndEquip << "\n" <<std::endl;
	AMateria *buffer;
	for (int i = 0; i < indexCreateAndEquip; i++)
	{
		if (i > 0)
			std::cout << std::endl;
		std::cout << "Materia #" << i + 1 << ": ";
		if (i % 2 == 0)
			buffer = newSrc->createMateria("cure");
		else
			buffer = newSrc->createMateria("ice");
		fred->equip(buffer);
	}
	std::cin.get();

	subTitle("USE MATERIAS");
	std::cout << "In \"CREATE AND EQUIP MATERIAS\" was used a index of: " << indexCreateAndEquip << std::endl;
	std::cout << "\"USE MATERIAS\" with an index of: " << indexUseAndUnequip << "\n" << std::endl;
	for (int i = 0; i < (indexUseAndUnequip); i++)
		fred->use(i, *rodrigo);
	std::cin.get();

	subTitle("UNEQUIP MATERIAS");
	std::cout << "In \"CREATE AND EQUIP MATERIAS\" was used a index of: " << indexCreateAndEquip << std::endl;
	std::cout << "\"UNEQUIP MATERIAS\" with an index of: " << indexUseAndUnequip << "\n" << std::endl;
	for (int i = 0; i < (indexUseAndUnequip); i++)
		fred->unequip(i);
	std::cin.get();

	subTitle("DELETE OBJECTS");
	// Delete caracter objects and free unequippedMaterias
	// NotCharacter *notCharacter = new NotCharacter(); // <--
	// delete fred; // <--
	// fred = notCharacter; // <--
	Character* characterToClean = dynamic_cast<Character*>(fred);
	if (characterToClean != NULL)
	{
		characterToClean->cleanup();
		delete fred;
	} 
	else
		std::cout << RED << fred->getName() << " is not a Character object." << RESET << std::endl;
	delete rodrigo;
	std::cin.get();

	subTitle("DELETE MATERIASOURCE OBJECT");
	//delete notCharacter; // <--
	delete newSrc;
	std::cin.get();

	// ----------------------------------------------------------- //
	titleHeader("DEEP COPY TEST");

	subTitle("CREATING A NEW MATERIASOURCES AND LEARNING MATERIAS");
	MateriaSource *Src1 = new MateriaSource();
	Src1->learnMateria(new Ice());
	Src1->learnMateria(new Cure());
	std::cin.get();

	subTitle("CREATING 2 NEW ICE OBJECT WITH COPY CONSTRUCTOR");
	Ice *basic = new Ice();
	Ice *temp = new Ice(*basic);
	std::cout << std::endl << "temp : " << temp << " | type: " << temp->getType() << std::endl;
	delete temp;
	std::cout << std::endl << "basic: " << basic << " | type: " << basic->getType() << std::endl;
	delete basic;
	std::cin.get();

	subTitle("CREATING A NEW MATERIASOURCES WITH COPY CONSTRUCTOR");
	MateriaSource *Src2 = new MateriaSource(*Src1);
	std::cout << std::endl;
	std::cout << "Old : " << Src1 << std::endl;
	std::cout << "New : " << Src2 << std::endl;
	std::cin.get();
	
	subTitle("DELETING OBJECTS");
	delete Src1;
	delete Src2;
	std::cin.get();

	return (0);
}

/*
	// Example of the main function output:

	int main()
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
		
		return 0;
	}
*/

/*
	// Example of the main function output:
	
	$> clang++ -W -Wall -Werror *.cpp
	$> ./a.out | cat -e
	* shoots an ice bolt at bob *$
	* heals bob's wounds *$
*/
