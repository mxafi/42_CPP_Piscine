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

BitcoinExchange::BitcoinExchange(const std::string& databasePath, const std::string& inputPath) {
  validateFile("database", databasePath);
  validateFile("input", inputPath);
  readDatabaseIntoMemory(databasePath);
  processInputFile(inputPath);
}

void BitcoinExchange::validateFile(const std::string& meta, const std::string& path) const {
  // Check that the file is good for reading
  if (path.empty()) {
    throw std::invalid_argument("empty " + meta + " file path (" + path + ")");
  }
  std::ifstream file(path);
  if (!file.good()) {
    throw std::invalid_argument("could not open " + meta + " file for reading (" + path + ")");
  }
  // Check that the file is not empty
  if (file.peek() == std::ifstream::traits_type::eof()) {
    throw std::invalid_argument("empty " + meta + " file (" + path + ")");
  }
  std::string line;
  std::getline(file, line);  // Skip the header
  if (file.peek() == std::ifstream::traits_type::eof()) {
    throw std::invalid_argument(meta + " file contains no rows after the header (" + path + ")");
  }
  file.close();
}

void BitcoinExchange::readDatabaseIntoMemory(const std::string& databasePath) {
  std::ifstream file(databasePath);
  std::string line;

  std::getline(file, line);  // Get the csv header

  size_t pos;
  std::string date;
  std::string rateStr;
  double rate;

  pos = line.find(',');
  if (pos == std::string::npos) {
    throw std::invalid_argument("invalid database file format, missing comma in header");
  }
  if (line.find_first_of("0123456789") != std::string::npos) {
    throw std::invalid_argument("invalid database file format, header date or rate contains numeric characters");
  }

  unsigned long lineNum = 2;
  while (file.good() && std::getline(file, line)) {

#if STRICT_MODE != 1

    if (line.empty()) {
      lineNum++;
      continue;
    }

#endif

    pos = line.find(',');
    if (pos == std::string::npos) {
      throw std::invalid_argument("invalid database file format, missing comma on line " + std::to_string(lineNum));
    }
    date = line.substr(0, pos);
    if (!isValidDateString(date))
      throw std::invalid_argument("invalid database file format, invalid date on line " + std::to_string(lineNum) + " => " + date);

    try {
      rateStr = line.substr(pos + 1);
    } catch (const std::exception& e) {
      throw std::invalid_argument("invalid database file format, missing rate on line " + std::to_string(lineNum));
    }
    try {
      rate = std::stod(rateStr);
    } catch (const std::exception& e) {
      throw std::invalid_argument("invalid database file format, invalid rate on line " + std::to_string(lineNum) + " => " + rateStr);
    }

    _rates[date] = rate;
    lineNum++;
  }
  if (!file.eof()) {
    throw std::invalid_argument("corrupt database file or read interrupted: " + databasePath);
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
  if (yearStr.find_first_not_of("0123456789") != std::string::npos || monthStr.find_first_not_of("0123456789") != std::string::npos ||
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

  if (inputTime.tm_year != validTime.tm_year || inputTime.tm_mon != validTime.tm_mon || inputTime.tm_mday != validTime.tm_mday) {
    return false;
  }
  return true;
}

void BitcoinExchange::processInputFile(const std::string& inputPath) const {
  std::ifstream file(inputPath);
  std::string line;

  std::getline(file, line);  // Skip the input header

  size_t pos = line.find('|');
  if (pos == std::string::npos) {
    throw std::invalid_argument("invalid input file format, missing comma in header");
  }
  if (line.find_first_of("0123456789") != std::string::npos) {
    throw std::invalid_argument("invalid input file format, header date or value contains numeric characters");
  }

  unsigned long lineNum = 2;
  while (file.good() && std::getline(file, line)) {
    processInputLine(line, lineNum);
    lineNum++;
  }
  if (!file.eof()) {
    throw std::invalid_argument("corrupt input file or read interrupted: " + inputPath);
  }
  file.close();
}

struct IsSpace {
  bool operator()(unsigned char c) { return std::isspace(c); }
};

void BitcoinExchange::processInputLine(const std::string& line, const unsigned long lineNum) const {
  std::string cleanStr = line;
  std::string dateStr;
  std::string valueStr;

  // Remove all whitespace from the line
  cleanStr.erase(std::remove_if(cleanStr.begin(), cleanStr.end(), IsSpace()), cleanStr.end());

#if STRICT_MODE == 1

  if (cleanStr.empty()) {
    LINE_ERROR(lineNum, "empty line" + line);
  }

#else

  if (cleanStr.empty()) {
    return;
  }

#endif

  size_t pos = cleanStr.find('|');
  if (pos == std::string::npos) {
    LINE_ERROR(lineNum, "bad input => " + line);
  }
  dateStr = cleanStr.substr(0, pos);
  if (dateStr.empty()) {
    LINE_ERROR(lineNum, "missing date => " + line);
  }
  if (!isValidDateString(dateStr)) {
    LINE_ERROR(lineNum, "invalid date => " + line);
  }
  valueStr = cleanStr.substr(pos + 1);
  if (valueStr.empty()) {
    LINE_ERROR(lineNum, "missing value => " + line);
  }

#if STRICT_MODE == 1

  if (valueStr.find_first_not_of("0123456789.") != std::string::npos) {
    if (valueStr.length() == 1) {
      LINE_ERROR(lineNum, "invalid value, single non-numeric => " + line);
    }
    if (valueStr[0] != '-' && valueStr[0] != '+') {
      LINE_ERROR(lineNum, "invalid value, only + or - prefix allowed => " + line);
    }
    if (valueStr.substr(1).find_first_not_of("0123456789.") != std::string::npos) {
      LINE_ERROR(lineNum, "invalid value, non-numeric after prefix => " + line);
    }
  }
  if (valueStr.find_first_of(".") != valueStr.find_last_of(".")) {
    LINE_ERROR(lineNum, "invalid value, multiple decimal points => " + line);
  }

#endif

  double value;
  try {
    value = std::stod(valueStr);
  } catch (const std::invalid_argument& e) {
    LINE_ERROR(lineNum, "invalid value, invalid argument => " + line);
  } catch (const std::out_of_range& e) {
    LINE_ERROR(lineNum, "invalid value, out of range => " + line);
  }
  if (value < 0) {
    LINE_ERROR(lineNum, "value not positive => " + line);
  }
  if (value < 0 || value > 1000) {
    LINE_ERROR(lineNum, "value too large => " + line);
  }
  std::string closestDate = findClosestDate(dateStr);
  try {
    double rate = _rates.at(closestDate);
    double result = value * rate;  // can be inf
    LINE_MSG(dateStr, value, result);
  } catch (const std::out_of_range& e) {
    LINE_ERROR(lineNum, "bad input => " + line);
  }
}

const std::string BitcoinExchange::findClosestDate(const std::string& date) const {
  if (_rates.count(date) > 0) {
    return date;
  }
  int year = std::stoi(date.substr(0, 4));
  int month = std::stoi(date.substr(5, 2));
  int day = std::stoi(date.substr(8, 2));
  for (; year > 2008; year--) {
    for (; month > 0; month--) {
      for (; day > 0; day--) {
        std::stringstream ss;
        ss << year << "-" << std::setw(2) << std::setfill('0') << month << "-" << std::setw(2) << std::setfill('0') << day;
        std::string newDate = ss.str();
        if (_rates.count(newDate) > 0) {
          return newDate;
        }
      }
      day = 31;
    }
    month = 12;
  }
  return "invalid";
}
