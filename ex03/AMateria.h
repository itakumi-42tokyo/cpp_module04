#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>

class ICharacter;

class AMateria {
 public:
  explicit AMateria(std::string const& type);
  AMateria(const AMateria& other);
  AMateria& operator=(const AMateria& other);
  virtual ~AMateria();
  std::string const& getType() const;  // Returns the materia type
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

 private:
  const std::string type_;
};

#endif
