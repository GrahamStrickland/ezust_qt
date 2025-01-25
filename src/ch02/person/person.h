#ifndef PERSON_H
#define PERSON_H

#include <string>

class Employer;
class Position;

class Person {
public:
  Person(std::string name);
  // Constructor with one argument.
  // Postcondition: m_Name = name.

  std::string toString() const;
  // Function to return the name of the Person object.
  // Postcondition: Returned m_Name;

  void setPosition(Employer newC, Position newP);
  // Function to set employer and position.
  // Postcondition: m_position set to newP, m_employer set to newC,
  //  m_employed set to true.

  std::string getPosition() const;
  // Function to return a stringrepresenting the person's position.
  // Precondition: m_employed == true.
  // Postcondition: If m_employed == true, returned m_position.toString(),
  //  otherwise error message printed to console.

  std::string getEmployer() const;
  // Function to return a string representing the person's employer.
  // Precondition: m_employed = true.
  // Postcondition: If m_employed = true, returned m_employer.toSTring,
  //  otherwise error message printed to console.
private:
  std::string m_name;
  bool m_employed;
  Position *m_position;
  Employer *m_employer;
};
#endif // PERSON_H
