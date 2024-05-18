#include <iostream>

#include "person.h"
#include "position.h"
#include "employer.h"

Person::Person(std::string name) : m_name(name)
{
    m_employed = false;
}

std::string Person::toString() const
{
    return m_name;
}

void Person::setPosition(Employer newC, Position newP)
{
    m_employed = true;
    m_employer = &newC;
    m_position = &newP;
}

std::string Person::getPosition() const
{
    if (m_employed) return m_position->toString();
    else return "This pathetic wretch has no position!";
}

std::string Person::getEmployer() const
{
    if (m_employed) return m_employer->toString();
    else return "This virulent pond-scum has no employer!";
}

