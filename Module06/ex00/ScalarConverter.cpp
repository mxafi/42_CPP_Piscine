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
  }
  if (input.find_first_not_of("0123456789-.f") != std::string::npos) {
    LOG_DEBUG(
        "ScalarConverter::getScalarType: found a non-numeric character that is "
        "not minus, dot, or f, invalid");
    return INVALID;
  }
  LOG_DEBUG("ScalarConverter::getScalarType: input is possibly a number");
  size_t dotPos = input.find_first_of('.');
  size_t minusPos = input.find_first_of('-');
  size_t fPos = input.find_first_of('f');
  if (minusPos != std::string::npos) {
    LOG_DEBUG("ScalarConverter::getScalarType: minus exists");
    if (minusPos != 0) {
      LOG_DEBUG(
          "ScalarConverter::getScalarType: minus in improper place, invalid");
      return INVALID;
    }
    if (input.find_first_of('-', minusPos + 1) != std::string::npos) {
      LOG_DEBUG(
          "ScalarConverter::getScalarType: minus has a duplicate, invalid");
      return INVALID;
    }
  }
  if (fPos != std::string::npos) {
    LOG_DEBUG("ScalarConverter::getScalarType: f exists");
    if (fPos != input.length() - 1) {
      LOG_DEBUG("ScalarConverter::getScalarType: f in improper place, invalid");
      return INVALID;
    }
    if (input.find_first_of('f', fPos + 1) != std::string::npos) {
      LOG_DEBUG("ScalarConverter::getScalarType: f has a duplicate, invalid");
      return INVALID;
    }
  }
  if (dotPos != std::string::npos) {
    LOG_DEBUG("ScalarConverter::getScalarType: dot exists");
    if (dotPos == 0 || dotPos == input.length() - 1) {
      LOG_DEBUG(
          "ScalarConverter::getScalarType: dot in improper place, invalid");
      return INVALID;
    }
    if (input.find_first_of('.', dotPos + 1) != std::string::npos) {
      LOG_DEBUG("ScalarConverter::getScalarType: dot has a duplicate, invalid");
      return INVALID;
    }
  }
  if (dotPos == std::string::npos) {
    LOG_DEBUG("ScalarConverter::getScalarType: input is some integer type");
    if (fPos != std::string::npos) {
      LOG_DEBUG(
          "ScalarConverter::getScalarType: input has f in some integer type, "
          "invalid");
      return INVALID;
    }
    try {
      std::stoi(input);
    } catch (std::invalid_argument& e) {
      LOG_DEBUG(
          "ScalarConverter::getScalarType: stoi invalid arg for int, "
          "invalid");
      return INVALID;
    } catch (std::out_of_range& e) {
      LOG_DEBUG(
          "ScalarConverter::getScalarType: stoi out of range for int, "
          "invalid");
      return INVALID;
    }
    return INT;
  }
  if (fPos != std::string::npos) {
    LOG_DEBUG("ScalarConverter::getScalarType: input is float");
    try {
      std::stof(input);
    } catch (std::invalid_argument& e) {
      LOG_DEBUG("ScalarConverter::getScalarType: stof invalid arg for float");
      return INVALID;
    } catch (std::out_of_range& e) {
      LOG_DEBUG("ScalarConverter::getScalarType: stof out of range for float");
      return INVALID;
    }
    return FLOAT;
  }
  LOG_DEBUG("ScalarConverter::getScalarType: input is double");
  try {
    std::stod(input);
  } catch (std::invalid_argument& e) {
    LOG_DEBUG("ScalarConverter::getScalarType: stod invalid arg for double");
    return INVALID;
  } catch (std::out_of_range& e) {
    LOG_DEBUG("ScalarConverter::getScalarType: stod out of range for double");
    return INVALID;
  }
  return DOUBLE;
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
