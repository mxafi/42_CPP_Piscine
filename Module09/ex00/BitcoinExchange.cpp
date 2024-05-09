#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  this->_rates = other._rates;
  return *this;
}

BitcoinExchange::BitcoinExchange(const std::string& databasePath,
                                 const std::string& inputPath) {
  validateFilePath("database", databasePath);
  validateFilePath("input", inputPath);
  readDatabaseIntoMemory(databasePath);
  processInputFile(inputPath);
}

void BitcoinExchange::validateFilePath(const std::string& meta,
                                       const std::string& path) const {
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

void BitcoinExchange::readDatabaseIntoMemory(const std::string& databasePath) {
  std::ifstream file(databasePath);
  std::string line;

  std::getline(file, line);  // Skip the csv header

  size_t pos;
  std::string date;
  std::string rateStr;
  double rate;

  unsigned long lineNum = 2;
  while (file.good() && std::getline(file, line)) {
    pos = line.find(',');
    if (pos == std::string::npos) {
      throw std::invalid_argument(
          "invalid database file format, missing comma on line " +
          std::to_string(lineNum));
    }
    date = line.substr(0, pos);
    if (!isValidDateString(date))
      throw std::invalid_argument(
          "invalid database file format, invalid date on line " +
          std::to_string(lineNum) + " => " + date);

    try {
      rateStr = line.substr(pos + 1);
    } catch (const std::exception& e) {
      throw std::invalid_argument(
          "invalid database file format, missing rate on line " +
          std::to_string(lineNum));
    }
    try {
      rate = std::stod(rateStr);
    } catch (const std::exception& e) {
      throw std::invalid_argument(
          "invalid database file format, invalid rate on line " +
          std::to_string(lineNum) + " => " + rateStr);
    }

    _rates[date] = rate;
    lineNum++;
  }
  if (!file.eof()) {
    throw std::invalid_argument("corrupt database file: " + databasePath);
  }
  file.close();
}

// Checks if the date string is in the format YYYY-MM-DD
// And if the date is a real date
bool BitcoinExchange::isValidDateString(const std::string& date) const {
  std::string yearStr, monthStr, dayStr;
  if (date.size() != 10) {
    return false;
  }
  if (date[4] != '-' || date[7] != '-') {
    return false;
  }
  yearStr = date.substr(0, 4);
  monthStr = date.substr(5, 2);
  dayStr = date.substr(8, 2);
  if (yearStr.find_first_not_of("0123456789") != std::string::npos ||
      monthStr.find_first_not_of("0123456789") != std::string::npos ||
      dayStr.find_first_not_of("0123456789") != std::string::npos) {
    return false;
  }

  try {
    std::stoi(yearStr);
    std::stoi(monthStr);
    std::stoi(dayStr);
  } catch (const std::exception& e) {
    return false;
  }

  // save the date to be checked in 'inputTime'
  std::tm inputTime = {};
  std::istringstream ss(date);
  ss >> std::get_time(&inputTime, "%Y-%m-%d");
  if (ss.fail()) {
    return false;
  }

  std::tm validTime = {};
  memcpy(&validTime, &inputTime, sizeof(inputTime));

  // mktime converts it's argument to a valid time and date
  time_t mktimeResult = mktime(&validTime);
  if (mktimeResult < 0) {
    return false;
  }

  if (inputTime.tm_year != validTime.tm_year ||
      inputTime.tm_mon != validTime.tm_mon ||
      inputTime.tm_mday != validTime.tm_mday) {
    return false;
  }
  return true;
}

void BitcoinExchange::processInputFile(const std::string& inputPath) const {
  // TODO: process input file one line at a time, don't throw exceptions
}
