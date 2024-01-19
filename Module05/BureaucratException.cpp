#include "BureaucratException.hpp"

BureaucratException::BureaucratException(void)
    : message("Bureaucrat::Exception") {}

BureaucratException::BureaucratException(char* message) : message(message) {}

char* BureaucratException::what(void) {}
