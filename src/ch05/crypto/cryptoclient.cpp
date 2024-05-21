#include <QTextStream>
#include <QString>

#include "crypto.h"

int main()
{
    QTextStream cout(stdout);
    QString str1("asdfghjkl;QWERTYUIOP{}}|123456&*()_+zxcvbnm,,, ./?"),
            str2;

    cout << "Original string: " << str1 << Qt::endl;
    cout << "length: " << str1.length() << Qt::endl;

    QString seqstr("pspsp");
    ushort key(12579);
    Crypto crypt(key, seqstr);
    str2 = crypt.encrypt(str1);
    cout << "Encrypted string: " << str2 << Qt::endl;
    cout << "Recovered string: " << crypt.decrypt(str2) << Qt::endl;

    return EXIT_SUCCESS;
}

