#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  (void)other;
  return *this;
}

BitcoinExchange::BitcoinExchange(const std::string& databasePath,
                                 const std::string& inputPath) {
  validateFilePath("database", databasePath);
  validateFilePath("input", inputPath);
  // Gather the data from the database while validating it
  // Process and validate the input file line by line
}

void BitcoinExchange::validateFilePath(const std::string& meta,
                                       const std::string& path) {
  // Check that the file is good for reading
  if (path.empty()) {
    throw std::invalid_argument("empty file path (" + meta + ")");
  }
  std::ifstream file(path);
  if (!file.good()) {
    throw std::invalid_argument("could not open " + meta +
                                " file for reading (" + path + ")");
  }
  file.close();
}
