#include <iostream>

#include "static3.h"

int Client::s_savedID(1000);

int main(int argc, char* argv[]) {
    Client cust1("George");
    
    std::cout << cust1.getID() << std::endl;
    std::cout << cust1.getName() << std::endl;

    return EXIT_SUCCESS;
}
