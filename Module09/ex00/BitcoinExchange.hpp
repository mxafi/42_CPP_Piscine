#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
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
  void validateFilePath(const std::string& meta, const std::string& path);
};

#endif
