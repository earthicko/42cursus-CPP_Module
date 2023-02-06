#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define QUEUE_SIZE 4
# define COLUMN_WIDTH 10
# define COLUMN_DIVIDER "|"

class PhoneBook
{
	public:
					PhoneBook(void);
					~PhoneBook(void);
					PhoneBook(const PhoneBook &phonebook);
		PhoneBook	&operator=(const PhoneBook &phonebook);

		void		addContact(Contact &contact);
		void		printAllContacts(void) const;
		void		printContact(int index) const;

	private:
		void		printColumn(std::string column) const;

		int			head;
		int			nContacts;
		Contact		contacts[QUEUE_SIZE];
};

#endif
