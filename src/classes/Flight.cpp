// src/classes/Flight.cpp
#include "../../include/classes/Flight.h"
#include <stdexcept>
using namespace std;

Flight::Flight(string flight_id, int number_of_rows, int number_of_seats_per_row, Route route) 
    : flight_id(flight_id), number_of_rows(number_of_rows), number_of_seats_per_row(number_of_seats_per_row), route(route)
{}

void Flight::addPassenger(Passenger& passenger) {
    passengers.push_back(passenger);
}

Passenger& Flight::get_passenger(const string& passenger_id) {
    for (Passenger& passenger : passengers) {
        if (passenger.get_passenger_id() == passenger_id) {
            return passenger;
        }
    }
    throw runtime_error("Passenger with ID " + passenger_id + " not found");
}

void Flight::removePassenger(const string& passenger_id) {
    for (size_t i = 0; i < passengers.size(); i++) {
        if (passengers[i].get_passenger_id() == passenger_id) {
            passengers.erase(passengers.begin() + i);
            // Also remove the corresponding seat
            for (size_t j = 0; j < seats.size(); j++) {
                if (seats[j].get_passenger_id() == passenger_id) {
                    seats.erase(seats.begin() + j);
                    break;
                }
            }
            return;
        }
    }
}

void Flight::addSeat(Seat& seat) {
    seats.push_back(seat);
}

const vector<Seat>& Flight::get_seats() const {
    return seats;
}

int Flight::get_number_of_rows() const {
    return number_of_rows;
}

int Flight::get_number_of_seats_per_row() const {
    return number_of_seats_per_row;
}

Route Flight::get_route() const {
    return route;
}

string Flight::get_flight_id() const {
    return flight_id;
}

const vector<Passenger>& Flight::get_passengers() const {
    return passengers;
}

