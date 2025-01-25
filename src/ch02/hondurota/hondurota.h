#ifndef HONDUROTA_H
#define HONDUROTA_H

class Hondurota {
public:
  double addFuel(double gal);
  // Function to add fuel to the automobile.
  // Precondition: m_fuel + gal <= tank capacity.
  // Postcondition: m_speed = 0.0; m_fuel incremented by gal.

  double getSpeed() const;
  // Function to return the current speed of the automobile.
  // Postcondition: Returned m_speed.

  Hondurota(double fuel = 0.0, double odom = 0.0, double capacity = 0.0,
            double mpg = 0.0);
  // Constructor function with paramters.
  // Postcondition: m_fuel = fuel; m_odometer = odom;
  //  m_tankCapacity = capacity; m_mpg = mpg; speed = 0.0.

  double getTankCapacity() const;
  // Function to return the capacity of the automobile's tank.
  // Postcondition: Returned m_tankCapacity.

  double getMPG() const;
  // Function to return the MPG (miles per gallon) representing
  //  the automobile's average fuel consumption.
  // Postcondition: Returned m_mpg.

  double drive(double speed, int minutes);
  // Function to simulate the automobile driving at speed MPH
  // for minutes minutes.
  // Precondition: m_fuel > 0.0; speed >= 0.0; minutes > 0.
  // Postcondition: m_odometer incremented; m_speed = speed;
  //  fuel decremented; returned remaining value of m_fuel.

  double getFuel() const;
  // Function to return the number of gallons of fuel left
  //  in the automobile's tank.
  // Postcondition: Returned m_fuel.

  double getOdometer() const;
  // Function to return the odometer reading of the automobile.
  // Postcondition: Returned m_odometer.

  double highwayDrive(double distance, double speedLimit);
  // Function to simulate driving on the highway, close to
  //  the given speed limit.
  // Postcondition: Returned the elapsed time for the trip.

private:
  double m_fuel;
  double m_odometer;
  double m_tankCapacity;
  double m_mpg;
  double m_speed;
};
#endif // HONDUROTA_H
