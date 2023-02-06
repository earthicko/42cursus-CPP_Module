#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	commandAdd(PhoneBook &phonebook)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	darkestsecret;

	std::cout << "First Name    : ";
	std::cin >> firstname;
	std::cout << "Last Name     : ";
	std::cin >> lastname;
	std::cout << "Nickname      : ";
	std::cin >> nickname;
	std::cout << "Phone Number  : ";
	std::cin >> phonenumber;
	std::cout << "Darkest Secret: ";
	std::cin >> darkestsecret;

	Contact	newcontact(
		firstname,
		lastname,
		nickname,
		phonenumber,
		darkestsecret);
	phonebook.addContact(newcontact);
}

void	commandSearch(PhoneBook &phonebook)
{
	std::string			input;
	std::stringstream	buf;
	int					index;

	phonebook.printAllContacts();
	std::cout << "Index: ";
	std::cin >> input;
	buf.str(input);
	buf >> index;
	if (buf.fail())
	{
		std::cout << "Invalid input: " << input << std::endl;
		return ;
	}
	phonebook.printContact(index);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "Command: ";
		std::cin >> input;
		if (input == "ADD")
			commandAdd(phonebook);
		else if (input == "SEARCH")
			commandSearch(phonebook);
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Command not found." << std::endl;
	}
	system("leaks anycall");
	return (0);
}
