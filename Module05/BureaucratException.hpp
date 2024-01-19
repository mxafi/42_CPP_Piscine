#ifndef BUREAUCRATEXCEPTION_HPP
#define BUREAUCRATEXCEPTION_HPP

#include <stdexcept>
#include <string>

class BureaucratException : public std::exception {
 private:
  char* message;

 public:
  BureaucratException(void);
  BureaucratException(char* message);
  char* what(void);
};

#endif
