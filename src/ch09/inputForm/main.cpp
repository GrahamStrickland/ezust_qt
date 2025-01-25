#include "mainwindow.h"
#include "order.h"
#include "orderform.h"
#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[]) {
  QTextStream cout(stdout);

  QApplication app(argc, argv);
  OrderForm pf;
  Order order;

  order.setName("Modern Multithreading");
  order.setDateAdded(QDateTime::currentDateTime().date());
  order.setQuantity(1);
  order.setPrice(118.50);

  pf.setOrder(&order);
  pf.show();

  int retval = app.exec();
  cout << order.toString() << endl;

  return retval;
}
