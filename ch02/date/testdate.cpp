#include <iostream>

#include "date.h"

int main()
{
    Date date1, date2;

    // Set to today's date.
    date1.setToToday();

    // Check toString() member function.
    std::cout << "date1 (today) = " << date1.toString(false)
              << " or " << date1.toString(true) << std::endl;

    // Check set() function.
    date2.set(2022, 4, 29);
    std::cout << "date2 = " << date2.toString(true) << std::endl;

    // Check equals() and lessThan() functions
    std::cout << "date1.equals(date2) = " 
              << (date1.equals(date2) ? "true" : "false") << std::endl
              << "date1.lessThan(date2) = " 
              << (date1.lessThan(date2) ? "true" : "false") << std::endl;

    // Check daysBetween() and addDays() functions.
    std::cout << "date1.daysBetween(date2) = "
              << date1.daysBetween(date2) << std::endl
              << "date1.addDays(3).toString(true) = "
              << date1.addDays(3).toString(true) << std::endl;

    return EXIT_SUCCESS;
}

