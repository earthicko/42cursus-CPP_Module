#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define QUEUE_SIZE 5
# define COLUMN_WIDTH 10

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		PhoneBook(const PhoneBook &phonebook);
		PhoneBook &operator= (const PhoneBook &phonebook);

		void	add_contact(Contact &contact);
		void	print_all_contacts(void);
		void	print_contact(int index);
	private:
		void	print_column(std::string column);
		int		head;
		int		tail;
		Contact	contacts[QUEUE_SIZE];
};

#endif
