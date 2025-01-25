#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
public:
  bool operator==(const Contact &otherContact) const;
  // Overloaded operator function to check for equality between Contact
  //  objects.
  // Postcondition: Returned true if toString() ==
  //  otherContact.toString().

  Contact(int cat = 0, QString first = "", QString last = "", QString add = "",
          QString zip = "", QString cty = "", QString num = "");
  // Constructor for objects of type Contact, default values set to "" or 0
  //  (for category).

  QString toString() const;
  // Function to return a QString representing the Contact object.
  // Postcondition: Returned a QString with all private member variables
  //  included.

  QString getName() const;
  // Function to return the name of the contact.
  // Postcondition: Returned firstName + lastName conactenated as a single
  //  QString.

  QString getNumber() const;
  // Function to return the phone number of the contact.
  // Postcondition: Returned phoneNumber.

  QString getAddress() const;
  // Function to return the full address of the contact.
  // Postcondition: Returned QString with all address details concatenated.

  int getCategory() const;
  // Function to return the category of the contact.
  // Postcondition: Returned category.
private:
  int m_category;
  QString m_firstName;
  QString m_lastName;
  QString m_streetAddress;
  QString m_zipCode;
  QString m_city;
  QString m_phoneNumber;
};
#endif // CONTACT_H
