#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to the best phonebook ever!" << std::endl;
	std::cout << "You'll lose your data if you exit the program." << std::endl;
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
	std::cin >> input;
	if (input.compare("ADD") == 0)
		add_contact_();
	else if (input.compare("SEARCH") == 0)
		search_();
	else if (input.compare("EXIT") == 0)
		exit(0);
	else
		std::cout << "Invalid input, try again." << std::endl;
}

void	PhoneBook::add_contact_(void)
{

}

void	PhoneBook::search_(void)
{
	
}
