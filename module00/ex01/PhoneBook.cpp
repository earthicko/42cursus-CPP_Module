#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	head = 0;
	tail = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

PhoneBook::PhoneBook(const PhoneBook &phonebook)
{
	head = phonebook.head;
	tail = phonebook.tail;
	for (int i = 0; i < QUEUE_SIZE; i++)
		contacts[i] = phonebook.contacts[i];
}

PhoneBook	&PhoneBook::operator= (const PhoneBook &phonebook)
{
	head = phonebook.head;
	tail = phonebook.tail;
	for (int i = 0; i < QUEUE_SIZE; i++)
		contacts[i] = phonebook.contacts[i];
	return (*this);
}

void	PhoneBook::add_contact(Contact &contact)
{
	if ((head + 1) % QUEUE_SIZE == tail)
		tail = (tail + 1) % QUEUE_SIZE;
	contacts[head] = contact;
	head = (head + 1) % QUEUE_SIZE;
}

void	PhoneBook::print_column(std::string column) const
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

void	PhoneBook::print_all_contacts(void) const
{
	for (int i = tail; i != head; i = (i + 1) % QUEUE_SIZE)
	{
		std::cout << "|";
		print_column(intToString((i - tail + QUEUE_SIZE) % QUEUE_SIZE));
		std::cout << "|";
		print_column(contacts[i].firstname);
		std::cout << "|";
		print_column(contacts[i].lastname);
		std::cout << "|";
		print_column(contacts[i].nickname);
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::print_contact(int index) const
{
	int	i_queue;
	int	i_array;

	i_queue = tail;
	i_array = 0;
	while (i_queue != head)
	{
		if (i_array == index)
		{
			contacts[i_queue].print();
			return ;
		}
		i_queue = (i_queue + 1) % QUEUE_SIZE;
		i_array++;
	}
	std::cout << "Index out of bound." << std::endl;
}
