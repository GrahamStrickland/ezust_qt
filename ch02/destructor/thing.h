#ifndef THING_H
#define THING_H

#include <iostream>
#include <string>

class Thing {
public:
    Thing(int n) : m_Num(n) {

    }

    ~Thing() {
        std::cout << "destructor called: "
                  << m_Num << std::endl;
    }

private:
    std::string m_String;
    int m_Num;
};
#endif // THING_H
       
