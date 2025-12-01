// src/classes/Airline.cpp
#include "../../include/classes/Airline.h"
#include <stdexcept>
#include <string>
using namespace std;

Airline::Airline(string name) {
    set_name(name);
    flights.clear();
}

void Airline::set_name(string input_name) {
    name = input_name;
}

string Airline::get_name() const {
    return name;
}

const vector<Flight>& Airline::get_flights() const {
    return flights;
}

Flight& Airline::get_flight(int index) {
    if (index < 0 || index >= flights.size()) {
        throw out_of_range("Flight index " + to_string(index) + " is out of range.");
    }
    return flights[index];
}

void Airline::addFlight(Flight& flight) {
    flights.push_back(flight);
    return;
}

