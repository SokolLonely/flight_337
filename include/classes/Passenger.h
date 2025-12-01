// include/classes/Passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
using std::string;

class Passenger {
private:
    string passenger_id;
    string first_name;
    string last_name;
    string phone_number;
public:
    Passenger(string passenger_id, string f_name, string l_name, string p_number);
    string get_passenger_id() const;
    string get_first_name() const;
    string get_last_name() const;
    string get_phone_number() const;
};

#endif // PASSENGER_H

