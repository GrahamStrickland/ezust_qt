#include <QTextStream>

#include "contactfactory.h"

int main(int argc, char *argv[]) {
  QTextStream cout(stdout);
  QStringList phoneList, mailingList;

  ContactList list1;
  ContactFactory cf1;
  cf1.createRandomContacts(list1, 3);

  phoneList = list1.getPhoneList(1);
  mailingList = list1.getMailingList(1);

  cout << "list1.getPhoneList(1): ";
  foreach (const QString &str, phoneList)
    cout << str << Qt::endl;
  cout << Qt::endl << "list1.getMailingList(1): ";
  foreach (const QString &str, mailingList)
    cout << str << Qt::endl;
  cout << Qt::endl;

  return EXIT_SUCCESS;
}
