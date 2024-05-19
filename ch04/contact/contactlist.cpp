#include "contactlist.h"

ContactList::ContactList()
    : m_length(0)
{
   m_contactList.reserve(m_length);
}

ContactList::ContactList(QList<Contact> list) 
    : m_length(list.size())
{
    m_contactList.reserve(m_length);
}

ContactList::ContactList(unsigned int length)
    : m_length(length)
{
    m_contactList.reserve(m_length);
}

void ContactList::add(const Contact& c)
{
    m_length++;
    m_contactList.append(c);
}

void ContactList::remove(const Contact& c)
{
    unsigned int num = m_contactList.removeAll(c);
    m_length -= num;
}

QStringList ContactList::getPhoneList(int cat) const
{
    QStringList phoneList;

    foreach (const Contact &contact, m_contactList) {
        if (contact.getCategory() == cat)
            phoneList << QString("%1\t%2")
                .arg(contact.getName())
                .arg(contact.getNumber());
    }

    return phoneList;
}

QStringList ContactList::getMailingList(int cat) const
{
    QStringList mailingList;

    foreach (const Contact &contact, m_contactList) {
        if (contact.getCategory() == cat)
            mailingList << QString("%1\t%2")
                .arg(contact.getName())
                .arg(contact.getAddress());
    }

    return mailingList;
}

ContactList::~ContactList()
{
    m_contactList.clear();
}

