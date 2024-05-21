#include <iostream>

#include "hondurota.h"

int main(int argc, char* argv[])
{
    Hondurota car1;

    std::cout << "car1:\nFuel: " << car1.getFuel() << "gal\nOdometer: "
              << car1.getOdometer() << "mi\nTank Capacity: "
              << car1.getTankCapacity() << "gal\nMPG: " << car1.getMPG()
              << "mi/gal\nSpeed: " << car1.getSpeed() << "mph\n\n";

    Hondurota car2(10.1, 102830, 11.6, 37.5);

    std::cout << "car2:\nFuel: " << car2.getFuel() << "gal\nOdometer: "
              << car2.getOdometer() << "mi\nTank Capacity: "
              << car2.getTankCapacity() << "gal\nMPG: " << car2.getMPG()
              << "mi/gal\nSpeed: " << car2.getSpeed() << "mph\n\n";

    car2.drive(30, 60);

    std::cout << "After driving 60mph for 60 minutes, car2:\n"
              << "Fuel: " << car2.getFuel() << "gal\nOdometer: "
              << car2.getOdometer() << "mi\nTank Capacity: "
              << car2.getTankCapacity() << "gal\nMPG: " << car2.getMPG()
              << "mi/gal\nSpeed: " << car2.getSpeed() << "mph\n\n";
    
    car2.drive(60, 80);

    std::cout << "After driving 120mph for 80 minutes, car2:\n"
              << "Fuel: " << car2.getFuel() << "gal\nOdometer: "
              << car2.getOdometer() << "mi\nTank Capacity: "
              << car2.getTankCapacity() << "gal\nMPG: " << car2.getMPG()
              << "mi/gal\nSpeed: " << car2.getSpeed() << "mph\n\n";

    car2.addFuel(12.4);

    car2.addFuel(2.3);

    std::cout << "After adding 12.4gal of fuel, then 2.3gal car2:\n"
              << "Fuel: " << car2.getFuel() << "gal\nOdometer: "
              << car2.getOdometer() << "mi\nTank Capacity: "
              << car2.getTankCapacity() << "gal\nMPG: " << car2.getMPG()
              << "mi/gal\nSpeed: " << car2.getSpeed() << "mph\n\n";

    std::cout << "car2 took " << car2.highwayDrive(60, 60) << " minutes "
              << "to drive 60mi, and here are its statistics afterwards:\n"
              << "Fuel: " << car2.getFuel() << "gal\nOdometer: "
              << car2.getOdometer() << "mi\nTank Capacity: "
              << car2.getTankCapacity() << "gal\nMPG: " << car2.getMPG()
              << "mi/gal\nSpeed: " << car2.getSpeed() << "mph\n\n";

    std::cout << "car2 took " << car2.highwayDrive(100, 80) << " minutes "
              << "to drive 100mi, and here are its statistics afterwards:\n"
              << "Fuel: " << car2.getFuel() << "gal\nOdometer: "
              << car2.getOdometer() << "mi\nTank Capacity: "
              << car2.getTankCapacity() << "gal\nMPG: " << car2.getMPG()
              << "mi/gal\nSpeed: " << car2.getSpeed() << "mph\n\n";

    return EXIT_SUCCESS;
}

