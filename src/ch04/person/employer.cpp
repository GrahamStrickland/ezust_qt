#include <cstdlib>
#include <ctime>

#include "employer.h"
#include "person.h"
#include "position.h"

Employer::Employer(QString name) : m_name(name) { srand(time(0)); }

bool Employer::hire(Person *newHire, Position *forPosition) {
  bool hired;

  if (m_openingList.contains(forPosition)) {
    hired = (rand() % 2 == 0) ? true : false;
    if (hired) {
      newHire->setPosition(this, forPosition);
      m_employeeList.append(newHire);
      return true;
    } else
      return false;
  } else
    return false;
}

QString Employer::toString() const { return m_name; }

QList<Position *> Employer::findJobs() const { return m_openingList; }

void Employer::addPosition(Position *pos) { m_openingList.append(pos); }
