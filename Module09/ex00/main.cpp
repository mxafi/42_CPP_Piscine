#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

#ifndef DATABASE_FILE
#define DATABASE_FILE "data.csv"
#endif

void printUsage(const std::string& prog) {
  std::cerr << "usage: " << prog << " <input_file>" << std::endl;
}

int main(int ac, char** av) {
  if (ac != 2) {
    printUsage(av[0]);
    return 1;
  }
  try {
    BitcoinExchange exchange(DATABASE_FILE, av[1]);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
