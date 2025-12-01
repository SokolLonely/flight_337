#ifndef FLIGHT_OPERATIONS_H
#define FLIGHT_OPERATIONS_H

#include <vector>
#include "../classes/Flight.h"
using namespace std;

int browseFlightList(vector<Flight> flights);
void displaySeatMap(Flight& flight);
void displayPassengerInfo(Flight& flight);
void addNewPassenger(Flight& flight);
void removeExistingPassenger(Flight& flight);

#endif // FLIGHT_OPERATIONS_H

