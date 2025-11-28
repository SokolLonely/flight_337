//this file has all code for classes and their functions (methods)
using namespace std;

#include "classes.h"

void Airline::addFlight(Flight& flight){
    flights.push_back(flight);
    return;
}

Airline::Airline(){
    name.clear();
    flights.clear();
}

Airline::Airline(string name){
    set_name(name);
    flights.clear();
}

void Airline::set_name(string input_name){
    name = input_name;
}

string Airline::get_name() const{
    return name;
}


Flight::Flight(int number_of_rows, int number_of_seats_per_row, Route* route) : 
    number_of_rows(number_of_rows), 
    number_of_seats_per_row(number_of_seats_per_row), 
    route(route) 
{}

void Flight::addPassenger(Passenger& passenger) {
    passengers.push_back(passenger);
}

Passenger::Passenger(){
    first_name = "";
    last_name = "";
    phone_number = 0;
}

Passenger::Passenger(std::string f_name, std::string l_name, int p_number){
    first_name = f_name;
    last_name = l_name;
    phone_number = p_number;
}

Seat::Seat(){
    row_number = 0;
    seat_character = '\0';
    passenger_ptr = nullptr;
    occupied = false;
}

Seat::Seat(int r_number, char s_character, Passenger* p_ptr){
    row_number = r_number;
    seat_character = s_character;
    passenger_ptr = p_ptr;
    occupied = false;
}

bool Seat::get_occupied(){
    return occupied;
}