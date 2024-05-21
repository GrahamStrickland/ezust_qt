#include <QTextStream>

#include "thing.h"

void Thing::set(int num, char c) {
    m_number = num;
    m_character = c;
}

void Thing::increment() {
    ++m_number;
    ++m_character;
}

void Thing::show() {
    QTextStream cout(stdout);
    cout << m_number << '\t' << m_character << Qt::endl;
}

int Thing::getNumber() const
{
    return m_number;
}

char Thing::getCharacter() const
{
    return m_character;
}

