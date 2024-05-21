#ifndef CONTACT_FACTORY_H
#define CONTACT_FACTORY_H

#include "contactlist.h"

class ContactFactory
{
public:
    ContactFactory();
        // Default ContactFactory constructor.

    void operator>>(ContactList &list);
        // Function to input a random Contact object into
        //  the given list.
        // Postcondition: randomly generated Contact object
        //  inserted into list.

    void createRandomContacts(ContactList& cl, int n=10);
        // Function to generate n random Contact objects and
        //  place them in cl.
        // Postcondition: cl filled with random Contact objects.

private:
    QString m_firstNames[3] = {"Bob", "Jim", "Dave"};
    QString m_lastNames[3] = {"Smith", "Jones", "Williams"};
    QString m_citiesFirst[4] = {"North", "East", "South", "West"};
    QString m_citiesLast[3] = {"Williamsburg", "Jonestown", "Smithfield"};
    QString m_streetNames[3] = {"Pleasant Avenue", "Main Street", "Queen\'s Street"};

    static int getRandomNumber(int min, int max);
        // Function to generate a random number in the range [min,max).
        // Postcondition: Returned a random number such that min <= 
        //  number < max.
};
#endif // CONTACT_FACTORY_H
       
