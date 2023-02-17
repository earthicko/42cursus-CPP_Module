#include <iostream>
#include <sstream>
#include <cstdlib>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static std::string	intToString(int val)
{
	std::ostringstream	strm;

	strm << val;
	return strm.str();
}

int	main(void)
{
	const int	nAnimals = 100;
	const int	nIdeas = 100;
	AAnimal		*animals[nAnimals];
	AAnimal		*copyAnimals[nAnimals];

	std::cout << "=============== Create Dogs ===============\n";
	for (int i = 0; i < nAnimals / 2; i++)
	{
		animals[i] = new Dog();
		for (int j = 0; j < nIdeas; j++)
			((Dog *)animals[i])->setIdea("Dog " + intToString(i) + " Idea " + intToString(j), j);
	}
	std::cout << "=============== Create Cats ===============\n";
	for (int i = nAnimals / 2; i < nAnimals; i++)
	{
		animals[i] = new Cat();
		for (int j = 0; j < nIdeas; j++)
			((Cat *)animals[i])->setIdea("Cat " + intToString(i) + " Idea " + intToString(j), j);
	}
	std::cout << "=============== Copy Animals ===============\n";
	for (int i = 0; i < nAnimals; i++)
		copyAnimals[i] = new Dog(*((Dog *)animals[i]));
	std::cout << "=============== Check Ideas ===============\n";
	for (int i = 0; i < nAnimals; i++)
	{
		for (int j = 0; j < nIdeas; j++)
			std::cout << ((Dog *)copyAnimals[i])->getIdea(j) << "\n";
	}
	std::cout << "=============== Reassign Ideas ===============\n";
	for (int i = 0; i < nAnimals; i++)
	{
		for (int j = 0; j < nIdeas; j++)
			((Dog *)animals[i])->setIdea("New idea " + intToString(j), j);
	}
	std::cout << "=============== Check Ideas ===============\n";
	for (int i = 0; i < nAnimals; i++)
	{
		for (int j = 0; j < nIdeas; j++)
			std::cout << ((Dog *)copyAnimals[i])->getIdea(j) << "\n";
	}
	std::cout << "=============== Destruct Animals ===============\n";
	for (int i = 0; i < nAnimals; i++)
	{
		delete animals[i];
		delete copyAnimals[i];
	}
	system("leaks exec");
	return (0);
}
