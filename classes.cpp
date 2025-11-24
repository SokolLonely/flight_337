//this file has all code for classes and their functions (methods)
#include "classes.h"
using namespace std;

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
}
Seat::Seat(int r_number, char s_character, Passenger* p_ptr){
    row_number = r_number;
    seat_character = s_character;
    passenger_ptr = p_ptr;
}
