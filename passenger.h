#ifndef PASSENGER_H
#define PASSENGER_H
#include "BusSystem.h"
class Passenger{
  private:
    BusSystem &system;
  public:
    Passenger(BusSystem &system);
    void Passengermenu();    
};
#endif
