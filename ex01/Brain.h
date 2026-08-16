#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
 public:
  explicit Brain();
  Brain(const Brain& brain);
  Brain& operator=(const Brain& brain);
  ~Brain();
  static const int ideas_count = 100;
  std::string ideas[ideas_count];
};

#endif
