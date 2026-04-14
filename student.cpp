#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char *const name, int perm)
{
  this->name = nullptr;
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const
{
  return perm;
}

const char *const Student::getName() const
{
  return name;
}

void Student::setPerm(const int permNumber)
{
  perm = permNumber;
}

void Student::setName(const char *const name)
{
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

Student::Student(const Student &orig)
{
  this->setName(orig.name);
  this->setPerm(orig.perm);
}

Student::~Student()
{
  delete[] this->name;
}

Student &Student::operator=(const Student &right)
{
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this)
    return (*this);

  // TODO... Here is where there is code missing that you need to
  delete[] this->name;
  this->setName(right.name);
  this->setPerm(right.perm);

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this);
}

std::string Student::toString() const
{
  return std::string("[") + this->getName() + "," + std::to_string(this->getPerm()) + "]";
}
