#include "contact.h"

bool Contact::operator==(const Contact &otherContact) const {
  return toString() == otherContact.toString();
}

Contact::Contact(int cat, QString first, QString last, QString add, QString zip,
                 QString cty, QString num)
    : m_category(cat), m_firstName(first), m_lastName(last),
      m_streetAddress(add), m_zipCode(zip), m_city(cty), m_phoneNumber(num) {
  // Function body deliberately blank.
}

QString Contact::toString() const {
  return QString(
             "Category: %1\nFirst Name: %2\nLast Name: %3\nStreet Address: %4\n"
             "Zip Code %5\nCity: %6\nPhone Number: %7\n")
      .arg(m_category)
      .arg(m_firstName)
      .arg(m_lastName)
      .arg(m_streetAddress)
      .arg(m_zipCode)
      .arg(m_city)
      .arg(m_phoneNumber);
}

QString Contact::getName() const {
  return QString("%2, %1").arg(m_firstName).arg(m_lastName);
}

QString Contact::getNumber() const { return m_phoneNumber; }

QString Contact::getAddress() const {
  return QString("%1, %2, %3").arg(m_streetAddress).arg(m_zipCode).arg(m_city);
}

int Contact::getCategory() const { return m_category; }
