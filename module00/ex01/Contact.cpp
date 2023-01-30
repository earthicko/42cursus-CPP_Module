#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(
			std::string _firstname,
			std::string _lastname,
			std::string _nickname,
			std::string _phonenumber,
			std::string _darkestsecret)
{
	firstname = _firstname;
	lastname = _lastname;
	nickname = _nickname;
	phonenumber = _phonenumber;
	darkestsecret = _darkestsecret;
}

Contact::~Contact(void)
{
	return ;
}

Contact::Contact(const Contact &contact)
{
	firstname = contact.firstname;
	lastname = contact.lastname;
	nickname = contact.nickname;
	phonenumber = contact.phonenumber;
	darkestsecret = contact.darkestsecret;
}

Contact	&Contact::operator= (const Contact &contact)
{
	firstname = contact.firstname;
	lastname = contact.lastname;
	nickname = contact.nickname;
	phonenumber = contact.phonenumber;
	darkestsecret = contact.darkestsecret;
	return (*this);
}

void	Contact::print(void) const
{
	std::cout << "First Name    : " << firstname << std::endl;
	std::cout << "Last Name     : " << lastname << std::endl;
	std::cout << "Nickname      : " << nickname << std::endl;
	std::cout << "Phone Number  : " << phonenumber << std::endl;
	std::cout << "Darkest Secret: " << darkestsecret << std::endl;
}
