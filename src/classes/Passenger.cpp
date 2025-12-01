// src/classes/Passenger.cpp
#include "../../include/classes/Passenger.h"
using namespace std;

Passenger::Passenger(string passenger_id, string f_name, string l_name, string p_number)
    : passenger_id(passenger_id), first_name(f_name), last_name(l_name), phone_number(p_number)
{}

string Passenger::get_passenger_id() const {
    return passenger_id;
}

string Passenger::get_first_name() const {
    return first_name;
}

string Passenger::get_last_name() const {
    return last_name;
}

string Passenger::get_phone_number() const {
    return phone_number;
}

