/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:21:48 by fde-carv          #+#    #+#             */
/*   Updated: 2024/04/15 18:34:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void titleHeader(const std::string& message)
{
	std::cout << "\033c";
	int standartSize = 60;
	int messageSize = message.length();
	int spacesBefore = (standartSize - messageSize) / 2 + messageSize;
	int spacesAfter = (standartSize - messageSize) / 2 + 1 + messageSize % 2;

	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << RESET_BG << std::endl;
	std::cout << BG_BLUE << "|" << std::setw(spacesBefore) << message << RESET_BG;
	std::cout << BG_BLUE << std::setw(spacesAfter) << "|" << RESET_BG << std::endl;
	std::cout << BG_BLUE << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << RESET_BG << std::endl;
}

void	subTitle(const std::string& message)
{
	std::cout << YELLOW << ">>> " << message << RESET << "\n" << std::endl;
}

int main(void)
{
	titleHeader("Mutated Abomination");
	std::cin.get();

	{
		subTitle("Subject Test");
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}


	{
		std::cin.get();
		subTitle("Mutant Stack Test");
		MutantStack<int> mstack;


		std::cout << " Insert values on stack: ";;
		mstack.push(3); // insert value
		mstack.push(19);
		mstack.push(189);
		mstack.push(23);
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) // begin() points to the first element
			std::cout << CYAN << "[" << RESET << *it << CYAN << "] " << RESET;
		std::cout << "\n" << std::endl;


		std::cout << " Top value" << std::setw(9) << ": " << mstack.top() << std::endl; // top value = last value inserted
		std::cout << " Stack size" << std::setw(8) <<  ": " << mstack.size() << "\n" << std::endl;
		std::cout <<" Remove top value" << std::setw(2) << ": " << mstack.top() << std::endl;
		mstack.pop(); // remove top value
		std::cout << " New top value" << std::setw(5) << ": " << mstack.top() << std::endl;
		std::cout << " Stack size" << std::setw(8) <<  ": " << mstack.size() << "\n" << std::endl;


		unsigned int partialSize = mstack.size();
		std::cout << " Insert values on stack: ";
		mstack.push(44);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		unsigned int numElementsToPrint = mstack.size() - partialSize;
		int startIndex = (mstack.size() >= numElementsToPrint) ? (mstack.size() - numElementsToPrint) : 0;
		for (MutantStack<int>::iterator it = mstack.begin() + startIndex; it != mstack.end(); ++it)
			std::cout << CYAN << "[" << RESET << *it << CYAN << "] " << RESET;
		std::cout << std::endl;


		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "\n" << " Printing all values on stack using iterator: ";
		while (it != ite)
		{
			std::cout << CYAN << "[" << RESET << *it << CYAN << "] " << RESET;
			++it;
		}
		std::cout << "\n" << std::endl;


		std::cout << " Copy the Mutant Stack to another common Stack." << "\n" << std::endl;
		std::stack<int> fred(mstack);


		std::cout << " Delete all values on the stack:" << std::endl;
		std::cout << RED << " ... deleting: " << RESET;
		MutantStack<int>::iterator itEnd;
		while (!mstack.empty())
		{
			itEnd = mstack.end();
			--itEnd;
			std::cout << CYAN << "[" << RESET << *itEnd << CYAN << "] " << RESET; 
			if (mstack.size() > 1)
				std::cout << "--> ";
			mstack.pop();
		}
		std::cout << "\n" << " ... stack is " << RED << "EMPTY." << RESET << std::endl;


		std::cout << "\n" << " Printing copy of the stack: ";
		while (!fred.empty())
		{
			std::cout << CYAN << "[" << RESET << fred.top() << CYAN << "] " << RESET; // prints last value inserted and deletes it, so printts in reverse order
			fred.pop();
		}
		std::cout << std::endl;
	}


	{
		std::cin.get();
		subTitle("Mutant Stack Test but with a List");
		std::list<int> list;


		std::cout << " Insert values on list: ";;
		list.push_back(3);
		list.push_back(19);
		list.push_back(189);
		list.push_back(23);
		for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
			std::cout << CYAN << "[" << RESET << *it << CYAN << "] " << RESET;
		std::cout << "\n" << std::endl;


		std::cout << " Top value" << std::setw(9) << ": " << list.back() << std::endl;
		std::cout << " List size" << std::setw(9) <<  ": " << list.size() << "\n" << std::endl;
		std::cout <<" Remove top value" << std::setw(2) << ": " << list.back() << std::endl;
		list.pop_back();
		std::cout << " New top value" << std::setw(5) << ": " << list.back() << std::endl;
		std::cout << " List size" << std::setw(9) <<  ": " << list.size() << "\n" << std::endl;


		unsigned int partialSize = list.size();
		std::cout << " Insert values on list: ";
		list.push_back(44);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		unsigned int numElementsToPrint = list.size() - partialSize;
		int startIndex = (list.size() >= numElementsToPrint) ? list.size() - numElementsToPrint : 0;
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		//std::advance(it, startIndex);
		for (std::advance(it, startIndex); it != list.end(); ++it)
			std::cout << CYAN << "[" << RESET << *it << CYAN << "] " << RESET;
		std::cout << std::endl;


		it = list.begin();
		std::cout << "\n" << " Printing all values on list using iterator: ";
		while (it != ite)
		{
			std::cout << CYAN << "[" << RESET << *it << CYAN << "] " << RESET;
			++it;
		}
		std::cout << "\n" << std::endl;


		std::cout << " Copy the List to another common List." << "\n" << std::endl;
		std::list<int> fred(list);


		std::cout << " Delete all values on the list:" << std::endl;
		std::cout << RED << " ... deleting: " << RESET;;
		std::list<int>::iterator itEnd;
		while (!list.empty())
		{
			itEnd = list.end();
			--itEnd;
			std::cout << CYAN << "[" << RESET << *itEnd << CYAN << "] " << RESET; 
			if (list.size() > 1)
				std::cout << "--> ";
			list.pop_back();
		}
		std::cout << "\n" << " ... list is " << RED << "EMPTY." << RESET << std::endl;


		std::cout << "\n" << " Printing copy of the list: ";
		while (!fred.empty())
		{
			std::cout << CYAN << "[" << RESET << fred.back() << CYAN << "] " << RESET;
			fred.pop_back();
		}
		std::cout << "\n" << std::endl;
	}

	return (0);
}

/*	
	// subject main()
	int main()
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		return 0;
	}
*/

/*
	--> std::stack<int>

	push(const T& value):
		Inserts a new element at the top of the stack.
		Example: myStack.push(10);

	pop():
		Removes the top element from the stack.
		Example: myStack.pop();

	top():
		Returns a reference to the top element of the stack.
		Example: int topElement = myStack.top();

	empty():
		Returns true if the stack is empty, false otherwise.
		Example: if (myStack.empty()) { // Do something }

	size():
		Returns the number of elements in the stack.
		Example: int size = myStack.size();

	swap(std::stack<T>& other):
		Swaps the contents of two stacks.
		Example: myStack.swap(otherStack);

	emplace(Args&&... args):
		Constructs and inserts a new element at the top of the stack.
		Example: myStack.emplace(5);

	emplace_hint(const_iterator position, Args&&... args):
		Constructs and inserts a new element at the position specified by the iterator.
		Example: myStack.emplace_hint(myStack.begin(), 7);
*/

/*
	--> LIST

	push_back(const T& value):
		Adds an element to the end of the list.
		Example: myList.push_back(10);

	pop_back():
		Removes the last element from the list.
		Example: myList.pop_back();

	push_front(const T& value):
		Adds an element to the beginning of the list.
		Example: myList.push_front(5);

	pop_front():
		Removes the first element from the list.
		Example: myList.pop_front();

	insert(iterator position, const T& value):
		Inserts an element before the specified position.
		Example: myList.insert(myList.begin(), 20);

	erase(iterator position):
		Removes the element at the specified position.
		Example: myList.erase(myList.begin());

	begin() and end():
		Returns iterators to the first and last element of the list, respectively.
		Example: auto it = myList.begin();

	size():
		Returns the number of elements in the list.
		Example: int size = myList.size();

	empty():
		Returns true if the list is empty, otherwise returns false.
		Example: if (myList.empty()) { // Do something }

	clear():
		Removes all elements from the list.
		Example: myList.clear();

	front() and back():
		Returns a reference to the first and last element of the list, respectively.
		Example: int firstElement = myList.front();
*/

/*
	--> VECTOR

	push_back(const T& value):
		Adds an element to the end of the list.
		Example: myList.push_back(10);

	pop_back():
		Removes the last element from the list.
		Example: myList.pop_back();

	push_front(const T& value):
		Adds an element to the beginning of the list.
		Example: myList.push_front(5);

	pop_front():
		Removes the first element from the list.
		Example: myList.pop_front();

	insert(iterator position, const T& value):
		Inserts an element before the specified position.
		Example: myList.insert(myList.begin(), 20);

	erase(iterator position):
		Removes the element at the specified position.
		Example: myList.erase(myList.begin());

	begin() and end():
		Returns iterators to the first and last element of the list, respectively.
		Example: auto it = myList.begin();

	size():
		Returns the number of elements in the list.
		Example: int size = myList.size();

	empty():
		Returns true if the list is empty, otherwise returns false.
		Example: if (myList.empty()) { // Do something }

	clear():
		Removes all elements from the list.
		Example: myList.clear();

	front() and back():
		Returns a reference to the first and last element of the list, respectively.
		Example: int firstElement = myList.front();
*/
