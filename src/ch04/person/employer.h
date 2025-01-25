#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QList>
#include <QString>

class Person;
class Position;

class Employer {
public:
  Employer(QString name);
  // Constructor with argument.
  // Postcondition: m_name set to name.

  bool hire(Person *newHire, Position *pos);
  // Function to hire a new person.
  // Postcondition: newHire.set() called with arguments
  //  representing the calling object and pos.

  QString toString() const;
  // Function to return a QString representing the employer.
  // Postcondition: Returned a QString including m_name and
  //  m_Market.

  QList<Position *> findJobs() const;
  // Function to return a list of available jobs from this employer.
  // Postcondition: Returned m_openingList.

  void addPosition(Position *pos);
  // Function to add a Position managed by this Employer.
  // Postcondition: pos added to m_openingList;

private:
  QString m_name;
  QList<Person *> m_employeeList;
  QList<Position *> m_openingList;
};
#endif // EMPLOYER_H
