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
      // numeric types (char, int, float, double)
      setOutChar(input);
      setOutInt(input, inputType);
      setOutFloat(input, inputType);
      setOutDouble(input, inputType);
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
        "ScalarConverter::getScalarType: found a non-numeric character or "
        "non-ascii char that is not minus, dot, or f, invalid");
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

void ScalarConverter::setOutChar(const std::string& input) {
  try {
    int i = std::stoi(input);
    if (i >= 33 && i <= 126) {
      LOG_DEBUG("ScalarConverter::setOutChar: i is in displayable char range");
      outputStringChar = std::to_string(static_cast<char>(i));
      return;
    }
    if (i >= 0 && i <= 127) {
      LOG_DEBUG(
          "ScalarConverter::setOutChar: i is in ascii range but not "
          "displayable");
      outputStringChar = "non-displayable";
      return;
    }
    LOG_DEBUG("ScalarConverter::setOutChar: i is not in ascii char range");
    outputStringChar = "impossible";
    return;
  } catch (std::exception& e) {
    LOG_DEBUG("ScalarConverter::setOutChar: stoi out of range for int");
    outputStringChar = "impossible";
    return;
  }
}

void ScalarConverter::setOutInt(const std::string& input,
                                ScalarType inputType) {
  (void)input;
  (void)inputType;
}

void ScalarConverter::setOutFloat(const std::string& input,
                                  ScalarType inputType) {
  (void)input;
  (void)inputType;
}

void ScalarConverter::setOutDouble(const std::string& input,
                                   ScalarType inputType) {
  (void)input;
  (void)inputType;
}
