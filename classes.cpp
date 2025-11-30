//this file has all code for classes and their functions (methods)
#include <string>
#include <cctype>
#include "classes.h"
using namespace std;

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


Flight::Flight(string flight_id, int number_of_rows, int number_of_seats_per_row, Route route) 
    : flight_id(flight_id), number_of_rows(number_of_rows), number_of_seats_per_row(number_of_seats_per_row), route(route)
{
    //resize_seats();
}

// void Flight::resize_seats()
// {
//     seats.resize(number_of_rows);
//     for (int i = 0; i < number_of_rows; i++)
//         seats[i].resize(number_of_seats_per_row);
// }

void Flight::addPassenger(Passenger& passenger) {
    passengers.push_back(passenger);
}

void Flight::addSeat(Seat& seat) {
    seats.push_back(seat);
}
Passenger::Passenger(string passenger_id, string f_name, string l_name, string p_number)
    : passenger_id(passenger_id), first_name(f_name), last_name(l_name), phone_number(p_number)
{}

Seat::Seat(string seat_id, string passenger_id)
    : passenger_id(passenger_id)
{   
    // TODO: improve this implementation
    // Find where the numeric part ends
    int num_end = 0;
    while (num_end < seat_id.length() && seat_id[num_end] >= '0' && seat_id[num_end] <= '9') {
        num_end++;
    }
        
    // Extract the row number
    if (num_end > 0) {
        row_number = stoi(seat_id.substr(0, num_end));
    } else {
        row_number = 0;
    }
        
    // Extract the seat character
    if (num_end < seat_id.length()) {
        seat_character = seat_id[num_end];
    } else {
        seat_character = '\0';
    }
}