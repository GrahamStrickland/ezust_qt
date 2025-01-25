#include <iostream>

#include "employer.h"
#include "person.h"
#include "position.h"

Employer::Employer(std::string name, std::string market)
    : m_name(name), m_market(market) {
  // Function body intentionally blank.
}

bool Employer::hire(Person &newHire, Position &pos) {
  newHire.setPosition(*this, pos);
  return true;
}

std::string Employer::toString() const { return m_name + " - " + m_market; }
