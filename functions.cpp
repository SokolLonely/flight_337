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
    cout << "\n<<< Press Return to Continue>>>>\n";
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


Flight* browseFlightList()
{
    ifstream flightFile("data/flights.txt");
    if (!flightFile) {
        cerr << "Error opening flights.txt file." << endl;
        exit(1);
    }

    cout << "Here is the list of available flights. Please select one:\n" << endl;

    // Store all lines in a vector to avoid reading file twice
    vector<string> flightLines;
    string line;
    int n = 1;
    while (getline(flightFile, line)) {
        cout << n << ". " << line << endl;
        flightLines.push_back(line);
        n++;
    }
    flightFile.close();

    int selected_n;
    cout <<"\nEnter your choice: ";
    cin >> selected_n;
    cleanStandardInputStream(); // Clear any leftover input

    // TODO: Improve error handling
    if (selected_n < 1 || selected_n > flightLines.size()) {
        cerr << "Invalid selection. Please run the program again." << endl;
        exit(1);
    }  

    // Parse the selected line
    line = flightLines[selected_n - 1]; // Convert to 0-based index
    
    int number_of_rows, number_of_seats_per_row;
    string flight_id, flight_departure, flight_destination;
    stringstream iss(line);
    iss >>  flight_id >> flight_departure >> flight_destination >> number_of_rows >> number_of_seats_per_row;

    Route* route = new Route(flight_departure, flight_destination); 
    Flight* selectedFlight = new Flight(number_of_rows, number_of_seats_per_row, route); 

    cout << "You have selected " << flight_id << " flight from " << flight_departure << " to " << flight_destination << "." << endl;
    return selectedFlight;
}

void displaySeatMap(Flight* flight) {
    vector <vector<Seat>> seats = flight->get_seats();
    int num_rows = flight->get_number_of_rows() * 2;
    int num_cols = flight->get_number_of_seats_per_row() * 2;
    
    cout << "Aircraft Seat Map for flight " << flight->get_ID() << endl;
    cout << "  ";
    for (int k = 0; k < num_cols/2; k++)
        cout << "  " << (char)65 + k << " ";

    for (int i = 0; i < num_rows; i++){
        if (i % 2 == 0)
            cout << "  +";
        else
            cout << (1 + i / 2) << " |";
        for (int j = 0; j < num_cols; j++){
            if (j % 2 == 0)
                cout << "---+";
            else{
                if (seats[i][j].get_occupied())
                    cout << " x |";
                else
                    cout << "   |";
            }
        }
        cout << endl;
    }
}

Flight browseFlightList();
void displayPassengerInformation(Flight);
void addNewPassenger(Flight);
void removeExistingPassenger(Flight);
void saveDataToFile(Flight);
