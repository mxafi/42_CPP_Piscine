#include <iostream>
#include <string>
#include <assert.h>

#include "Serializer.hpp"
#include "data.h"

static void printData(Data* data, std::string msg) {
  std::cout << "Data (" << msg << "): " << data->a << ", " << data->b << ", "
            << data->c << std::endl;
}

int main(void) {
  Data* input = new Data();
  input->a = 'x';
  input->b = 42;
  input->c = "Hello, World!";

  printData(input, "input");
  uintptr_t serialized = Serializer::serialize(input);
  Data* output = Serializer::deserialize(serialized);
  printData(output, "output");
  assert(input == output);
  assert(input->a == output->a);
  assert(input->b == output->b);
  assert(input->c == output->c);
  output->a = 'y';
  output->b = 43;
  output->c = "Goodbye, World!";
  printData(output, "modif");
  assert(output->a == 'y');
  assert(output->b == 43);
  assert(output->c == "Goodbye, World!");
  delete output;
}
