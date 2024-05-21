#ifndef THING_H
#define THING_H

class Thing {
public:
    void set(int num, char c);
    void increment();
    void show();
    int getNumber() const;
    char getCharacter() const;

private:
    int m_number;
    char m_character;
};
#endif // THING_H

