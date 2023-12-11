#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain constructed. (default)" << std::endl;
}

Brain::~Brain() {
  std::cout << "Brain destructed." << std::endl;
}

Brain::Brain(const Brain& other) {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = other.ideas[i];
  }
  std::cout << "Brain constructed. (copy)" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = other.ideas[i];
  }
  std::cout << "Brain assigned." << std::endl;
  return *this;
}

void Brain::setIdea(unsigned int index, std::string idea) {
  if (index > 99)
    return;
  this->ideas[index] = idea;
}

void Brain::printIdeas(unsigned int start_index, unsigned int end_index_incl) {
  if (start_index > 99 || end_index_incl > 99)
    return;
  for (unsigned int i = start_index; i <= end_index_incl; i++) {
    std::cout << "[" << i << "]" << this->ideas[i] << std::endl;
  }
}
