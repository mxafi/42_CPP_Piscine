#include <thread>
#include <chrono>
#include "PhoneBook.hpp"

int main () {
	PhoneBook	phonebook;

	while (true) {
		phonebook.run();
	}
	return 0;
}
