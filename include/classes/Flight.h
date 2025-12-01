// include/classes/Flight.h
#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include <string>
#include "Passenger.h"
#include "Seat.h"
#include "Route.h"
using namespace std;

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
    void addPassenger(Passenger& passenger);
    void addSeat(Seat& seat);
    const vector<Seat>& get_seats() const;
    int get_number_of_rows() const;
    int get_number_of_seats_per_row() const;
    Route get_route() const;
    string get_flight_id() const;
    const vector<Passenger>& get_passengers() const;
    Passenger& get_passenger(const string& passenger_id);
    void removePassenger(const string& passenger_id);
};

#endif // FLIGHT_H

