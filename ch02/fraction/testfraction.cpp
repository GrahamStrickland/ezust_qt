#include <QString>
#include <QTextStream>

#include "fraction.h"

int main(int argc, char* argv[])
{
    QTextStream cout(stdout);

    Fraction f1, f2(3, 6), f3;

    f1.set(4, 5);

    f3 = f1.add(f2);

    cout << f1.toString() << " + " << f2.toString() 
         << " = " << f3.toString() << Qt::endl << Qt::endl;

    f3 = f1.subtract(f2);

    cout << f1.toString() << " - " << f2.toString() 
         << " = " << f3.toString() << Qt::endl << Qt::endl;

    f3 = f1.multiply(f2);

    cout << f1.toString() << " * " << f2.toString() 
         << " = " << f3.toString() << Qt::endl << Qt::endl;

    f3 = f1.divide(f2);

    cout << f1.toString() << " / " << f2.toString() 
         << " = " << f3.toString() << Qt::endl << Qt::endl;

    f3.set(0, 5);
    cout << "f3.set(0, 5) = " << f3.toString() << Qt::endl << Qt::endl;

    f3.set(-4, -10);
    cout << "f3.set(-4, -10) = " << f3.toString() << Qt::endl << Qt::endl;

    f3.set(10, -20);
    cout << "f3.set(10, -20) = " << f3.toString() << Qt::endl << Qt::endl;

    f3.set(-4, 15);
    cout << "f3.set(-4, 15) = " << f3.toString() << Qt::endl << Qt::endl;

    return EXIT_SUCCESS;
}

