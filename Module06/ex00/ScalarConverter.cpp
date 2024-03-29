#include "ScalarConverter.hpp"

// public destructor
ScalarConverter::~ScalarConverter() {}

// private constructors and assignment operator
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
  (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::ScalarConverter(const std::string& input) {
  inputType = getScalarType(input);
  switch (inputType) {
    case CHAR:
      // input[1] is the character
      break;
    case INT:
      // stoi(input) is the integer
      break;
    case FLOAT:
      // stof(input) is the float
      break;
    case DOUBLE:
      // stod(input) is the double
      break;
    case INVALID:
      // invalid input
      break;
    case IND_NAN:
      // nan
      break;
    case POS_INF:
      // +inf or +inff
      break;
    case NEG_INF:
      // -inf or -inff
      break;
    default:
      break;
  }
  printOutput();
}

// public static method
void ScalarConverter::convert(const std::string& input) {
  ScalarConverter sc(input);
}

// private utility methods
ScalarConverter::ScalarType ScalarConverter::getScalarType(
    const std::string& input) {
  if (input.length() == 0) {
    return INVALID;
  } else if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
    return CHAR;
  } else if (input == "+inf" || input == "+inff") {
    return POS_INF;
  } else if (input == "-inf" || input == "-inff") {
    return NEG_INF;
  } else if (input == "nan" || input == "nanf") {
    return IND_NAN;
  }
  return INVALID;
}

void ScalarConverter::printOutput() {
  std::cout << "char: " << outputStringChar << std::endl;
  std::cout << "int: " << outputStringInt << std::endl;
  std::cout << "float: " << outputStringFloat << std::endl;
  std::cout << "double: " << outputStringDouble << std::endl;
}
