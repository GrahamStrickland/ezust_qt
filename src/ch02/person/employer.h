#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <string>

class Person;
class Position;

class Employer
{
public:
    Employer(std::string name, std::string market);
    // Constructor with arguments.
    // Postcondition: m_Name set to name, m_Market set to market.

    bool hire(Person& newHire, Position& pos);
    // Function to hire a new person.
    // Postcondition: newHire.set() called with arguments
    //  representing the calling object and pos.

    std::string toString() const;
    // Function to return a string representing the employer.
    // Postcondition: Returned a string including m_Name and
    //  m_Market.
private:
    std::string m_name;
    std::string m_market;
};
#endif // EMPLOYER_H
       
