#include <iostream>

#include "employer.h"
#include "person.h"
#include "position.h"

int main(int argc, char *argv[]) {
  Employer employer1("StarFleet Federation", "Intergalactic"),
      employer2("Borg", "Cyberspace");

  Person person1("Jean-Luc Picard"), person2("Wesley Crusher");

  Position position1("Captain", "Commander in Chief of the fleet"),
      position2("Worm", "Sniveling worm boy");

  person1.setPosition(employer1, position1);
  person2.setPosition(employer2, position2);

  std::cout << "person1:\n"
            << person1.toString() << std::endl
            << "Employer: " << person1.getEmployer() << std::endl
            << "Position: " << person1.getPosition() << std::endl
            << "\nperson2:\n"
            << person2.toString() << std::endl
            << "Employer: " << person2.getEmployer() << std::endl
            << "Position: " << person2.getPosition() << std::endl;

  return EXIT_SUCCESS;
}
