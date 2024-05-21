#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <QList>
#include <QStringList>

#include "contact.h"

class ContactList
{
public:
    ContactList();
        // Default constructor function.
        // Postcondition: Empty list containing NULL pointer initialized;
        //  length = 0.

    ContactList(QList<Contact> list);
        // Constructor function with list parameter.
        // Postcondition: ContactList initialized with m_contactList set
        //  to list.

    ContactList(unsigned int length);
        // Constructor function with int parameter.
        // Postcondition: m_length set to length and m_contactList initialized
        //  and memory reserved of size m_length.

    void add(const Contact& c);
        // Function to add a contact to the contact list.
        // Postcondition: m_length++ and contact added to m_contactList.

    void remove(const Contact& c);
        // Function to remove a contact from the contact list.
        // Postcondition: Contact c removed from m_contactList and m_contactList
        //  decremented by number of occurrences of c.

    QStringList getPhoneList(int cat) const;
        // Function to return a list of names and phone numbers matching the 
        //  given category.
        // Postcondition: Returned QStringList object with all names and phone
        //  numbers matching cat separated by '\t'.

    QStringList getMailingList(int cat) const;
        // Function to return a list of names and addresses matching the given
        //  category.
        // Postcondition: Returned QStringList object with all names and addresses
        //  matching cat separated by '\t'.
    ~ContactList();
        // Destructor function.

private:
    unsigned int m_length;
    QList<Contact> m_contactList;
};
#endif // CONTACT_LIST_H

