#include <iostream>
#include <string>

void printUsage(const std::string& prog) {
  std::cerr << "usage: " << prog << " <input_file>" << std::endl;
}

int main(int ac, char** av) {
  if (ac != 2) {
    printUsage(av[0]);
    return 1;
  }
  return 0;
}
