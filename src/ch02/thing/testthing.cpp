#include <QTextStream>

#include "thing.h"

void display(Thing t, int n) {
  int i;
  for (i = 0; i < n; ++i)
    t.show();
}

int main(int argc, char *argv[]) {
  QTextStream cout(stdout);
  Thing t1, t2;

  t1.set(23, 'H');
  t2.set(1234, 'w');
  t1.increment();
  cout << t1.getNumber();
  display(t1, 3);
  // cout << i << Qt::endl;
  t2.show();

  return EXIT_SUCCESS;
}
