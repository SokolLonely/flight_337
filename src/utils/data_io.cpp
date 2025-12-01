// src/utils/data_io.cpp
#include "../../include/utils/data_io.h"
#include "../../include/classes/Passenger.h"
#include "../../include/classes/Seat.h"
#include "../../include/classes/Route.h"
#include "../../include/classes/Flight.h"
#include "../../include/classes/Airline.h"
#include "../../include/utils/ui_utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

Airline* createAirline(const string& airline_name) {
// PROMISES:
// Creates a new Airline instance with the provided name
// Populates Airline with Flights, Routes, Passengers and Seats information by reading data files
// Prints error messages if input files can't be opened
// Returns a pointer to the created airline instance 
    Airline* airline = new Airline(airline_name);

    // Open data files
    ifstream flightFile("data/flights.txt");
    if (!flightFile) {
        cerr << "Error opening flights.txt file." << endl;
        exit(1);
    }
    ifstream passengerFile("data/passengers.txt");
    if (!passengerFile) {
        cerr << "Error opening passengers.txt file." << endl;
        exit(1);
    }
    
    string line;
    while (getline(flightFile, line)) {
        int number_of_rows, number_of_seats_per_row;
        string flight_id, flight_departure, flight_destination;
        stringstream iss(line);
        iss >> flight_id >> flight_departure >> flight_destination >> number_of_rows >> number_of_seats_per_row;
        Route route = Route(flight_departure, flight_destination); 
        Flight flight = Flight(flight_id, number_of_rows, number_of_seats_per_row, route);
    
        // Add passengers and seats to flight
        // Reset passenger file pointer to beginning for each flight
        passengerFile.clear();
        passengerFile.seekg(0);
        while (getline(passengerFile, line)) {
            string passenger_flight_id, first_name, last_name, phone_number, seat_id, passenger_id;
            stringstream iss(line);
            iss >> passenger_flight_id >> first_name >> last_name >> phone_number >> seat_id >> passenger_id;
            Passenger passenger = Passenger(passenger_id, first_name, last_name, phone_number);
            Seat seat = Seat(seat_id, passenger_id);
            if (passenger_flight_id == flight_id) {
                flight.addPassenger(passenger);
                flight.addSeat(seat);
            }
        }
    
        airline->addFlight(flight);
    }
    flightFile.close();
    passengerFile.close();
    return airline;
}

void saveData(vector<Flight> flights) {
// PROMISES:
// Prompts user on if they would like to save the passengers data to a file
// Reprompts on invalid input
// Prints error message if output file can't be opened
// Stores all passengers information in a file "passengers.txt"
    char answer;
    while (true) {
        cout << "Do you want to save the data to \"data/passengers.txt\"? Please answer <Y or N>: ";
        cin >> answer;
        cleanStandardInputStream();
        if (answer == 'Y') break;
        else if (answer == 'N') return;
        else {
            cout << "\nInvalid answer. Please try again.\n" << endl;
        }
    }

    ofstream passengerFile("data/passengers.txt");
    if (!passengerFile) {
        cerr << "Error opening passengers.txt file." << endl;
        exit(1);
    }
    
    // Iterate through all flights and save passengers from each flight
    bool first_passenger = true;
    for (const Flight& flight : flights) {
        vector<Passenger> passengers = flight.get_passengers();
        vector<Seat> seats = flight.get_seats();
        
        for (const Passenger& passenger : passengers) {
            // Find the passenger's seat
            string seat_id = "";
            for (const Seat& seat : seats) {
                if (seat.get_passenger_id() == passenger.get_passenger_id()) {
                    seat_id = to_string(seat.get_row_number()) + seat.get_seat_character();
                    break;
                }
            }
            
            if (!first_passenger) {
                passengerFile << endl;
            }
            first_passenger = false;
            
            passengerFile << left << setw(8) << flight.get_flight_id()
                          << setw(8) << passenger.get_first_name()
                          << setw(10) << passenger.get_last_name()
                          << setw(16) << passenger.get_phone_number()
                          << setw(6) << seat_id
                          << passenger.get_passenger_id();
        }
    }
    passengerFile.close();

    cout << "\nAll the data in the passenger list were saved." << endl;
}

