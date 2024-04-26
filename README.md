# 42 CPP Projects (Module00 - Module09)

This is my implemantation of the C++ projects completed in modules 00 to 09. Below, you will find information about each project, including its name, description, grade, and repository URL.

<details>
    <summary> Module 00</summary>

<details>
    <summary>───── Exercise 00 ─────</summary>

### [Exercise 00] : Megaphone

- **Description:**
The Megaphone program is designed to echo input arguments in uppercase. When executed, it takes input strings as arguments and converts them to uppercase letters, then prints the result. If no arguments are provided, it outputs a specific message. The program ensures that all input strings are converted to uppercase, making the output loud and clear.

  To run, open the terminal and type 'make', and the program will compile.

```shell
./megaphone
```
  For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./megaphone
```
  After entering the program's name, you can input as many strings as you want, and all the input will be converted to uppercase letters.
  
```shell
valgrind ./megaphone "abc" "def"
```

- **Turn-in Directory:**
ex00/
- **Files to Turn in:**
Makefile |
megaphone.cpp

- **Forbidden Functions:** None
</details>

<details>
    <summary>───── Exercise 01 ─────</summary>
    
### [Exercise 01] : My Awesome PhoneBook

- **Description:**
My Awesome PhoneBook is a basic phonebook software written in C++. It consists of two classes: PhoneBook and Contact. The PhoneBook class manages an array of contacts and can store up to 8 contacts. If the user tries to add a 9th contact, the oldest one is replaced. The Contact class represents a phonebook contact. The program allows users to add new contacts, search for existing contacts, and exit the phonebook.

  To run, open the terminal and type 'make', and the program will compile.

```shell
./phonebook
```
  For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./phonebook
```

- **Turn-in Directory:**
ex01/
- **Files to Turn in:**
    Makefile |
    *.cpp |
    *.{h, hpp}

- **Forbidden Functions:** None
</details>

<details>
    <summary>───── Exercise 02 ─────</summary>

### [Exercise 02] : The Job Of Your Dreams

- **Description:**
The Job Of Your Dreams task involves recreating a lost file, Account.cpp, based on available files such as Account.hpp and a log file. The log file provides clues about the implementation of the Account class. The goal is to recreate the Account.cpp file by analyzing the provided files and ensuring that the recreated program passes the tests. This exercise tests the understanding and implementation skills of C++ classes and member functions.

To run, open the terminal and type 'make', and the program will compile.

```shell
./account
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./account
```
To run do:
```shell
make download
```
```shell
./account > fred.log 
```
```shell
diff <(cut -c 18- fred.log) <(cut -c 18- 19920104_091532.log) 
```
If the result is a new line, well done, your job is done!!!
It means there is no difference between your log and the 19920104_091532.log.
(The only difference should be the date).

- **Turn-in Directory:**
ex02/
- **Files to Turn in:**
    Makefile |
    *.cpp |

- **Forbidden Functions:** None

</details>

## Grade: 100/100

</details>
</details>

<details>
    <summary> Module 01</summary>
 &#8203;
    
Each exercise presents a different challenge in C++, covering everything from basic concepts to more advanced topics like memory allocation, pointers and references, file manipulation, and the use of control structures.

<details>
    <summary>───── Exercise 00 ─────</summary>

  ### [Exercise 00] : BraiiiiiiinnnzzzZ

- **Description:**
This exercise involves implementing a Zombie class, where each Zombie instance has a name and can announce itself. Additionally, two functions need to be implemented: newZombie, which creates a new zombie and returns it, and randomChump, which creates a zombie and makes it announce itself. The goal is to determine when it's best to allocate zombies on the stack or heap.

To run, open the terminal and type 'make', and the program will compile.

```shell
./zombie
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./zombie
```
- **Turn-in Directory:**
ex00/

- **Files to Turn in:**
    Makefile | main.cpp | Zombie.{h, hpp} | Zombie.cpp | newZombie.cpp | randomChump.cpp

- **Forbidden Functions:** None
</details>

<details>
    <summary>───── Exercise 01 ─────</summary>

  ### [Exercise 01] : Moar brainz!

- **Description:**
This exercise involves creating a horde of zombies. The zombieHorde function allocates a specified number of Zombie objects in a single allocation and initializes them with specific names. The objective is to test the zombieHorde function and ensure there are no memory leaks.

To run, open the terminal and type 'make', and the program will compile.

```shell
./zombiehorde
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./zombiehorde
```
- **Turn-in Directory:**
ex01/

- **Files to Turn in:**
    Makefile | main.cpp | Zombie.{h, hpp} | Zombie.cpp | zombieHorde.cpp


- **Forbidden Functions:** None
</details>

<details>
    <summary>───── Exercise 02 ─────</summary>

  ### [Exercise 02] : HI THIS IS BRAIN

- **Description:**
In this exercise, you're asked to write a program that prints information about string variables and their corresponding pointers and references. The goal is to better understand references in C++.

To run, open the terminal and type 'make', and the program will compile.

```shell
./brain
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./brain
```
- **Turn-in Directory:**
ex02/

- **Files to Turn in:**
    Makefile | main.cpp

- **Forbidden Functions:** None
</details>

<details>
    <summary>───── Exercise 03 ─────</summary>

  ### [Exercise 03] : Unnecessary violence

- **Description:**
Here, you need to implement a Weapon class with a private type attribute and functions to get and set this type. Additionally, two classes HumanA and HumanB are created, each with a Weapon and a name, capable of attacking. The difference between the classes is that HumanA always has a weapon, while HumanB may or may not have one.

To run, open the terminal and type 'make', and the program will compile.

```shell
./weapon
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./weapon
```
- **Turn-in Directory:**
ex03/

- **Files to Turn in:**
    Makefile | main.cpp | Weapon.{h, hpp} | Weapon.cpp | HumanA.{h,hpp} | HumanA.cpp | HumanB.{h, hpp} | HumanB.cpp


- **Forbidden Functions:** None
</details>

<details>
    <summary>───── Exercise 04 ─────</summary>

  ### [Exercise 04] : Sed is for losers

- **Description:**
The goal of this exercise is to create a program that replaces all occurrences of one string s1 with another string s2 in a specified file. File manipulation in C is forbidden, and the replacement must be done using string manipulation functions.

To run, open the terminal and type 'make', and the program will compile.

```shell
./replace
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./replace
```
In the terminal, type 'make txt' to compile a text file.
Then, use it with the program, and s1 will be replaced by s2 in <name>.txt.replace.
  
```shell
./replace <filename> <s1> <s2>
```
Example:
```shell
./replace fred.txt a b
```
- **Turn-in Directory:**
ex04/

- **Files to Turn in:**
    Makefile | main.cpp | *.cpp | *.{h, hpp}

- **Forbidden Functions:** std::string::replace
</details>

<details>
    <summary>───── Exercise 05 ─────</summary>

  ### [Exercise 05] : Harl 2.0

- **Description:**
In this exercise, you need to create a Harl class that can emit messages of different levels (DEBUG, INFO, WARNING, ERROR). The challenge is to implement this functionality using member function pointers. The objective is to automate Harl's messages based on different log levels.

To run, open the terminal and type 'make', and the program will compile.

```shell
./harl
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./harl
```
- **Turn-in Directory:**
ex05/

- **Files to Turn in:**
    Makefile | main.cpp | Harl.{h, hpp} | Harl.cpp

- **Forbidden Functions:** None
</details>

<details>
    <summary>───── Exercise 06 ─────</summary>

  ### [Exercise 06] : Harl filter

- **Description:**
This exercise involves implementing a filtering system for Harl's messages based on different log levels. The program should display only messages of a certain level and above. The challenge is to implement this using the switch statement in C++.

To run, open the terminal and type 'make', and the program will compile.

```shell
./harlFilter 
```
For assurance, run with Valgrind to check for errors and memory leaks.
  
```shell
valgrind ./harlFilter
```
Running without arguments should return this:
  
```shell
./harlFilter [LEVEL] --> <DEBUG> <INFO> <WARNING> <ERROR>
```
Example of how to use:
```shell
./harlFilter DEBUG
```
- **Turn-in Directory:**
ex06/

- **Files to Turn in:**
    Makefile | main.cpp | Harl.{h, hpp} | Harl.cpp

- **Forbidden Functions:** None
</details>

## Grade: 100/100
</details>
</details>





<details>
    <summary> Module 02</summary>

## Module02

### [Project Name]
- **Description:** [Brief description of the project]
- **Grade:** [Project Grade]
- **Repository:** [Project URL]

### [Project Name]
- **Description:** [Brief description of the project]
- **Grade:** [Project Grade]
- **Repository:** [Project URL]

## Grade: 100/100

</details>

<details>
    <summary> Module 03</summary>

## Module03

### [Project Name]
- **Description:** [Brief description of the project]
- **Grade:** [Project Grade]
- **Repository:** [Project URL]

### [Project Name]
- **Description:** [Brief description of the project]
- **Grade:** [Project Grade]
- **Repository:** [Project URL]

</details>

<details>
    <summary> Module 04</summary>

## Module04

### [Project Name]
- **Description:** [Brief description of the project]
- **Grade:** [Project Grade]
- **Repository:** [Project URL]

### [Project Name]
- **Description:** [Brief description of the project]
- **Grade:** [Project Grade]
- **Repository:** [Project URL]

</details>
