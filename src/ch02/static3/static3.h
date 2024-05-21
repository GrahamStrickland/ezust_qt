#ifndef STATIC_3_H
#define STATIC_3_H

#include <string>

class Client {
public:
    Client(std::string name) : m_name(name), m_id(s_savedID++) { }

    int getSavedID() {
        if (s_savedID > m_id) return s_savedID;
        else return 0;
    }

    std::string getName() { return m_name; }
    int getID() { return m_id; }

private:
    std::string m_name;
    int m_id;
    static int s_savedID;
};
#endif // STATIC_3_H

