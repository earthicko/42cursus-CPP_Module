#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal		*animal = new Animal();
	const Animal		*dog = new Dog();
	const Animal		*cat = new Cat();
	const WrongAnimal	*wronganimal = new WrongAnimal();
	const WrongAnimal	*wrongcat = new WrongCat();

	std::cout << animal->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << wronganimal->getType() << std::endl;
	std::cout << wrongcat->getType() << std::endl;
	wronganimal->makeSound();
	wrongcat->makeSound();
	delete animal;
	delete dog;
	delete cat;
	delete wronganimal;
	delete wrongcat;
	return (0);
}
