// include/classes/Airline.h
#ifndef AIRLINE_H
#define AIRLINE_H

#include <vector>
#include <string>
#include "Flight.h"
using namespace std;

class Airline {
private:
    string name;
    vector<Flight> flights;
public:
    Airline();
    Airline(string name);
    void set_name(string name);
    string get_name() const;
    vector<Flight> get_flights() const;
    Flight& get_flight(int index);
    void addFlight(Flight& flight);
};

#endif // AIRLINE_H

