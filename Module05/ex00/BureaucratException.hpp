#ifndef BUREAUCRATEXCEPTION_HPP
#define BUREAUCRATEXCEPTION_HPP

#include <stdexcept>
#include <string>

class BureaucratException : public std::runtime_error {
 private:
  BureaucratException(void);
 public:
  BureaucratException(std::string& message);
  BureaucratException(const char* message);
};

#endif
