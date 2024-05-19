#include "position.h"
#include "employer.h"

Position::Position(QString name, QString description, Employer* empl) :
    m_name(name), m_description(description), m_employer(empl)
{
    m_employer->addPosition(this);
}

QString Position::toString() const
{
    return QString(m_name + " - " + m_description);
}

Employer* Position::getEmployer() const
{
    return m_employer;
}

void Position::setEmployer(Employer* empl)
{
    m_employer = empl;
}

