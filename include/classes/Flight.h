// include/classes/Flight.h
#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include <string>
#include "Passenger.h"
#include "Seat.h"
#include "Route.h"
using std::string;
using std::vector;

class Flight {
private:
    vector<Seat> seats;
    vector<Passenger> passengers;
    int number_of_rows;
    int number_of_seats_per_row;
    Route route;
    string flight_id;
public:
    Flight(string flight_id, int number_of_rows, int number_of_seats_per_row, Route route);
    /* REQUIRES
 *   flight_id
     number_of_rows > 0
     number_of_seats_per_row > 0
     route is a valid Route object
 *   
 * PROMISES
 *   creates a Flight object with the given flight ID, number of rows, number of seats per row, and route.
 */

    void addPassenger(Passenger& passenger);
    /*REQUIRES
 *   passenger is a valid Passenger object
    * PROMISES
    *  adds the given Passenger object to the flight's vector of passengers.
    
    */

    void addSeat(Seat& seat);
    /*REQUIRES
 *   seat  is a valid Seat object
    * PROMISES
    *  adds the given Saet object to the flight's vector of seats.
    
    */
    const vector<Seat>& get_seats() const;

    int get_number_of_rows() const;
    int get_number_of_seats_per_row() const;
    Route get_route() const;
    string get_flight_id() const;
    const vector<Passenger>& get_passengers() const;
    void removePassenger(const string& passenger_id);
    /*REQUIRES
    passenger id is a string
    PROMISES
    removed passenger and a corresponding seat
    */
};

#endif // FLIGHT_H

