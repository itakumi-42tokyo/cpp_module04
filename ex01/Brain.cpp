#include "Brain.h"

#include <iostream>

Brain::Brain() {
  std::cout << "Brain: default constructor called." << std::endl;
}

Brain::Brain(const Brain& brain) {
  for (int i = 0; i < ideas_count; i++) {
    ideas[i] = brain.ideas[i];
  }
  std::cout << "Brain: copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& brain) {
  for (int i = 0; i < ideas_count; i++) {
    ideas[i] = brain.ideas[i];
  }
  return *this;
}

Brain::~Brain() { std::cout << "Brain: destructor called." << std::endl; }
