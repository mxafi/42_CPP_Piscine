#include "BureaucratException.hpp"

BureaucratException::BureaucratException(std::string& message) : std::runtime_error(message) {}

BureaucratException::BureaucratException(const char* message) : std::runtime_error(message) {}