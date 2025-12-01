// src/classes/Airline.cpp
#include "../../include/classes/Airline.h"
using namespace std;

void Airline::addFlight(Flight& flight) {
    flights.push_back(flight);
    return;
}

Airline::Airline() {
    name.clear();
    flights.clear();
}

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

vector<Flight> Airline::get_flights() const {
    return flights;
}

Flight& Airline::get_flight(int index) {
    return flights[index];
}

