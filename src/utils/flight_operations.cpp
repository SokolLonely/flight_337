// src/utils/flight_operations.cpp
#include "../../include/utils/flight_operations.h"
#include "../../include/classes/Flight.h"
#include "../../include/classes/Passenger.h"
#include "../../include/classes/Seat.h"
#include "../../include/utils/ui_utils.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int selectFlight(const vector<Flight>& flights) {   
    cout << "Here is the list of available flights. Please select one: \n" << endl;
    
    for (int i = 0; i < flights.size(); i++) {
        cout << i + 1 << ". " << left << setw(8) << flights[i].get_flight_id() 
             << setw(10) << flights[i].get_route().get_source() 
             << setw(10) << flights[i].get_route().get_destination() 
             << setw(4) << flights[i].get_number_of_rows() 
             << flights[i].get_number_of_seats_per_row() << endl;
    }

    int selected_flight_index;
    while (true) {
        cout << "\nEnter your choice: ";
        cin >> selected_flight_index;
        
        if (!cin.fail() && selected_flight_index >= 1 && selected_flight_index <= flights.size()) {
            cleanStandardInputStream();
            break;
        }
        
        cin.clear();
        cleanStandardInputStream();
        cout << "\nInvalid choice. Please enter a number between 1 and " << flights.size() << "." << endl;
    }

    cout << "You have selected flight " << flights[selected_flight_index - 1].get_flight_id() 
         << " from " << flights[selected_flight_index - 1].get_route().get_source() 
         << " to " << flights[selected_flight_index - 1].get_route().get_destination() << "." << endl;
    return selected_flight_index - 1;
}

void displaySeatMap(Flight& flight) {
    vector<Seat> seats = flight.get_seats();
    int num_rows = flight.get_number_of_rows();
    int num_cols = flight.get_number_of_seats_per_row();
    
    // Create a 2D map to quickly find seats by row and column
    vector<vector<bool>> seatMap(num_rows, vector<bool>(num_cols, false));
    for (const Seat& seat : seats) {
        int seat_row = seat.get_row_number(); // 1-based
        char col_char = seat.get_seat_character();
        int map_row = seat_row - 1; // Convert to 0-based for vector indexing
        if (map_row >= 0 && map_row < num_rows && col_char >= 'A' && col_char < 'A' + num_cols) {
            int map_col = col_char - 'A';
            seatMap[map_row][map_col] = !seat.get_passenger_id().empty();
        }
    }
    
    cout << "Aircraft Seat Map for flight " << flight.get_flight_id() << "\n" << endl;
    
    // Print column headers
    cout << setw(3) << "";
    for (int c = 0; c < num_cols; c++) {
        cout << "  " << (char)('A' + c) << " ";
    }
    cout << endl;
    
    // Print top border
    cout << right << setw(4) << "+";
    for (int c = 0; c < num_cols; c++) {
        cout << "---+";
    }
    cout << endl;
    
    // Print seat rows
    for (int r = 0; r < num_rows; r++) {
        cout << left << setw(2) << (r + 1) << " |";
        for (int c = 0; c < num_cols; c++) {
            if (seatMap[r][c]) {
                cout << " X |";
            } else {
                cout << "   |";
            }
        }
        cout << endl;
        cout << right << setw(4) << "+";
        for (int c = 0; c < num_cols; c++) {
            cout << "---+";
        }
        cout << endl;
    }
}

void displayPassengerInfo(Flight& flight) {
    vector<Passenger> passengers = flight.get_passengers();
    vector<Seat> seats = flight.get_seats();

    cout << "Passenger List (Flight: " << flight.get_flight_id() 
         << " from " << flight.get_route().get_source() 
         << " to " << flight.get_route().get_destination() << ")\n" << endl;

    cout << left << setw(15) << "First Name" << setw(15) << "Last Name" 
         << setw(18) << "Phone" << setw(8) << "Row" << setw(8) << "Seat" 
         << setw(5) << "ID" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i = 0; i < passengers.size(); i++) {
        Passenger& passenger = passengers[i];
        Seat& seat = seats[i];
        cout << left << setw(15) << passenger.get_first_name() 
             << setw(15) << passenger.get_last_name() 
             << setw(18) << passenger.get_phone_number() 
             << setw(8) << seat.get_row_number() 
             << setw(8) << seat.get_seat_character() 
             << setw(5) << passenger.get_passenger_id() << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }
}

void addNewPassenger(Flight& flight) {
    string passenger_id, first_name, last_name, phone_number;
    int row_number;
    char seat_character;

    cout << "Please enter the passenger id: ";
    cin >> passenger_id;
    cout << "Please enter the passenger first name: ";
    cin >> first_name;
    cout << "Please enter the passenger last name: ";
    cin >> last_name;
    cout << "Please enter the passenger phone number: ";
    cin >> phone_number;
    cout << "\nPlease enter the row number: ";
    cin >> row_number;
    cout << "Please enter the seat character: ";
    cin >> seat_character;
    cleanStandardInputStream();

    Passenger passenger = Passenger(passenger_id, first_name, last_name, phone_number);
    Seat seat = Seat(row_number, seat_character, passenger_id);
    flight.addPassenger(passenger);
    flight.addSeat(seat);
}

void removeExistingPassenger(Flight& flight) {
    string passenger_id;
    cout << "Please enter the id of the passenger that needs to be removed: ";
    cin >> passenger_id;
    cleanStandardInputStream();

    string passenger_name = flight.get_passenger(passenger_id).get_first_name() + " " 
                           + flight.get_passenger(passenger_id).get_last_name();
    flight.removePassenger(passenger_id);

    cout << "\nPassenger " << passenger_name << " was successfully removed from flight " 
         << flight.get_flight_id() << "." << endl;
}

