// include/utils/flight_operations.h
#ifndef FLIGHT_OPERATIONS_H
#define FLIGHT_OPERATIONS_H

#include <vector>
#include "../classes/Flight.h"
using std::vector;

int selectFlight(const vector<Flight>& flights);
// REQUIRES:
// flights is a valid vector of Flight objects
// PROMISES:
// Displays a numbered list of flights
// Prompts the user to select a flight from the displayed list
// Reprompts the user on invalid inputs
// Displays the user's choice after they pick

void displaySeatMap(Flight& flight);
// REQUIRES:
// flight is a valid Flight object
// PROMISES:
// Displays a seat map for the selected flight indicating whether a seat is empty or occupied

void displayPassengerInfo(Flight& flight);
// REQUIRES:
// flight is a valid Flight object
// PROMISES:
// Displays info for all Passengers on the selected flight

void addNewPassenger(Flight& flight);
// REQUIRES:
// flight is a valid Flight object
// PROMISES:
// Prompts user for new passenger and seat information to be added to the selected flight
// Checks that passenger doesn't already exist through the passenger ID
// Reprompts on invalid inputs
// Inserts new Passenger and Seat instances if successful

void removeExistingPassenger(Flight& flight);
// REQUIRES:
// flight is a valid Flight object
// PROMISES:
// Prompts the user for the ID of a passenger to be removed from the selected flight
// Checks if the passenger exists
// Displays a confirmation message that the passenger was removed

#endif // FLIGHT_OPERATIONS_H

