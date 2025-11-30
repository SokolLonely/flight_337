#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "classes.h"
#include "functions.h"
using namespace std;

void cleanStandardInputStream (void) {
    int leftover;
    do {
        leftover = cin.get();
    } while (leftover !='\n' && leftover != EOF);
}

void clearScreen(void) {
    cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear the screen (cross-platform compatible)
}

void pressEnter() {
    cout << "\n<<< Press Return to Continue >>>" << endl;
    cin.get();
}

void displayHeader() {
    clearScreen();
    cout << "FMAS Version 1.0" << endl;
    cout << "Term Project - Flight Management Application System" << endl;
    cout << "Produced by Group#: 139" << endl;
    cout << "Names: Ryabinkin, Simon; ElSayed, Abdelrahman; Boucher, Maxime" << endl;
    pressEnter();
}

void printChoicePrompt() {
    cout<<"Please select one the following options:\n"<<endl;
    cout<<"1. Select a flight"<<endl;
    cout<<"2. Display Flight Seat Map."<<endl;
    cout<<"3. Display Passengers Information."<<endl;
    cout<<"4. Add a New Passenger."<<endl;
    cout<<"5. Remove an Existing Passenger"<<endl;
    cout<<"6. Save data"<<endl;
    cout<<"7. Quit."<<endl;
    cout<<"\nEnter your choice: (1, 2, 3, 4, 5, 6, or 7) ";
}

int menu() {
    int choice = -1;
    clearScreen();
    printChoicePrompt();
    cin >> choice;
    cleanStandardInputStream();
    return choice;
}

Airline* createAirline() {
    Airline* airline = new Airline("WestJet");

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
        iss >>  flight_id >> flight_departure >> flight_destination >> number_of_rows >> number_of_seats_per_row;
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
    
        airline -> addFlight(flight);
    }
    flightFile.close();
    passengerFile.close();
    return airline;
}

int browseFlightList(vector<Flight> flights)
{
    for (int i = 0; i < flights.size(); i++) {
        cout << i + 1 << ". " << flights[i].get_flight_id() << "  " << flights[i].get_route().get_source() << "  " << flights[i].get_route().get_destination() << "  " << flights[i].get_number_of_rows() << "  " << flights[i].get_number_of_seats_per_row() << endl;
    }
    int selected_flight_index;
    cout << "\nEnter your choice: ";
    cin >> selected_flight_index;
    // TODO: improve error handling
    cleanStandardInputStream(); // Clear any leftover input
    cout << "You have selected flight " << flights[selected_flight_index - 1].get_flight_id() << " from " << flights[selected_flight_index - 1].get_route().get_source() << " to " << flights[selected_flight_index - 1].get_route().get_destination() << "." << endl;
    return selected_flight_index - 1;
}

// void displaySeatMap(Flight* flight) {
//     vector <Seat> seats = flight -> get_seats();
//     int num_rows = flight -> get_number_of_rows() * 2;
//     int num_cols = flight -> get_number_of_seats_per_row() * 2;
    
//     cout << "Aircraft Seat Map for flight " << flight -> get_flight_id() << endl;
//     cout << "  ";
//     for (int k = 0; k < num_cols/2; k++)
//         cout << "  " << (char)65 + k << " ";

//     for (int i = 0; i < num_rows; i++){
//         if (i % 2 == 0)
//             cout << "  +";
//         else
//             cout << (1 + i / 2) << " |";
//         for (int j = 0; j < num_cols; j++){
//             if (j % 2 == 0)
//                 cout << "---+";
//             else{
//                 if (seats[i][j].get_occupied())
//                     cout << " x |";
//                 else
//                     cout << "   |";
//             }
//         }
//         cout << endl;
//     }
// }

Flight* browseFlightList();
void displayPassengerInformation(Flight);
void addNewPassenger(Flight);
void removeExistingPassenger(Flight);
void saveDataToFile(Flight);
