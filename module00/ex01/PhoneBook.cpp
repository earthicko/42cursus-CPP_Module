#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	head = 0;
	nContacts = 0;
	for (int i = 0; i < QUEUE_SIZE; i++)
		contacts[i] = Contact();
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

PhoneBook::PhoneBook(const PhoneBook &phonebook)
{
	head = phonebook.head;
	nContacts = phonebook.nContacts;
	for (int i = 0; i < QUEUE_SIZE; i++)
		contacts[i] = phonebook.contacts[i];
}

PhoneBook	&PhoneBook::operator= (const PhoneBook &phonebook)
{
	head = phonebook.head;
	nContacts = phonebook.nContacts;
	for (int i = 0; i < QUEUE_SIZE; i++)
		contacts[i] = phonebook.contacts[i];
	return (*this);
}

void	PhoneBook::addContact(Contact &contact)
{
	contacts[(head + nContacts) % QUEUE_SIZE] = contact;
	if (nContacts < QUEUE_SIZE)
		nContacts++;
	else
		head = (head + 1) % QUEUE_SIZE;
}

void	PhoneBook::printColumn(std::string column) const
{
	if (column.length() > COLUMN_WIDTH)
		column = column.substr(0, COLUMN_WIDTH - 1) + ".";
	std::cout << std::setw(COLUMN_WIDTH) << std::right;
	std::cout << column;
	std::cout << std::resetiosflags(std::ios::right);
	std::cout << std::resetiosflags(std::ios::adjustfield);
}

static std::string	intToString(int val)
{
	std::ostringstream	strm;

	strm << val;
	return strm.str();
}

void	PhoneBook::printAllContacts(void) const
{
	for (int i = 0; i < nContacts; i++)
	{
		std::cout << COLUMN_DIVIDER;
		printColumn(intToString(i));
		std::cout << COLUMN_DIVIDER;
		printColumn(contacts[(head + i) % QUEUE_SIZE].getFirstname());
		std::cout << COLUMN_DIVIDER;
		printColumn(contacts[(head + i) % QUEUE_SIZE].getLastname());
		std::cout << COLUMN_DIVIDER;
		printColumn(contacts[(head + i) % QUEUE_SIZE].getNickname());
		std::cout << COLUMN_DIVIDER << std::endl;
	}
}

void	PhoneBook::printContact(int index) const
{
	if (0 <= index && index < nContacts)
		contacts[(head + index) % QUEUE_SIZE].print();
	else
		std::cout << "Index out of bound." << std::endl;
}
