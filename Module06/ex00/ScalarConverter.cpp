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
  DEBUG_INPUT_ENUM_LABEL(inputType);
  switch (inputType) {
    case CHAR:
      parseChar(input);
      break;
    case INT:
      parseInt(input);
      break;
    case FLOAT:
      parseFloat(input);
      break;
    case DOUBLE:
      parseDouble(input);
      break;
    case INVALID:
      std::cout << "Invalid input" << std::endl;
      return;
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
  LOG_DEBUG("ScalarConverter::getScalarType: got input: " << input);
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
  } else if (input.find_first_not_of("0123456789-.f") == std::string::npos) {
    LOG_DEBUG("ScalarConverter::getScalarType: input is possibly int, float, or double");
    if (input.find_first_of(".") == std::string::npos) {
      LOG_DEBUG("ScalarConverter::getScalarType: input is possibly int");
      // check if it fits in int, sanitize -.f positions
      return INT;
    }
  }
  return INVALID;
}

void ScalarConverter::printOutput() {
  std::cout << "char: " << outputStringChar << std::endl;
  std::cout << "int: " << outputStringInt << std::endl;
  std::cout << "float: " << outputStringFloat << std::endl;
  std::cout << "double: " << outputStringDouble << std::endl;
}

void ScalarConverter::parseChar(const std::string& input) {
  outputStringChar = input[1];
  outputStringInt = std::to_string(static_cast<int>(input[1]));
  outputStringFloat = std::to_string(static_cast<float>(input[1])) + "f";
  outputStringDouble = std::to_string(static_cast<double>(input[1]));
}

void ScalarConverter::parseInt(const std::string& input) {
  try {
    int i = std::stoi(input);
    outputStringInt = std::to_string(i);
  } catch (std::exception& e) {
    outputStringInt = "impossible";
  }
}

void ScalarConverter::parseFloat(const std::string& input) {
  try {
    float f = std::stof(input);
    outputStringFloat = std::to_string(f);
  } catch (std::exception& e) {
    outputStringFloat = "impossible";
  }
}

void ScalarConverter::parseDouble(const std::string& input) {
  try {
    double d = std::stod(input);
    outputStringDouble = std::to_string(d);
  } catch (std::exception& e) {
    outputStringDouble = "impossible";
  }
}

bool isDisplayable(char c) {
  return (c >= 32 && c <= 126);
}
