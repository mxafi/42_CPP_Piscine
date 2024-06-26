#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define RESET "\033[0m"
#define CYAN "\033[36m"

#ifdef DEBUG
#define LOG_DEBUG(x) \
  { std::cout << CYAN << "Debug: " << x << RESET << std::endl; };
#define DEBUG_INPUT_ENUM_LABEL(x)                                     \
  {                                                                   \
    const char* inputEnumLabels[] = {"CHAR",    "INT",     "FLOAT",   \
                                     "DOUBLE",  "INVALID", "IND_NAN", \
                                     "POS_INF", "NEG_INF"};           \
    LOG_DEBUG("ScalarConverter::ScalarConverter: inputType: "         \
              << inputEnumLabels[x]);                                 \
  };
#else
#define LOG_DEBUG(x)
#define DEBUG_INPUT_ENUM_LABEL(x)
#endif

#include <iostream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  explicit ScalarConverter(const std::string& input);

  enum ScalarType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID,
    IND_NAN,
    POS_INF,
    NEG_INF,
  };

  ScalarType getScalarType(const std::string& input);
  void setOutChar(const std::string& input, ScalarType inputType);
  void setOutInt(const std::string& input, ScalarType inputType);
  void setOutFloat(const std::string& input, ScalarType inputType);
  void setOutDouble(const std::string& input, ScalarType inputType);
  void printOutput();

  ScalarType inputType;
  std::string outputStringChar;
  std::string outputStringInt;
  std::string outputStringFloat;
  std::string outputStringDouble;

 public:
  ~ScalarConverter();

  static void convert(const std::string& input);
};

#endif
