#include <cstdlib>
#include <ctime>

#include "contactfactory.h"

ContactFactory::ContactFactory() { srand(time(0)); }

void ContactFactory::operator>>(ContactList &list) {
  QString first, last, add, zip, cty, num;

  // Generate random QStrings from public member arrays
  first = QString("%1").arg(m_firstNames[getRandomNumber(0, 3)]);
  last = QString("%2").arg(m_lastNames[getRandomNumber(0, 3)]);
  add = QString("%1 %2")
            .arg(getRandomNumber(0, 100))
            .arg(m_streetNames[getRandomNumber(0, 3)]);
  zip = QString("%1%2%3%4")
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10));
  cty = QString("%1 %2")
            .arg(m_citiesFirst[getRandomNumber(0, 4)])
            .arg(m_citiesLast[getRandomNumber(0, 3)]);
  num = QString("+27 %1%2 %3%4%5 %6%7%8%9")
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10))
            .arg(getRandomNumber(0, 10));

  // Create Contact with random details
  Contact random(1, first, last, add, zip, cty, num);

  // Add to list
  list.add(random);
}

void ContactFactory::createRandomContacts(ContactList &cl, int n) {
  static ContactFactory cf;
  for (int i = 0; i < n; ++i) {
    cf >> cl;
  }
}

int ContactFactory::getRandomNumber(int min, int max) {
  return (rand() % max) + min;
}
