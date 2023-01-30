#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	command_add(PhoneBook &phonebook)
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
	phonebook.add_contact(newcontact);
}

void	command_search(PhoneBook &phonebook)
{
	std::string			input;
	std::stringstream	buf;
	int					index;

	phonebook.print_all_contacts();
	std::cout << "Index: ";
	std::cin >> input;
	buf.str(input);
	buf >> index;
	if (buf.fail())
	{
		std::cout << "Invalid input: " << input << std::endl;
		return ;
	}
	phonebook.print_contact(index);
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
			command_add(phonebook);
		else if (input == "SEARCH")
			command_search(phonebook);
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Command not found." << std::endl;
	}
	system("leaks anycall");
	return (0);
}
