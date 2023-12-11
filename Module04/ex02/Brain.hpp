#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
 public:
  Brain(void);
  ~Brain(void);
  Brain(const Brain& other);
  Brain& operator=(const Brain& other);
  void setIdea(unsigned int index, std::string idea);
  void printIdeas(unsigned int start_index, unsigned int end_index_incl);

 private:
  std::string ideas[100];
};

#endif