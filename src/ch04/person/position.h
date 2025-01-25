#ifndef POSITION_H
#define POSITION_H

#include <QString>

class Employer;

class Position {
public:
  Position(QString name, QString desc, Employer *empl);
  // Constructor with arguments.
  // Postcondition: Object initialized with m_name set to name,
  //  and m_description set to description.

  QString toString() const;
  // Function to return a QString representing the position.
  // Postcondition: Returned a QString including m_name and m_description.

  Employer *getEmployer() const;
  // Function to return the Employer who maintains this position.
  // Postcondition: Returned m_employer.

  void setEmployer(Employer *empl);
  // Function to set the Employer who maintains this Position.
  // Postcondition: m_Employer set to empl.

private:
  QString m_name;
  QString m_description;
  Employer *m_employer;
};
#endif // POSITION_H
