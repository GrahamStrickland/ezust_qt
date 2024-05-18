#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position
{
public:
    Position(std::string name, std::string description);
    // Constructor with arguments.
    // Postcondition: Object initialized with m_Name set to name,
    //  and m_Description set to description.

    std::string toString() const;
    // Function to return a string representing the position.
    // Postcondition: Returned a string including m_Name and m_Description.
private:
    std::string m_name;
    std::string m_description;
};
#endif // POSITION_H
