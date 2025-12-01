// src/utils/flight_operations.cpp
#include "../../include/utils/flight_operations.h"
#include "../../include/classes/Flight.h"
#include "../../include/classes/Passenger.h"
#include "../../include/classes/Seat.h"
#include "../../include/utils/ui_utils.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
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
    
    // Create a seatMap matrix to access seats by row and column
    vector<vector<bool>> seatMap(num_rows, vector<bool>(num_cols, false));
    for (const Seat& seat : seats) {
        int seat_row = seat.get_row_number();
        char col_char = seat.get_seat_character();
        int map_row = seat_row - 1; // Convert for indexing
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

    // Get valid passenger ID
    while (true) {
        cout << "Please enter the passenger id: ";
        cin >> passenger_id;
        cleanStandardInputStream();
        
        // Check if passenger ID already exists
        const vector<Passenger>& passengers = flight.get_passengers();
        bool id_exists = false;
        for (const Passenger& passenger : passengers) {
            if (passenger.get_passenger_id() == passenger_id) {
                id_exists = true;
                break;
            }
        }
        
        if (!id_exists) break;
        cout << "\nPassenger ID already exists. Please enter a different ID.\n" << endl;
    }
    
    cout << "Please enter the passenger first name: ";
    cin >> first_name;
    cout << "Please enter the passenger last name: ";
    cin >> last_name;
    cout << "Please enter the passenger phone number: ";
    cin >> phone_number;
    
    // Get valid seat
    while (true) {
        // Get valid row number
        int max_rows = flight.get_number_of_rows();
        while (true) {
            cout << "\nPlease enter the row number (1-" << max_rows << "): ";
            cin >> row_number;
            
            if (!cin.fail() && row_number >= 1 && row_number <= max_rows) {
                cleanStandardInputStream();
                break;
            }
            
            cin.clear();
            cleanStandardInputStream();
            cout << "\nInvalid row number. Please enter a number between 1 and " << max_rows << "." << endl;
        }
        
        // Get valid seat character
        int max_seats = flight.get_number_of_seats_per_row();
        char max_seat_char = 'A' + max_seats - 1;
        while (true) {
            cout << "Please enter the seat character (A-" << max_seat_char << "): ";
            cin >> seat_character;
            cleanStandardInputStream();
            
            if (seat_character >= 'A' && seat_character <= max_seat_char) {
                break;
            }
            
            cout << "\nInvalid seat character. Please enter a letter between A and " << max_seat_char << ".\n" << endl;
        }
        
        // Check if seat is already taken
        const vector<Seat>& seats = flight.get_seats();
        bool seat_taken = false;
        for (const Seat& seat : seats) {
            if (seat.get_row_number() == row_number && seat.get_seat_character() == seat_character) {
                seat_taken = true;
                break;
            }
        }
        
        if (seat_taken) {
            cout << "\nSeat " << row_number << seat_character << " is already taken. Please choose a different seat." << endl;
            continue;  // Go back to start of outer loop to ask for new seat
        }
        
        // Seat is available, break out of outer loop
        break;
    }

    Passenger passenger = Passenger(passenger_id, first_name, last_name, phone_number);
    Seat seat = Seat(row_number, seat_character, passenger_id);
    flight.addPassenger(passenger);
    flight.addSeat(seat);
    cout << "\nPassenger " << passenger.get_first_name() << " " << passenger.get_last_name() << " added successfully to flight " << flight.get_flight_id() << "." << endl;
}

void removeExistingPassenger(Flight& flight) {
    string passenger_id;
    
    // Get valid passenger ID
    while (true) {
        cout << "Please enter the id of the passenger that needs to be removed: ";
        cin >> passenger_id;
        cleanStandardInputStream();
        
        // Check if passenger exists
        const vector<Passenger>& passengers = flight.get_passengers();
        bool passenger_exists = false;
        string passenger_name;
        for (const Passenger& passenger : passengers) {
            if (passenger.get_passenger_id() == passenger_id) {
                passenger_exists = true;
                passenger_name = passenger.get_first_name() + " " + passenger.get_last_name();
                break;
            }
        }
        
        if (!passenger_exists) {
            cout << "\nPassenger with ID \"" << passenger_id << "\" not found. Please try again.\n" << endl;
            continue;
        }
        
        // Passenger exists, remove them
        flight.removePassenger(passenger_id);
        cout << "\nPassenger " << passenger_name << " was successfully removed from flight " 
             << flight.get_flight_id() << "." << endl;
        break;
    }
}

