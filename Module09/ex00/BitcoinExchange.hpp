#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cctype>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#define LINE_ERROR(line_number, message)                                         \
  {                                                                              \
    std::cerr << "Error (line " << line_number << "): " << message << std::endl; \
    return;                                                                      \
  }

#define LINE_MSG(date, value, result) \
  { std::cout << date << " => " << value << " = " << result << std::endl; }

#ifndef STRICT_MODE
#define STRICT_MODE 1
#endif

class BitcoinExchange {
 public:
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  BitcoinExchange(const std::string& databasePath, const std::string& inputPath);

 private:
  BitcoinExchange();
  void validateFile(const std::string& meta, const std::string& path) const;
  void readDatabaseIntoMemory(const std::string& databasePath);
  bool isValidDateString(const std::string& date) const;
  void processInputFile(const std::string& inputPath) const;
  void processInputLine(const std::string& line, const unsigned long lineNum) const;
  const std::string findClosestDate(const std::string& date) const;

  std::map<std::string, double> _rates;
};

#endif
