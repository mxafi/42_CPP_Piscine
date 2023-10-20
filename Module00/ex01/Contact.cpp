#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void	Contact::set_firstname(std::string firstname) {
	this->firstname_ = firstname;
}
void	Contact::set_lastname(std::string lastname) {
	this->lastname_ = lastname;
}
void	Contact::set_nickname(std::string nickname) {
	this->nickname_ = nickname;
}
void	Contact::set_phone_nbr(std::string phone_nbr) {
	this->phone_nbr_ = phone_nbr;
}
void	Contact::set_darkest_secret(std::string darkest_secret) {
	this->darkest_secret_ = darkest_secret;
}
std::string	Contact::get_firstname(void) {
	return (this->firstname_);
}
std::string	Contact::get_lastname(void) {
	return (this->lastname_);
}
std::string	Contact::get_nickname(void) {
	return (this->nickname_);
}
std::string	Contact::get_phone_nbr(void) {
	return (this->phone_nbr_);
}
std::string	Contact::get_darkest_secret(void) {
	return (this->darkest_secret_);
}
