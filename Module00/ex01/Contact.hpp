#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	firstname_;
	std::string	lastname_;
	std::string	nickname_;
	std::string	phone_nbr_;
	std::string	darkest_secret_;

public:
	Contact(void);
	~Contact(void);
	void		set_firstname(std::string firstname);
	void		set_lastname(std::string lastname);
	void		set_nickname(std::string nickname);
	void		set_phone_nbr(std::string phone_nbr);
	void		set_darkest_secret(std::string darkest_secret);
	std::string	get_firstname(void);
	std::string	get_lastname(void);
	std::string	get_nickname(void);
	std::string	get_phone_nbr(void);
	std::string	get_darkest_secret(void);
};

#endif
