#ifndef REF_ITEM_H
#define REF_ITEM_H

#include <QString>
#include <QStringList>

class RefItem {
public:
  virtual ~RefItem();
  QString getItemType() const;
  QString getISBN() const;
  QString getTitle() const;
  int getNumberOfCopies() const;
  virtual QString toString(QString sep = "[::]") const;
  void setNumberOfCopies(int newVal);

protected:
  RefItem(QString type, QString isbn, QString title, int numCopies = 1);
  RefItem(QStringList &proplist);

private:
  QString m_ItemType, m_ISBN, m_Title;
  int m_NumberOfCopies;
};

class Book : public RefItem {
public:
  Book(QString type, QString isbn, QString title, QString author, QString pub,
       int year, int numCopies = 1);
  Book(QStringList &proplist);
  QString toString(QString sep = "[::]") const;
  QString getAuthor() const;
  QString getPublisher() const;
  int getCopyRightYear() const;

private:
  QString m_Author, m_Publisher;
  int m_CopyrightYear;
};

class ReferenceBook : public Book {
public:
  enum RefCategory {
    NOREF = -1,
    Art,
    Architecture,
    ComputerScience,
    Literature,
    Math,
    Music,
    Science
  };
  ReferenceBook(QString type, QString isbn, QString title, QString author,
                QString pub, int year, RefCategory refcat, int numCopies = 1);
  ReferenceBook(QStringList &proplist);
  QString toString(QString sep = "[::]") const;
  RefCategory getCategory() const;
  QString categoryString() const;        // returns string version of m_Category
  static QStringList getRefCategories(); // returns a list of categories
private:
  RefCategory m_Category;
};

class TextBook : public Book {
public:
  enum TextCategory {
    NOTEXT = -1,
    Biology,
    Chemistry,
    Law,
    Mathematics,
    Philosophy,
    Psychology,
    Physics
  };
  TextBook(QString type, QString isbn, QString title, QString author,
           QString pub, int year, TextCategory textcat, int numCopies = 1);
  TextBook(QStringList &proplist);
  QString toString(QString sep = "[::]") const;
  TextCategory getCategory() const;
  QString categoryString() const; // returns string version of m_Category
  static QStringList getTextCategories(); // returns a list of categories
private:
  TextCategory m_Category;
};

class Dvd : public RefItem {
public:
  Dvd(QString type, QString isbn, QString title, QString creator, QString pub,
      int year, int numCopies = 1);
  Dvd(QStringList &proplist);
  virtual QString toString(QString sep = "[::]") const;
  int getCopyrightYear() const;
  QString getCreator() const;
  QString getPublisher() const;

private:
  QString m_Creator, m_Publisher;
  int m_CopyrightYear;
};

class Film : public Dvd {
public:
  enum FilmCategory { NOFILM = -1, Action, Comedy, Romance, Thriller };
  Film(QString type, QString isbn, QString title, QString creator, QString pub,
       int year, FilmCategory filmcat, int numCopies = 1);
  Film(QStringList &proplist);
  QString toString(QString sep = "[::]") const;
  FilmCategory getCategory() const;
  QString categoryString() const;
  static QStringList getFilmCategories();

private:
  FilmCategory m_Category;
};

class DataBase : public Dvd {
public:
  enum DBCategory { NODB = -1, RefBook, TextBook, Film };
  DataBase(QString type, QString isbn, QString title, QString creator,
           QString pub, int year, DBCategory dbcat, int numCopies = 1);
  DataBase(QStringList &proplist);
  QString toString(QString sep = "[::]") const;
  DBCategory getCategory() const;
  QString categoryString() const;
  static QStringList getDBCategories();

private:
  DBCategory m_Category;
};
#endif // REF_ITEM_H
