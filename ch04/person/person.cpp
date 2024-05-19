#include <QTextStream>

#include "person.h"
#include "position.h"
#include "employer.h"

QList<Person*> Person::s_unemploymentLine;

QTextStream cout(stdout);

Person::Person(QString name) : m_name(name)
{
    m_employed = false;
    s_unemploymentLine.append(this);
    Employer noEmpl("Unemployed");
    Position noPos("Unemployed", "No job", &noEmpl);
    m_employer = &noEmpl;
    m_position = &noPos;
}

QString Person::getName() const
{
    return m_name;
}

bool Person::apply(Position* pos)
{
    bool hired = pos->getEmployer()->hire(this, pos);
    if (hired) {
        m_position = pos;
        m_employer = pos->getEmployer();
        s_unemploymentLine.removeAll(this);
        m_employed = true;
    }
    return hired;
}

Position* Person::getPosition() const
{
    if (!m_employed) 
        cout << Qt::endl << getName() << " is not currently employed.\n";
    return m_position;
}

Employer* Person::getEmployer() const
{
    if (!m_employed) 
        cout << Qt::endl << getName() << " is not currently employed.\n";
    return m_employer;
}

void Person::setPosition(Employer* empl, Position* pos)
{
    m_employed = true;
    m_employer = empl;
    m_position = pos;
    s_unemploymentLine.removeAll(this);
}

