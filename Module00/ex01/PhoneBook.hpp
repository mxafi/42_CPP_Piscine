#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACTS_MAX 8

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts_[CONTACTS_MAX];
	int		contact_idx_;
	void	add_contact_(void);
	void	search_(void);

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	run(void);

};

#endif
