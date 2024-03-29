#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

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
