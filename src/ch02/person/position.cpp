#include "position.h"

Position::Position(std::string name, std::string description)
    : m_name(name), m_description(description) {
  // Function body intentionally blank.
}

std::string Position::toString() const {
  return m_name + " - " + m_description;
}
