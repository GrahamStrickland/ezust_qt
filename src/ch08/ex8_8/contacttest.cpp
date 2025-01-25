// This is a driver program to test the ADT ContactFactory and its
// associated ADT's.

#include "contactfactory.h"
#include <QTextStream>

int main() {
  QTextStream cout(stdout);
  QStringList phoneList, mailingList;

  ContactList *list1 = new ContactList();
  ContactFactory cf1;
  cf1.createRandomContacts(list1, 3);

  phoneList = list1->getPhoneList(1);
  mailingList = list1->getMailingList(1);

  cout << "list1.getPhoneList(1): ";
  foreach (const QString &str, phoneList)
    cout << str << endl;
  cout << endl << "list1.getMailingList(1): ";
  foreach (const QString &str, mailingList)
    cout << str << endl;
  cout << endl;

  return 0;
}
