#ifndef LIBRARY_H
#define LIBRARY_H

#include "refitem.h"
#include <QList>
#include <QString>
#include <QStringList>

class Library : public QList<RefItem *> {
public:
  Library() {}
  ~Library();
  void addRefItem(RefItem *&refItem);
  int removeRefItem(QString isbn);
  bool isInList(QString isbn);
  QString toString(QString sep) const;
  QString getItemString(QString isbn);
  RefItem *findRefItem(QString isbn);

private:
  Library(const Library &);
  Library &operator=(const Library &);
};
#endif // LIBRARY_H
