#include <cassert>
#include <cstdlib>
#include <iostream>

#include "hondurota.h"

double Hondurota::addFuel(double gal) {
  assert(gal >= 0.0);

  m_speed = 0.0;

  if (m_fuel + gal <= m_tankCapacity)
    m_fuel += gal;
  else {
    std::cout << "Tank full, excess fuel remaining "
              << gal - (m_tankCapacity - m_fuel) << "gal\n";
    m_fuel = m_tankCapacity;
  }
  return m_fuel;
}

double Hondurota::getSpeed() const { return m_speed; }

Hondurota::Hondurota(double fuel, double odom, double capacity, double mpg)
    : m_fuel(fuel), m_odometer(odom), m_tankCapacity(capacity), m_mpg(mpg),
      m_speed(0.0) {
  assert(fuel >= 0.0 && odom >= 0.0 && capacity >= 0.0 && mpg >= 0.0);
}

double Hondurota::getTankCapacity() const { return m_tankCapacity; }

double Hondurota::getMPG() const { return m_mpg; }

double Hondurota::drive(double speed, int minutes) {
  if (m_fuel <= 0.0)
    std::cout << "Warning! Tank empty: unable to drive.";
  else {
    m_speed = speed;
    double distanceTravelled = speed * (static_cast<double>(speed) / 60.0);
    double fuelUsed = distanceTravelled / m_mpg;
    if (m_fuel <= fuelUsed) {
      std::cout << "Warning! Tank empty: unable to drive.";
      m_fuel = 0.0;
      distanceTravelled -= (fuelUsed - m_fuel) * m_mpg;
    } else
      m_fuel -= fuelUsed;
    m_odometer += distanceTravelled;
  }

  return m_fuel;
}

double Hondurota::getFuel() const { return m_fuel; }

double Hondurota::getOdometer() const { return m_odometer; }

double Hondurota::highwayDrive(
    double distance, double speedLimit) { // Declare variables for calculation.
  double optimalSpeed = 45.0, consumptionRate = m_mpg;
  int elapsedTime = 0;

  // Seed random number generator.
  srand(time(0));

  // Set speed to speedLimit.
  m_speed = speedLimit;

  while (m_fuel > 0.0 && distance > 0.0) {
    // Add random change from -5mph to +5mph
    m_speed += ((rand() % 10) + 1.0) - 5.0;

    // Do not allow speed to exceed speedLimit + 40mph.
    if (m_speed >= speedLimit + 40.0)
      m_speed = speedLimit + 40.0;

    // Do not allow speed to become negative.
    if (m_speed < 0.0)
      m_speed = 0.0;

    // Adjust consumption rate for each mph > optimal.
    consumptionRate *= 1.01 * (m_speed - optimalSpeed);

    // Adjust figures for one minute elapsed.
    elapsedTime++;
    distance -= m_speed / 60.0;
    m_odometer += m_speed / 60.0;
    m_fuel -= (m_speed / 60.0) / consumptionRate;
  }

  // Alert if automobile has stopped.
  if (m_fuel <= 0.0)
    std::cout << "Warning! Out of fuel.\n";

  return elapsedTime;
}
