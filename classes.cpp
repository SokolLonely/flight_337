//this file has all code for classes and their functions (methods)
#include "classes.h"

Flight::Flight(int number_of_rows, int number_of_seats_per_row, Route* route) : 
    number_of_rows(number_of_rows), 
    number_of_seats_per_row(number_of_seats_per_row), 
    route(route) 
{}

void Flight::addPassenger(Passenger& passenger) {
    passengers.push_back(passenger);
}