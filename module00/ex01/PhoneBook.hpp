#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define QUEUE_SIZE 9
# define COLUMN_WIDTH 10

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
		int			tail;
		Contact		contacts[QUEUE_SIZE];
};

#endif
