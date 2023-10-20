#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to the best phonebook ever!" << std::endl;
	std::cout << "You'll lose your data if you exit the program." << std::endl;
	std::cout << "You can store a maximum of "<< CONTACTS_MAX << " contacts," << std::endl;
	std::cout << "old contacts are overwritten." << std::endl << std::endl;
	contact_idx_ = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Thanks for using the best phonebook ever!" << std::endl;
	std::cout << "Byebye!" << std::endl;
}

void	PhoneBook::run(void)
{
	std::string	input;

	std::cout << "You can ADD, SEARCH or EXIT." << std::endl;
	std::cout << "Write what you want to do: ";
	std::getline(std::cin, input);
	std::cout << std::endl;
	if (input == "ADD") {
		add_contact_();
		return ;
	}
	else if (input == "SEARCH") {
		search_();
		return ;
	}
	else if (input == "EXIT")
		exit(0);
	else
		std::cout << std::endl << "Invalid input, try again." << std::endl;
}

void	PhoneBook::add_contact_(void)
{
	std::string	input;
	Contact		tmp_contact;
	std::string	error_empty("Empty fields not allowed, contact information was not saved.\n");

	std::cout << "To add a new contact, fill out the contact info below :)" << std::endl;
	std::cout << "Note: No empty fields are allowed." << std::endl;

	std::cout << "First name: " << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << error_empty;
		return ;
	}
	else
		tmp_contact.set_firstname(input);

	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << error_empty;
		return ;
	}
	else
		tmp_contact.set_lastname(input);

	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << error_empty;
		return ;
	}
	else
		tmp_contact.set_nickname(input);

	for (int p_i = 0; p_i < 3; p_i++) {
		std::cout << "Phone number: " << std::endl;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << error_empty;
			return ;
		}
		else if (input.find_first_not_of("0123456789 +-()") != std::string::npos) {
			std::cout << "Phone number is not valid, try again. Attempt " << p_i + 1 << "/3" << std::endl;
			continue;
		}
		else {
			tmp_contact.set_phone_nbr(input);
			break;
		}
	}

	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << error_empty;
		return ;
	}
	else
		tmp_contact.set_darkest_secret(input);

	contacts_[contact_idx_] = tmp_contact;
	contact_idx_ = (contact_idx_ + 1) % CONTACTS_MAX;
	std::cout << std::endl << "Contact added successfully!" << std::endl << std::endl;
}

void	PhoneBook::search_(void)
{
	std::string	tmp;
	int			index;
	int			attempt = 0;

	if (contacts_[0].get_firstname().empty()) {
		std::cout << "The phonebook is empty :(" << std::endl << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "first name" << "|" << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < CONTACTS_MAX; i++) {
		if (contacts_[i].get_firstname().empty())
			break;
		std::cout << std::setw(10) << i << "|";
		for (int j = 0; j < 3; j++) {
			switch (j) {
				case 0:
					tmp = contacts_[i].get_firstname();
					break;
				case 1:
					tmp = contacts_[i].get_lastname();
					break;
				case 2:
					tmp = contacts_[i].get_nickname();
					break;
			}
			if (tmp.length() > 10)
				std::cout << tmp.substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << tmp;
			if (j != 2)
				std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Which contact do you want to display?" << std::endl;
	invalid_index:
	std::cout << "Type the index number of the desired contact: ";
	std::getline(std::cin, tmp);
	std::cout << std::endl;
	if (!tmp.empty() && tmp.find_first_not_of("0123456789") == std::string::npos) {
		index = std::atoi(tmp.c_str());
		if (index >= 0 && index < CONTACTS_MAX && !contacts_[index].get_firstname().empty()) {
			std::cout << "    First name: " << contacts_[index].get_firstname() << std::endl;
			std::cout << "     Last name: " << contacts_[index].get_lastname() << std::endl;
			std::cout << "      Nickname: " << contacts_[index].get_nickname() << std::endl;
			std::cout << "  Phone number: " << contacts_[index].get_phone_nbr() << std::endl;
			std::cout << "Darkest secret: " << contacts_[index].get_darkest_secret() << std::endl;
			std::cout << std::endl;
			return ;
		}
	}
	std::cout << "Not a valid index, try again. Attempt " << attempt + 1 << "/3." << std::endl;
	attempt++;
	if (attempt == 3)
		return ;
	goto invalid_index;
}
