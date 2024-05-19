#include <iostream>
#include <string>
    
std::string boolToString(bool var);

int main(int argc, char* argv[])
{
    bool value = true;

    std::cout << boolToString(value);

    return EXIT_SUCCESS;
}

std::string boolToString(bool var)
{
    return std::string(var ? "true" : "false");
}

