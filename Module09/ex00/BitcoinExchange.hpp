#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
 public:
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  BitcoinExchange(const std::string& databasePath,
                  const std::string& inputPath);

 private:
  BitcoinExchange();
  void validateFilePath(const std::string& meta, const std::string& path) const;
  void readDatabaseIntoMemory(const std::string& databasePath);
  bool isValidDateString(const std::string& date) const noexcept;
  void processInputFile(const std::string& inputPath) const noexcept;

  std::map<std::string, double> _rates;
};

#endif
