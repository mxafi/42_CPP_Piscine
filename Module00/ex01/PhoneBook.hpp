#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts_[8];
	void	add_contact_(void);
	void	search_(void);

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	run(void);

};

#endif
